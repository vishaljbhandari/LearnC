// gcc -Wall -Wextra -Werror -lstdc++ -lm allocate_2d.cpp
#include<iostream>
#include<stdio.h>
using namespace std;

int** allocate_new(int row, int col) {
	int **matrix = NULL;
	matrix = new int*[row];
	for (int i = 0; i < row; i++) {
		matrix[i] = new int[col];
	}
	return matrix;
}

/*

 free() vs delete:

 free() is a C library function that can also be used in C++, while “delete” is a C++ keyword.
 free() frees memory but doesn’t call Destructor of a class whereas “delete” calls the Destructor of the class and frees the memory.

 */

void free_matrix(int **matrix, int row) {
	for (int i = 0; i < row; i++) {
		free(matrix[i]);
	}
	free(matrix);
}

void delete_matrix(int **matrix, int row) {
	for (int i = 0; i < row; i++) {
		delete matrix[i];
	}
	delete matrix;
}

void read_address(int **matrix, int row, int col) {
	cout << "Your allocated matrix memories [" << row << "] [" << col << "] "
			<< endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << &matrix[i][j] << "\t";
		}
		cout << endl;
	}
}

int** allocate_malloc(int row, int col) {
	int **matrix = NULL;
	matrix = (int**) malloc(sizeof(int*) * row);
	for (int i = 0; i < row; i++) {
		matrix[i] = (int*) malloc(sizeof(int) * col);
	}
	return matrix;
}

void print_matrix(int **matrix, int row, int col) {
	cout << "Your matrix [" << row << "] [" << col << "] " << endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
}

void populate_matrix(int **matrix, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			matrix[i][j] = (i + 2) * (j + 3);
		}
	}
	cout << "Your matrix is populated" << endl;
}

void allocate_two_dimention() {
	int *p1 = new int[3];
	int *p2 = new int[3];

	int **pData = new int*[2];
	pData[0] = p1;
	pData[1] = p2;

	pData[0][1] = 2;

	delete[] p1;
	delete[] p2;

	delete[] pData;
}

int main() {
	int row = 4, col = 5, **matrix;
	matrix = allocate_new(row, col);
	if (matrix == NULL) {
		cout << "Failed to allocated memory" << endl;
		return 1;
	}
	read_address(matrix, row, col);
	populate_matrix(matrix, row, col);
	print_matrix(matrix, row, col);
	delete_matrix(matrix, row);
	cout << endl;
	row = 3;
	col = 6;
	matrix = allocate_malloc(row, col);
	if (matrix == NULL) {
		cout << "Failed to allocated memory" << endl;
		return 1;
	}

	free_matrix(matrix, row);
	allocate_two_dimention();
	return (0);
}
