#include <cstdio>

int main(int argc, char* argv[]){
#ifdef __GLIBCPP__
    std::printf("GLIBCPP: %d\n",__GLIBCPP__);
#endif
#ifdef __GLIBCXX__
    std::printf("GLIBCXX: %d\n",__GLIBCXX__);
#endif
   return 0;
}

/*

g++ libdatestamp.cxx -o libdatestamp

./libdatestamp
GLIBCXX: 20101208

*/
