gcc -c -fPIC first.c -o first.o
gcc -c -fPIC second.c -o second.o
ar rcs libthird.a first.o second.o

