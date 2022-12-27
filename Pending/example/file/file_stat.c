#include <stdio.h>
#include <time.h>
#include <dirent.h>
#include <sys/stat.h>

int main() {

	const char filename[] = "alpha.txt";
	struct stat fstat;

	stat(filename, &fstat);
	printf("%s is %ld bytes long\n", filename, fstat.st_size);
	printf("It was modified on %s", ctime(&fstat.st_mtime));

	DIR *directory;
	struct dirent *file;

	/* open the directory */
	directory = opendir(".");
	if (directory == NULL) {
		puts("Unable to open current directory");
		return (1);
	}

	/* do something */
	printf("%-25s %-10s %s\n", "Filename", "Size", "Timestamp");
	while ((file = readdir(directory)) != NULL) {
		stat(file->d_name, &fstat);
		printf("%25s %10lld ", file->d_name, fstat.st_size);
		printf("%s", ctime(&fstat.st_mtime));
	}

	/* do something */
	printf("%-5s %-20s %-10s %s\n", "Type", "Filename", "Size", "Timestamp");
	while ((file = readdir(directory)) != NULL) {
		stat(file->d_name, &fstat);
		if (S_ISDIR(fstat.st_mode))
			printf(" Dir ");
		else
			printf("File ");
		printf("%20s %10lld %ld\n", file->d_name, fstat.st_size,
				fstat.st_mtime);
	}

	/* close the directory */
	closedir(directory);

	return (0);
}

