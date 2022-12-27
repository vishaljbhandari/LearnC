#!/bin/bash

if [ -d $1 ] 
then
	find $1 -type f -name "*.c" -o -name "*.cc" -o -name "*.cpp"  | xargs cppcheck
else
    	echo -e "Invalid directory " $1
    	find . -type f -name "*.c" -o -name "*.cc" -o -name "*.cpp"  | xargs cppcheck
fi
