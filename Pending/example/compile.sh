C_DATA_FILE=c_file_list.data
CPP_DATA_FILE=cpp_file_list.data
SEPARATOR=';'
FAILED=0
SUCCESS=0
TOTAL=0
if [ ! -f $C_DATA_FILE ]
then
    echo -e "[ERROR] C_DATA_FILE : [$C_DATA_FILE] missing"
        exit 1
fi
  
for cfile in `cat $C_DATA_FILE`
do
bin_file="$(echo $cfile | cut -d$SEPARATOR -f1)"
if [ ! -z $bin_file ]
then
source_file="$(echo $cfile | cut -d$SEPARATOR -f2)"
if [ -z $source_file ]
then
	source_file=$bin_file.c
fi
options="$(echo $cfile | cut -d$SEPARATOR -f3)"
let "TOTAL+=1"
gcc -o  $bin_file  $source_file $options
if [ $? == '0' ]
then
   let "SUCCESS+=1"
   echo -e "[$bin_file] Compiled [TOTAL $TOTAL, SUCCESS $SUCCESS, FAILED $FAILED] ---------"
else
   let "FAILED+=1"
   echo -e "[$bin_file] Compilation Failed [TOTAL $TOTAL, SUCCESS $SUCCESS, FAILED $FAILED] ---------"
fi
fi
done


if [ ! -f $CPP_DATA_FILE ]
then
    echo -e "[ERROR] CPP_DATA_FILE : [$CPP_DATA_FILE] missing"
        exit 2
fi
  
for cppfile in `cat $CPP_DATA_FILE`
do
bin_file="$(echo $cppfile | cut -d$SEPARATOR -f1)"
if [ ! -z $bin_file ]
then
source_file="$(echo $cppfile | cut -d$SEPARATOR -f2)"
if [ -z $source_file ]
then
        source_file=$bin_file.cpp
fi
options="$(echo $cppfile | cut -d$SEPARATOR -f3)"
let "TOTAL+=1"
g++ -Wall -Wextra -Werror -lm -o  $bin_file  $options $source_file 
if [ $? == '0' ]
then
   let "SUCCESS+=1"
   echo -e "[$bin_file] Compiled [TOTAL $TOTAL, SUCCESS $SUCCESS, FAILED $FAILED] ---------"
else
   let "FAILED+=1"
   echo -e "[$bin_file] Compilation Failed [TOTAL $TOTAL, SUCCESS $SUCCESS, FAILED $FAILED] ---------"
fi
fi
done

