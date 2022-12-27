#include <stdio.h>
#include "boo.h"	// directory path(include/boo.h) is not required, as this directory is already passed to gcc compilation paramters as -Iinclude
 
void foo(void) {
    puts("Hello, I am a shared library");
    #ifdef DEBUG		// DEBUG is passed thought gcc compilation parameter
       printf("Debug run\n");
    #else
       printf("Release run\n");
    #endif
    int num = NUM;
    printf("variable - %d\n", num);
}
