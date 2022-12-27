#include "basic.h"
#include <cstdlib>
#include <iostream>

int main (int argc, char *argv[]){
    if (argc < 2) {
        // report version
        std::cout << argv[0] << " Version " << VERSION_MAJOR << "."
                << VERSION_MINOR << std::endl;
        std::cout << "Hello basic world" << std::endl;
    }
    return 0;
}
