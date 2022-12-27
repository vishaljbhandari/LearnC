#include <stdio.h>


/*



In C:

    void foo() means "a function foo taking an unspecified number of arguments of unspecified type"
    void foo(void) means "a function foo taking no arguments"

In C++:

    void foo() means "a function foo taking no arguments"
    void foo(void) means "a function foo taking no arguments"

By writing foo(void), therefore, we achieve the same interpretation across both languages and make our headers multilingual (though we usually need to do some more things to the headers to make them truly cross-language; namely, wrap them in an extern "C" if we're compiling C++).




*/


int main() {

	return 0;
}
