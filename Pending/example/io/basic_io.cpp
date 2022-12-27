#include <iostream>

/*
 iostream - Standard Input / Output Streams Library
 Header that defines the standard input/output stream objects:

 Objects

 Narrow characters (char)

 cin
 Standard input stream (object ) -> std::istream class
 cout
 Standard output stream (object ) -> std::ostream class
 cerr
 Standard output stream for errors (object )
 clog
 Standard output stream for logging (object )

 Wide characters (wchar_t)

 wcin
 Standard input stream (wide) (object )
 wcout
 Standard output stream (wide) (object )
 wcerr
 Standard output stream for errors (wide-oriented) (object )
 wclog
 Standard output stream for logging (wide) (object )

 */

// cout and cin represent console or standard i/o stream

using namespace std;

int main() {

	char buff[512];
	cout << "What is your name?\n"; // cout represent console, it means redirect output to console using << operator
	// between << we can use any inbuilt or standard library variable or object for which << operator overload function is already defined.
	// for putting any user define object between << we need to define << operator overload function in that class
	/*
	 There's a better way to do it. Check the
	 lecture on std::strings if you're curious :)
	 */

	// cout << abc; means give abc value to cout/console as operator direction indicates
	// abc gives(<<) value to cout/console

	cin.getline(buff, 64, '\n');

	/*
	 istream& getline (istream&  is, string& str, char delim);
	 istream& getline (istream&& is, string& str, char delim);

	 istream& getline (istream&  is, string& str);
	 istream& getline (istream&& is, string& str);

	 */
	// cin is an object of istream class and getline is function of this classed
	cout << "\nYour name is: " << buff << endl;
	// cout is object of ostream class and << is overloaded operator function of this class

	int age;
	cin >> age;
	// cin is object of istream class and >> is overloaded operator function of this class
	// cin represent console, it means accept input from console using >> operator
	// between >> we can use any inbuilt or standard library variable or object for which >> operator overload function is already defined.
	// for putting any user define object between >> we need to define << operator overload function in that class

	// cin >> abc; means give value from cin/console to abc variable as operator direction indicates
	// cin gives(>>) value to abc from console

	return 0;
}
