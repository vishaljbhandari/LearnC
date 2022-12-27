#include<stdio.h>

int first[5][5], second[5][5], third[5][5];
int row1, col1, row2, col2, row3, col3;

int matrixmultiplication() {
	int li, lj, lk, ch = 1;

	printf("\nFirst Matrix => Rows : %d Columns : %d\n", row1, col1);
	printf("\nSecond Matrix => Rows : %d Columns : %d\n", row2, col2);
	if ((col1 != row2) || row1 == 0 || col1 == 0) {
		row3 = col3 = 0;
		printf("\aGiven Matrices Do Not Meet Multiplication Requirements..\n");
		printf("Multiplication Failed..\nPress AnyKey To Return... ");

		return (0);
	}
	printf("\nColumns Of First Matrix = Rows Of Second Matrix\n");
	printf("Given Matrices are Favourable For Multiplication..\n");
	row3 = row1;
	col3 = col2;
	for (li = 0; li < row3; li++)
		for (lj = 0; lj < col3; lj++)
			for (lk = 0, third[li][lj] = 0; lk < row2; lk++)
				third[li][lj] += first[li][lk] * second[lk][lj];
	printf("\nSuccesfuly Multiplied....\a");
	printf("\nView Results... ?? Press 1 To Yes.");
	scanf("%d", &ch);
	if (ch != 1)
		return (1);
	puts("\a");

	printf("First Matrix[A] => Rows : %d Columns : %d\n", row1, col1);
	for (li = 0; li < row1; puts("\t\t"), li++)
		for (lj = 0; lj < col1; lj++)
			printf("\t%d", first[li][lj]);
	printf("\a\n\nSecond Matrix[B] => Rows : %d Columns : %d\n", row2, col2);
	for (li = 0; li < row2; puts("\t\t"), li++)
		for (lj = 0; lj < col2; lj++)
			printf("\t%d", second[li][lj]);
	printf("\a\n\nResulted Matrix[A*B] => Rows : %d Columns : %d\n", row2,
			col2);
	for (li = 0; li < row3; puts("\t\t"), li++)
		for (lj = 0; lj < col3; lj++)
			printf("\t%d", third[li][lj]);
	printf("\a\n\nPress Any Key For Main Menu..");

	return (1);
}

int matrixaddition() {
	int li, lj, ch = 1;

	printf("\nFirst Matrix => Rows : %d Columns : %d\n", row1, col1);
	printf("\nSecond Matrix => Rows : %d Columns : %d\n", row2, col2);
	if (row1 != row2 || col1 != col2 || row1 == 0 || col1 == 0) {
		row3 = col3 = 0;
		printf("\aGiven Matrices Do Not Meet Addition Requirements..\n");
		printf("Addition Failed..\n");
		printf("Press Any Key To Return In Main Menu... ");

		return (0);
	}
	printf("\nFor Both Matrices \tRows : Equal...\n");
	printf("\t\t\tColumns : Equal....\n");
	printf("Given Matrices are Favourable For Addition..\n");
	row3 = row1;
	col3 = col1;
	for (li = 0; li < row3; li++)
		for (lj = 0, third[li][lj] = 0; lj < col3; lj++)
			third[li][lj] = first[li][lj] + second[li][lj];
	printf("\nSuccesfuly Added....");
	printf("\a\nView Results... ?? Press 1 To Yes.");
	scanf("%d", &ch);
	if (ch != 1)
		return (1);
	puts("\a");

	printf("First Matrix[A] => Rows : %d Columns : %d\n", row1, col1);
	for (li = 0; li < row1; puts("\t\t"), li++)
		for (lj = 0; lj < col1; lj++)
			printf("\t%d", first[li][lj]);
	printf("\a\n\nSecond Matrix[B] => Rows : %d Columns : %d\n", row2, col2);
	for (li = 0; li < row2; puts("\t\t"), li++)
		for (lj = 0; lj < col2; lj++)
			printf("\t%d", second[li][lj]);
	printf("\a\n\nResulted Matrix[A+B] => Rows : %d Columns : %d\n", row2,
			col2);
	for (li = 0; li < row3; puts("\t\t"), li++)
		for (lj = 0; lj < col3; lj++)
			printf("\t%d", third[li][lj]);
	printf("\a\n\nPress Any Key For Main Menu..");

	return (1);
}

int matrixsubtraction() {
	int li, lj, ch = 1;

	printf("\nFirst Matrix => Rows : %d Columns : %d\n", row1, col1);
	printf("\nSecond Matrix => Rows : %d Columns : %d\n", row2, col2);
	if (row1 != row2 || col1 != col2 || row1 == 0 || col1 == 0) {
		row3 = col3 = 0;
		printf("\aGiven Matrices Do Not Meet Subtraction Requirements..\n");
		printf("Addition Failed..\n");
		printf("Press Any Key To Return In Main Menu... ");

		return (0);
	}
	printf("\nFor Both Matrices \tRows : Equal...\n");
	printf("\t\t\tColumns : Equal....\n");
	printf("Given Matrices are Favourable For Subtraction..\n");
	row3 = row1;
	col3 = col1;
	for (li = 0; li < row3; li++)
		for (lj = 0, third[li][lj] = 0; lj < col3; lj++)
			third[li][lj] = first[li][lj] - second[li][lj];
	printf("\nSuccesfuly subtracted....");
	printf("\a\nView Results... ?? Press 1 To Yes.");
	scanf("%d", &ch);
	if (ch != 1)
		return (1);

	printf("\aFirst Matrix[A] => Rows : %d Columns : %d\n", row1, col1);
	for (li = 0; li < row1; puts("\t\t"), li++)
		for (lj = 0; lj < col1; lj++)
			printf("\t%d", first[li][lj]);
	printf("\a\n\nSecond Matrix[B] => Rows : %d Columns : %d\n", row2, col2);
	for (li = 0; li < row2; puts("\t\t"), li++)
		for (lj = 0; lj < col2; lj++)
			printf("\t%d", second[li][lj]);
	printf("\a\n\nResulted Matrix[A-B] => Rows : %d Columns : %d\n", row2,
			col2);
	for (li = 0; li < row3; puts("\t\t"), li++)
		for (lj = 0; lj < col3; lj++)
			printf("\t%d", third[li][lj]);
	printf("\a\n\nPress Any Key For Main Menu..");

	return (1);
}

void viewmatrices() {
	int li, lj;

	printf("\a\nFirst Matrix => Rows : %d Columns : %d\n\n", row1, col1);
	for (li = 0; li < row1; puts("\t\t"), li++)
		for (lj = 0; lj < col1; lj++)
			printf("\t%d", first[li][lj]);
	printf("\a\n\nSecond Matrix => Rows : %d Columns : %d\n\n", row2, col2);
	for (li = 0; li < row2; puts("\t\t"), li++)
		for (lj = 0; lj < col2; lj++)
			printf("\t%d", second[li][lj]);
	printf("\a\n\nPress Any Key For Main Menu..");

}

void viewresultmatrix() {
	int li, lj;

	printf("\a\nMatrix => Rows : %d Columns : %d\n\n", row3, col3);
	for (li = 0; li < row3; puts("\t\t"), li++)
		for (lj = 0; lj < col3; lj++)
			printf("\t%d", third[li][lj]);
	printf("\a\n\nPress Any Key For Main Menu..");

}

// Function definition of input
int inputmatrix() {
	int ch1, li, lj, ch2;

	printf("1 For First Matrix\n2 For Second Matrix\n");
	printf("3 For Both Matrices\n4 To Quit\nYour Choice : \a");
	scanf("%d", &ch1);
	switch (ch1) {
	case 3:
	case 1:
		printf("\nFirst Matrix\nEnter Row[Limit 5] : ");
		scanf("%d", &row1);
		if (row1 > 5) {
			row1 = col1 = 0;
			return 0;
		}
		printf("Enter Column[Limit 5] : ");
		scanf("%d", &col1);
		if (col1 > 5) {
			row1 = col1 = 0;
			return 0;
		}
		for (li = 0; li < row1; li++)
			for (lj = 0; lj < col1; lj++) {
				printf("Value For[%d][%d] = ", li + 1, lj + 1);
				scanf("%d", &first[li][lj]);
			}
		printf("\nFirst Input Completed\a");
		if (ch1 == 1)
			break;
	case 2:
		li = lj = 0;
		printf("\nSecond Matrix\nEnter Row : ");
		scanf("%d", &row2);
		if (row2 > 5) {
			row2 = col2 = 0;
			return 0;
		}
		printf("Enter Column : ");
		scanf("%d", &col2);
		if (col2 > 5) {
			row2 = col2 = 0;
			return 0;
		}
		for (li = 0; li < row2; li++)
			for (lj = 0; lj < col2; lj++) {
				printf("Value For[%d][%d] = ", li + 1, lj + 1);
				scanf("%d", &second[li][lj]);
			}
		printf("\nSecond Input Completed\a");
		break;
	default:
		printf("\nInvalid Entry\a");
		return (0);
	}

	puts("\a");
	printf("Press 1 To View Matrices : ");
	scanf("%d", &ch2);
	if (ch2 == 1)
		viewmatrices();
	return (1);
}

int clearmatrix() {
	int ch1, li, lj;

	printf("1 For First Matrix\n2 For Second Matrix\n");
	printf("3 For Result Matrix\n4 To Clear All\n5 To Quit\nYour Choice : ");
	scanf("%d", &ch1);
	switch (ch1) {
	case 4:
	case 1:
		for (li = 0; li < row1; li++)
			for (lj = 0; lj < col1; first[li][lj] = 0, lj++)
				;
		row1 = col1 = 0;
		printf("\n\nFirst Matrix Cleared....");
		if (ch1 == 1)
			return (1);
	case 2:
		for (li = 0; li < row2; li++)
			for (lj = 0; lj < col2; second[li][lj] = 0, lj++)
				;
		row2 = col2 = 0;
		printf("\n\nSecond Matrix Cleared....");
		if (ch1 == 2)
			return (1);
	case 3:
		for (li = 0; li < row3; li++)
			for (lj = 0; lj < col3; third[li][lj] = 0, lj++)
				;
		row3 = col3 = 0;
		printf("\n\nThird Matrix Cleared....");
		return (1);
	default:
		printf("\nInvalid Entry....");
	}
	return (0);
}

int main() {
	int i, j, k;  //Integer Variable Declaration
	int ch;
	// ch = switch control variable
	// j = confirmation variable
	while (1) //Infinite Loop For Continuity
	{
		//Clear Display
		//Print Guide-line
		printf("Enter Your Choice According To Following.\n");
		printf("1 For Input Matrices.\n2 For Clear Matrices.\n");
		printf("3 To View Matrices.\n4 For Matrix Addition.\n");
		printf("5 For Matrix Subtraction.\n6 For Matrix Multiplcation.\n");
		printf("7 To Show Result Matrix.\n8 To Quit.\nYour Choice : ");
		//Input choice
		puts("\a");
		scanf("%d", &ch);
		j = 0; //Clearing Variables
		//Switching Choices
		switch (ch) {
		case 1:
			j = inputmatrix();

			if (j == 0)
				printf("\n\nInput Failed");
			break;
		case 2:
			j = clearmatrix();

			if (j == 0)
				printf("\n\nclear Failed");
			break;
		case 3:
			viewmatrices();
			break;
		case 4:
			j = matrixaddition();

			if (j == 0)
				printf("\n\nAddition Failed");
			break;
		case 5:
			j = matrixsubtraction();

			if (j == 0)
				printf("\n\nSubtraction Failed");
			break;
		case 6:
			j = matrixmultiplication();

			if (j == 0)
				printf("\n\nMultiplication Failed");
			break;
		case 7:
			viewresultmatrix();
			break;
		case 8:

			printf("\nThanks...\nQuiting...\nPress any key..\n");

			return 0;
		}

	}
}
