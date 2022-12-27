#include <stdio.h>
#include <unistd.h>
#include <dirent.h>

void open_directory() {
	DIR *directory;
	struct dirent *file;

	/* open the directory */
	directory = opendir(".");
	if (directory == NULL) {
		puts("Unable to open current directory");
		return;
	}

	/* do something */
	file = readdir(directory);
	printf("Found the file %s\n", file->d_name);

	/* do something */
	while ((file = readdir(directory)) != NULL)
		printf("Found the file %s\n", file->d_name);

	/* close the directory */
	closedir(directory);
}

int main() {
	char path[512];

	chdir("..");
	getcwd(path, 512);
	printf("This program's parent directory is: %s\n", path);

	getcwd(path, 512);
	printf("This program is running in the %s directory\n", path);

	open_directory();

	return (0);
}
