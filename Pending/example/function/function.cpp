#include <stdio.h>

// Function -> set of instructions for a specific task called whenever it is required.
// it is enclosed within curly braces { statements } called function block/body
// holds a name which is used to identify/represent/call the function block, it should be a valid identifier
// have a return type, which is used to tell called of function about result/status of the function
// have argument list, which it receives from caller function, enclosed in round braces () and separated by comma, order is significant.

/*

below is a typical function definition
<return type> function_name (args 1, args 2, ....){
	function body..
}

function call
recieveing_field = function_name(argument values ... );



*/

void arguments_two(char, int);

void f_arguments_two() {
	int x;

	for (x = 1; x < 11; x++)
		arguments_two('*', x * 2);
}

void arguments_two(char c, int count) {
	int x;

	for (x = 0; x < count; x++)
		putchar(c);
	putchar('\n');
}

void arguments_three(float a, float b, float c) {
	float p;

	p = a * b * c;
	printf("%f * %f * %f = %f\n", a, b, c, p);
}

void f_arguments_three() {
	float x = 5, y= 6, z = 7;
	arguments_three(x, y, z);
}

void arguments_one(int count) {
	int x;

	for (x = 0; x < count; x++)
		puts("Nevermore!");
}

void f_arguments_one() {
	int a, b;

	a = 1;
	b = 5;

	puts("At first the raven was like:");
	arguments_one(a);
	puts("But then he was all:");
	arguments_one(b);
}

int main() {
	f_arguments_one();
	f_arguments_two();
	f_arguments_three();
	return 0;
}
