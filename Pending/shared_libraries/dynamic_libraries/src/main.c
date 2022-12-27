#include <stdio.h>
#include "foo.h"	// header file path should relative to the include directory give as gcc parameters
			// as -Iinclude is given as parameter, therefore path should be from include directory
 
int main(void)
{
    puts("This is a shared library test...");
    foo();
    return 0;
}
