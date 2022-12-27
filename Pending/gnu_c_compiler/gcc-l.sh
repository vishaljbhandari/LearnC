# gcc -I option flag
# gcc -I adds include directory of header files.

# Syntax
# gcc -Idir [options] [source files] [object files] [-o output file]


# gcc myfile.c -o myfile	# this will cause error
# needs to include the directory with -I option


gcc -Iproj1/src/ myfile.c -o myfile

# bellow will also work
# gcc proj1/src/myfile.c -o myfile
