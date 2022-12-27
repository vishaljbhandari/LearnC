# source code -> foo.c
# header code -> foo.h

# -Wall 	-> enables all compiler's warning messages. This option should always be used, in order to generate better code
# -Werror 	-> 
# -fPIC		-> generates position independent code (PIC) for shared libraries
# -o out_file   -> writes the build output to an output file
# -c 		-> compiles source files without linking
# -Dvar=value	-> defines a macro to be used by the preprocessor
# -I 		-> adds include directory of header files
# -l 		-> links with a library file
# -L 		-> looks in directory for library files
# -shared	-> turn output object file into a shared library


# -O option 	-> Set the compiler's optimization level
# Compilation Options		
#option		optimization level					execution time	code size	memory usage	compile time
#-O0		optimization for compilation time (default)		+		+		-		-
#-O1 or -O	optimization for code size and execution time	-		-		+		+
#-O2		optimization more for code size and execution time	--	 			+		++
#-O3		optimization more for code size and execution time	---	 			+		+++
#-Os		optimization for code size	 					--	 			++
#-Ofast		O3 with fast none accurate math calculations		---	 			+		+++


# -g            -> generates debug information to be used by GDB debugger
# debug informations
# option	description
#-g0	no debug information
#-g1	minimal debug information
#-g	default debug information
#-g3	maximal debug information




#gcc -Olevel -glevel -Dmacro_variable=macro_value [-Iheader_file_directory] [-Ldir_for_libraries] -llibname [options] [source files] [object files] [-o output file]



gcc -c -DDEBUG -Wall -Werror -fPIC -g3 -O0 -Iinclude -lmath -o bin/foo.o src/foo.c


# DEBUG - a macro passed through compilation 
# -g3 	- maximal debug information
# -O0	- Optimization for compilation time
# -Iinclude  - adding include directory for header file boo.h
# -lmath  - to use shared library file libmath.so



# Creating a shared library from an object file
# -shared  -> create shared library
# -o out_file -> output file
# libs/	-> create library in lib directory
gcc -shared -o libs/libfoo.so bin/foo.o
# for shared output library file, object file acts as input/source code file



# Linking with a shared library
# gcc -Wall -o executable main.c -lfoo	# this will give error, as it is not aware where to file shared library

# -lfoo  - linking libfoo.so dynamic library
# -o 	 - output binary


# Telling GCC where to find the shared library
# 1) using -L option, at compile time

gcc -L/store/c_space/shared_libraries/dynamic_libraries/libs -Wall -o bin/executable -Iinclude src/main.c -lfoo	# search in /store/c_space/dynamic_libraries/libs directory (absolute or relative paths)
#gcc -L. -Wall -o bin/executable main.c -lfoo    # search in current directory

# 2) Making the library available at runtime, on production or execution machine, using LD_LIBRARY_PATH environment variable, add library path in this variable

export LD_LIBRARY_PATH=/store/c_space/shared_libraries/dynamic_libraries/libs:$LD_LIBRARY_PATH
#once library is added into LD_LIBRARY_PATH in run time, we can execute the exucatable linked with shared libraries
./bin/executable



# Deliverables
./bin/executable	# to execute code
./libs/libfoo.so	# add this library directory in to LD_LIBRARY_PATH in run time machine
