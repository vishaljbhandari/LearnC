C_DATA_FILE=c_file_list.data
CPP_DATA_FILE=cpp_file_list.data
SEPARATOR=';'
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
	rm $bin_file
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
	rm $bin_file
fi
done


