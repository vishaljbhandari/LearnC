#include <ctime>
#include <errno.h>
#include <fstream>
#include <linux/magic.h>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sys/mount.h>
#include <sys/vfs.h>
#include <bits/stdc++.h>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mount.h>
#include <linux/loop.h>
#include <fcntl.h>
#include <linux/loop.h>
#include <fcntl.h>
#include <linux/loop.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

#define LOOP_CTL_GET_FREE       0x4C82

#define errExit(msg)    do { perror(msg); exit(EXIT_FAILURE); \
                               } while (0)

bool FileExists(const std::string &name) {

	struct stat buffer;

	return (stat(name.c_str(), &buffer) == 0);

}

static const struct {

	unsigned long magic;

	const char *type;

} types[] = {

{ EXT4_SUPER_MAGIC, "ext4" },

{ TMPFS_MAGIC, "tmpfs" }

};

const char* get_type(unsigned long magic) {

	static const char *unknown = "unknown";

	unsigned int index;

	for (index = 0; index < sizeof(types) / sizeof(types[0]); index++)

		if (types[index].magic == magic)

			return types[index].type;

	return unknown;

}

int backup() {

	struct statfs buf;

	statfs("/boot", &buf);

	printf("/boot is %s\n", get_type((unsigned long) buf.f_type));

	statfs("/tmp", &buf);

	printf("/tmp is %s\n", get_type((unsigned long) buf.f_type));

	return 0;

}

int restore() {

	return 0;

}

int browse(const string &mount_point) {

	return 0;

}

int mount_file(const string &backup_stub_filename) {

	return 0;

}

int main(int argc, char **argv) {

	if (argc != 4) {

		cout << "Invalid Argument Count\nUsage: " << argv[0]
				<< " -file <filename> <device_name>" << endl;

		return 1;

	}

	cout << "1: " << argv[1] << ", 2: " << argv[2] << ", 3: " << argv[3]
			<< endl;

	string backup_stub_filename;

	string device_name;

	if (string(argv[1]) == string("-file")) {

		backup_stub_filename = string(argv[2]);

		if (!FileExists(backup_stub_filename)) {

			return 3;

		}

		device_name = string(argv[3]);

	} else {

		return 2;

	}

	time_t unique_timestamp = time(0);

	std::stringstream string_stream;

	string_stream << unique_timestamp;

	string target_mount_directory = string("/mnt/") + backup_stub_filename
			+ string_stream.str();

	const unsigned long mntflags = 0;

	const char *opts = "mode=0700,uid=65534"; /* 65534 is the uid of nobody */

	cout << "target:" << target_mount_directory.c_str() << ", file:"
			<< backup_stub_filename.c_str() << endl;

	/*

	 string *free_device = std::system("losetup -f");

	 std::string prefix = "/dev/loop";

	 std::string argument = free_device;

	 char device_character = argument.at(argument.length());

	 int device_number = device_character - 48;

	 if(argument.substr(0, prefix.length()) == prefix && argument.length() == prefix.length() + 1 && (device_number >= 0 $$ device_number <= 9) )) {

	 device_name = free_device;

	 }



	 if(device_name == "none"){

	 cout<<"Failed to find free device"<<endl;

	 return 4;

	 }

	 */

	/*

	 int file_fd, device_fd;



	 file_fd = open(backup_stub_filename.c_str(), O_RDONLY);

	 if (file_fd < -1) {

	 perror("open backing file failed");

	 return 11;

	 }

	 device_fd = open(device_name.c_str(), O_RDONLY);

	 if (device_fd < -1) {

	 perror("open loop device failed");

	 close(file_fd);

	 return 12;

	 }

	 if (ioctl(device_fd, LOOP_SET_FD, file_fd) < 0) {

	 perror("ioctl LOOP_SET_FD failed");

	 cerr << "Error: " << strerror(errno) << endl;

	 close(file_fd);

	 close(device_fd);

	 return 13;

	 }else{

	 cerr << "Error: " << strerror(errno) << endl;

	 }

	 */

	int loopctlfd, loopfd, backingfile;

	long devnr;

	char loopname[4096];

	loopctlfd = open("/dev/loop-control", O_RDWR);

	if (loopctlfd == -1) {

		errExit("open: /dev/loop-control");

	}

	devnr = ioctl(loopctlfd, LOOP_CTL_GET_FREE);

	if (devnr == -1) {

		errExit("ioctl-LOOP_CTL_GET_FREE");

	}

	sprintf(loopname, "/dev/loop%ld\n", devnr);

	printf("loopname = %s\n", loopname);

	loopfd = open(loopname, O_RDWR);

	if (loopfd == -1) {

		errExit("open: loopname");

	}

	backingfile = open(backup_stub_filename.c_str(), O_RDWR);

	if (backingfile == -1) {

		close(loopfd);

		errExit("open: backing-file");

	}

	if (ioctl(loopfd, LOOP_SET_FD, backingfile) == -1) {

		close(backingfile);

		close(loopfd);

		errExit("ioctl-LOOP_SET_FD");

	}

	if (mkdir(target_mount_directory.c_str(), 0777) == -1) {

		cerr << "Error while creating directory(" << target_mount_directory
				<< "):  " << strerror(errno) << endl;

	} else {

		cout << "Directory created " << target_mount_directory << endl;

	}

	//int result = mount(device_name.c_str(), target_mount_directory.c_str(), backup_stub_filename.c_str(),MS_RDONLY,NULL);

	int result = mount(loopname, target_mount_directory.c_str(),
			backup_stub_filename.c_str(), MS_RDONLY, NULL);

	close(backingfile);

	close(loopfd);

	if (result == 0) {

		printf("Mount created at %s...\n", target_mount_directory.c_str());

		printf("Press <return> to unmount the volume: ");

		//getchar();

		//umount(target_mount_directory.c_str());

	} else {

		printf("Error : Failed to mount %s\nReason: %s [%d][%d]\n",
				device_name.c_str(), strerror(errno), errno, result);

		if (rmdir(target_mount_directory.c_str()) == -1) {

			cerr << "Error: " << strerror(errno) << endl;

		} else {

			cout << "Directory " << target_mount_directory.c_str() << " deleted"
					<< endl;

		}

		return -1;

	}

	return 0;

}
