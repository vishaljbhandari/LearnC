#include <stdio.h>

#define     ROWS     4
#define     COLS     3

void array_int_2d() {
	int grid[3][3];
	int x, row, col;
	int value[ROWS][COLS];

	/* initialize the array */
	for (row = 0; row < 3; row++) {
		for (col = 0; col < 3; col++)
			grid[row][col] = 0;
	}

	grid[2][2] = 1;
	for (x = 0; x < 5; x++) {
		grid[x][0] = x + 1;
		grid[x][1] = grid[x][0] * 10;
	}

	/* display the grid */
	for (row = 0; row < 3; row++) {
		for (col = 0; col < 3; col++) {
			printf("%d ", grid[row][col]);
		}
		putchar('\n');
	}
	putchar('\n');

	/* initialize the array */
	for (row = 0; row < ROWS; row++) {
		for (col = 0; col < COLS; col++)
			value[row][col] = 0;
	}
	/* display the grid */
	for (row = 0; row < ROWS; row++) {
		for (col = 0; col < COLS; col++) {
			printf("%d ", value[row][col]);
		}
		putchar('\n');
	}
	putchar('\n');
}

void array_int_3d() {
	char tictactoe[3][3][3];
	int x, y, z;

	/* initialize */
	for (x = 0; x < 3; x++)
		for (y = 0; y < 3; y++)
			for (z = 0; z < 3; z++)
				tictactoe[x][y][z] = '.';

	/* display */
	puts("Tic Tac Toe");
	for (x = 0; x < 3; x++) {
		printf("%*c", x + 1, ' ');
		for (y = 0; y < 3; y++) {
			for (z = 0; z < 3; z++)
				printf(" %c ", tictactoe[x][y][z]);
			printf("     "); /* 5 spaces */
		}
		putchar('\n');
	}
	putchar('\n');
}

void array_char_2d() {
	char *months[12] = { "January", "February", "March", "April", "May", "June",
			"July", "August", "September", "October", "November", "December" };
	int x;
	for (x = 0; x < 12; x++)
		printf("%s\n", months[x]);
	putchar('\n');

	char *presidents[4] = { "Washington", "Adams", "Jefferson", "Madison" };
	char *ptr;
	for (x = 0; x < 4; x++) {
		ptr = presidents[x];
		while (*ptr != '\0') {
			putchar(*ptr);
			ptr++;
		}
		putchar('\n');
	}
	putchar('\n');
	char names[4][5] = { "Ant", "Bee", "Cat", "Duck" };
	for (x = 0; x < 4; x++) {
		printf("%s\n", names[x]);
	}
	putchar('\n');
}

int main() {
	array_int_2d();
	array_int_3d();
	array_char_2d();
	return 0;
}
