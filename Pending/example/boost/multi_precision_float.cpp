
/*
 multi precision float
 With Boost multi precision float,
 we can achieve precision up to 50 and 100 decimal with cpp_float_50 and cpp_dec_float_100 respectively.
 */
#include<iostream>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/math/constants/constants.hpp>

using boost::multiprecision::cpp_dec_float_50;

using namespace std;

template<typename T>
inline T area_of_a_circle(T r) {
	// pi represent predefined constant having value
	// 3.1415926535897932384...
	using boost::math::constants::pi;
	return pi<T>() * r * r;
}

int main() {
	float radius_f = 123.0 / 100;
	float area_f = area_of_a_circle(radius_f);

	double radius_d = 123.0 / 100;
	double area_d = area_of_a_circle(radius_d);

	cpp_dec_float_50 r_mp = 123.0 / 100;
	cpp_dec_float_50 area_mp = area_of_a_circle(r_mp);

	// numeric_limits::digits10 represent the number
	// of decimal digits that can be held of particular
	// data type without any loss.

	// Area by using float data type
	cout << "Float: " << setprecision(numeric_limits<float>::digits10) << area_f
			<< endl;

	// Area by using double data type
	cout << "Double: " << setprecision(numeric_limits<double>::digits10)
			<< area_d << endl;

	// Area by using Boost multi precision
	cout << "Boost multi precision: "
			<< setprecision(numeric_limits < cpp_dec_float_50 > ::digits10)
			<< area_mp << endl;
	return 0;
}
