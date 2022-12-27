// iostream-file.cpp by Bill Weinman <http://bw.org/>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string lineno () {
	static int lineint;
	static char linestr[3];
	if(lineint >= 99) lineint = 0;
	sprintf(linestr, "%02d", ++lineint);
	return string(linestr);
}

int main( int argc, char ** argv ) {
	const char * filename = "test.txt";
	string buffer;	// for reads

	// write a file
	cout << "write the file:" << endl;
	ofstream ofile(filename);
	ofile << lineno() << " " << "This is the test file." << endl;
	ofile << lineno() << " " << "This is the test file." << endl;
	ofile << lineno() << " " << "This is the test file." << endl;
	ofile.close();

	// read a file
	cout << "read the file:" << endl;
	ifstream infile(filename);
	while (infile.good()) {
		getline(infile, buffer);
		cout << buffer << endl;
	}
	infile.close();

	// append a file
	cout << "open file for append:" << endl;
	fstream afile(filename, fstream::in | fstream::out | fstream::app );
	if(!afile.good()) {
		cout << "failed to open" << endl;
		exit(0);
	}
	cout << "current contents:" << endl;
	afile.seekg (0, fstream::beg);	// seek to beginning of file
	while (afile.good()) {
		getline(afile, buffer);
		cout << buffer << endl;
	}
	afile.clear();	// clear error flags after reading to eof

	cout << "append lines:" << endl;
	afile << lineno() << " " << "This is the test file." << endl;
	afile << lineno() << " " << "This is the test file." << endl;
	afile << lineno() << " " << "This is the test file." << endl;

	cout << "content after append:" << endl;
	afile.seekg (0, fstream::beg);	// seek to beginning of file
	while (afile.good()) {
		getline(afile, buffer);
		cout << buffer << endl;
	}
	afile.close();

	// delete file
	cout << "delete file." << endl;
	remove(filename);
	return 0;
}
