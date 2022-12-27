// gcc storage_class_extern.c  storage_class_externfile.c

/*
 The extern Storage Class
 The extern storage class is used to give a reference of a global variable that is visible to ALL the program files.
 When you use 'extern', the variable cannot be initialized however, it points the variable name at a storage location that has been previously defined.

 When you have multiple files and you define a global variable or function, which will also be used in other files,
 then extern will be used in another file to provide the reference of defined variable or function.
 Just for understanding, extern is used to declare a global variable or function in another file.

 The extern modifier is most commonly used when there are two or more files sharing the same global variables or functions as explained below.

 */

#include <stdio.h>

int count;
extern void write_extern();

int main() {
	count = 5;
	write_extern();
	return 0;
}
