#include <stdio.h>  
/*
	https://www.javatpoint.com/structure-padding-in-c
	Structure padding is a concept in C that adds the one or more empty bytes between the memory addresses to align the data in memory.

	The processor does not read 1 byte at a time. It reads 1 word at a time.


*/

/*
	Avoiding Structure Padding
	The structural padding is an in-built process that is automatically done by the compiler. 
	Sometimes it required to avoid the structure padding in C 
		as it makes the size of the structure greater than the size of the structure members.

	We can avoid the structure padding in C in two ways:
	1. Using #pragma pack(1) directive
		#pragma pack(1)  
	2. Using attribute
		__attribute__((packed)); 
*/

void StructurePadding() {

	struct student1 {
		char a;
		char b;
		int c;
	};
	// Another structure with same contents but with different order as of student1
	struct student2 {
		char a;
		int b;
		char c;
	};

	printf("Size of student1 %d\n", sizeof(struct student1));
	printf("Size of student2 %d\n", sizeof(struct student2));




}