#To find which library is being used you could run
echo -e "Find which library is being used"
/sbin/ldconfig -p | grep stdc++
#output#    libstdc++.so.6 (libc6) => /usr/lib/libstdc++.so.6


# The list of compatible versions for libstdc++ version 3.4.0 and above is provided by
echo -e "\nThe list of compatible versions for libstdc++"
/sbin/ldconfig -p | grep stdc++ | awk -F"=>" '{ print $2}' | xargs strings | grep LIBCXX
#or
#strings /usr/lib/libstdc++.so.6 | grep LIBCXX
#or
#strings /usr/lib64/libstdc++.so.6 | grep LIBCXX

#output# GLIBCXX_3.4
#output# GLIBCXX_3.4.1
#output# GLIBCXX_3.4.2

# For earlier versions the symbol GLIBCPP is defined
# for example use libdatestamp.cpp program
