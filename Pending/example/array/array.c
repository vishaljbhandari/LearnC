#include <stdio.h>
#include <time.h>
#include <stdlib.h>
// gcc array.c
void n_values() {
	float temp1, temp2, temp3, temp4;

	temp1 = 74.9;
	temp2 = 73.7;
	temp3 = 75.8;
	temp4 = 78.2;

	printf("Local temperatures:\n");
	printf("Station 1: %.1f\n", temp1);
	printf("Station 2: %.1f\n", temp2);
	printf("Station 3: %.1f\n", temp3);
	printf("Station 4: %.1f\n", temp4);
}

void an_array() {
	// Size empty/blank
	float temps0[] = { 74.9, 73.7, 75.8, 78.2 };
	int x;

	printf("Local temperatures:\n");
	for (x = 0; x < 4; x++)
		printf("Station %d: %.1f\n", x, temps0[x]);

	// Size as integer value
	float temps1[4] = { 74.9, 73.7, 75.8, 78.2 };

	printf("Local temperatures:\n");
	for (x = 0; x < 4; x++)
		printf("Station %d: %.1f\n", x, temps1[x]);

	// Size as integer variable
	int arr_size = 4;
	// error: variable-sized object may not be initialized
	// float temps2[arr_size] = { 74.9, 73.7, 75.8, 78.2 };

	// Size as integer constant variable
	const int carr_size = 4;
	// error: variable-sized object may not be initialized
	// float temps3[carr_size] = { 74.9, 73.7, 75.8, 78.2 };

	float highscore[5];

	highscore[0] = 993.86;
	highscore[1] = 682.01;
	highscore[2] = 639.60;
	highscore[3] = 310.45;
	highscore[4] = 123.25;

	puts("Here are the high scores:");
	printf("#1 %.2f\n", highscore[0]);
	printf("#2 %.2f\n", highscore[1]);
	printf("#3 %.2f\n", highscore[2]);
	printf("#4 %.2f\n", highscore[3]);
	printf("#5 %.2f\n", highscore[4]);

	puts("Here are the high scores:");
	for (x = 0; x < 5; x++)
		printf("#%d %.2f\n", x + 1, highscore[x]);

	// bellow is error, it is not initialization
	// highscore[5] = {993.86, 682.01, 639.60, 310.45, 123.25};
	// it must be with declaration and initialization
	// float highscore[5] = {993.86, 682.01, 639.60, 310.45, 123.25};   is correct
}

#define MEALS 3
void array_size_macro() {
	int x, total = 0, calories[MEALS];
	puts("Calorie Counter");
	for (x = 0; x < MEALS; x++) {
		printf("Calories at meal %d: ", x + 1);
		scanf("%d", &calories[x]);
		total = total + calories[x];
	}
	printf("You had a total of %d calories.\n", total);
}

void array_elements() {
	int numbers[] = { 45, 50, 88, 100, 213 };
	int temp, x;

	puts("Before:");
	for (x = 0; x < 5; x++)
		printf("%d\n", numbers[x]);

	temp = numbers[3];
	numbers[3] = numbers[2];
	numbers[2] = temp;

	puts("After:");
	for (x = 0; x < 5; x++)
		printf("%d\n", numbers[x]);
}

void array_copy() {
	int duplicate[5], x, original[5] = { 45, 50, 88, 100, 213 };

	for (x = 0; x < 5; x++)
		duplicate[x] = original[x];

	puts("Array values:");
	for (x = 0; x < 5; x++)
		printf("Element#%d %3d == %3d\n", x, original[x], duplicate[x]);
}

int* makearray(void) {
	int x;
	int array1[5];		// Local array variable
	static int array2[5];
	for (x = 0; x < 5; x++) {
		array1[x] = (x * 5) % 10 + 1;
		array2[x] = (x * 5) % 10 + 1;
		printf("array2[%d] : %d at %ul\n", x, array2[x], &array2[x]);
	}
	// return (array1);	// Local array can not be returned
	return array2;
}

void return_array_from_function() {
	int x;
	int array[5];
	int *atr;
	srand((unsigned) time(NULL));
	puts("Here are your 5 random numbers:");
	// array = makearray();	// wrong assignment
	atr = makearray();
	for (x = 0; x < 5; x++) {
		printf("atr[%d] : %d at %ul\n", x, atr[x], &atr[x]);
	}
}

int as_array_name_plus_index_with_input() {
	float highscore[5];
	int x;

	for (x = 0; x < 5; x++) {
		printf("High score #%d: ", x + 1);
		scanf("%f", &highscore[x]);
	}

	puts("Here are the high scores:");
	for (x = 0; x < 5; x++)
		printf("#%d %.2f\n", x + 1, highscore[x]);
}

int main() {
	n_values();
	an_array();
	array_size_macro();
	array_copy();
	array_elements();
	return_array_from_function();
	as_array_name_plus_index_with_input();
	return 0;
}
