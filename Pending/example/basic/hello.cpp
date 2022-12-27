#include <cstdio>

void print_message(const char * s) {
    puts(s);
    fflush(stdout);
}

// argc -> argument count, number of command line arguments including filename itself
// argv -> argument values, array containing values of command line arguments inclding file name itself

int main( int argc, char ** argv ) {
    print_message("Hello, World!");
    return 0;
}
