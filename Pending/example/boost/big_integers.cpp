// gcc -lm -lstdc++ big_integers.cpp
/*
 Big Integer data type
 We can use either int128_t, int256_t, int512_t or int1024_t data type according to your requirement.
 By using these one, we can achieve precision up to 1024 easily.
 Below C++ implementation code of finding the product of large numbers.
 */

#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
using namespace std;

int128_t boost_product(long long A, long long B) {
	int128_t ans = (int128_t) A * B;
	return ans;
}

int main() {
	long long first = 98745636214564698;
	long long second = 7459874565236544789;
	cout << "Product of " << first << " * " << second << " = "
			<< boost_product(first, second) << endl;
	return 0;
}
