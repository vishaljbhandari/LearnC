find . -name "*.c" -printf '%P\n' | grep -v '^_' | awk -F"\.c$" '{ print $1";;" }' > c_file_list.data

find . -name "*.cpp" -printf '%P\n' | grep -v '^_' | awk -F"\.cpp$" '{ print $1";;" }' > cpp_file_list.data
