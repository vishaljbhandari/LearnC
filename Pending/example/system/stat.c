#include <stdio.h>
#include <time.h>
#include <sys/stat.h>

int main(int argc, char **argv) {
	const char *fname = "stat.c";
	struct stat fstat;

	if (stat(fname, &fstat) == 0) {
		fprintf(stdout, "Name: %s, UID: %u, GID: %u, Size: %llu\n", fname,
				fstat.st_uid, fstat.st_gid, fstat.st_size);

		// file modification time is in seconds since midnite 1970-01-01 UTC
		const static int bufSize = 128;
		char buf[bufSize];
		// struct tm mtime = *gmtime(&fstat.st_mtimespec.tv_sec);
		struct tm mtime = *gmtime(&fstat.st_mtime);
		strftime(buf, bufSize, "%Y-%m-%d %H:%M:%S %Z", &mtime);
		printf("Last modified: %s\n", buf);

	} else {
		perror("Couldn't stat file");
	}
	return 0;
}
