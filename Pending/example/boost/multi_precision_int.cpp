// gcc -lm -lstdc++ multi_precision_int.cpp

/*
 Arbitrary precision data type
 We can use any precision with the help of cpp_int data type if we are not sure about how much precision is needed in future. It automatically converts the desired precision at the Run-time.
 Below implementation of C++ code for finding the factorial of 30.
 */
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
using namespace std;

cpp_int boost_factorial(int num) {
	cpp_int fact = 1;
	for (int i = num; i > 1; --i)
		fact *= i;
	return fact;
}

int main() {
	int num = 30;
	cout << "Factorial of " << num << " = " << boost_factorial(num) << endl;
	return 0;
}
