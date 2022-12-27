// gcc -Wall -Wextra -Werror -lstdc++ -lm complex_numbers.cpp
#include<iostream>
#include<stdio.h>
using namespace std;

class Complex {
private:
	float real, img;
public:
	Complex();
	friend istream& operator >>(istream&, Complex&);
	friend ostream& operator <<(ostream&, Complex&);
	Complex operator +(Complex&);
	Complex operator -(Complex&);
	Complex operator *(Complex&);
	Complex operator /(Complex&);
};

Complex::Complex() {
	real = img = 0;
}

istream& operator>>(istream &in, Complex &c) {
	cout << "Enter Real Number : ";
	in >> c.real;
	cout << "Enter Imaginary part : ";
	in >> c.img;
	return in;
}

ostream& operator<<(ostream &out, Complex &c) {
	out << "(" << c.real << ", i" << c.img << ")";
	return out;
}

Complex Complex::operator +(Complex &c) {
	Complex tmp;
	tmp.real = real + c.real;
	tmp.img = img + c.img;

	return tmp;
}

Complex Complex::operator -(Complex &c) {
	Complex temp;
	temp.real = real - c.real;
	temp.img = img - c.img;
	return temp;
}

Complex Complex::operator *(Complex &c) {
	Complex tmp;
	tmp.real = real * c.real - real * img;
	tmp.img = real * c.img + img * c.real;
	return tmp;
}

Complex Complex::operator /(Complex &c) {
	Complex number;
	number.real = (real * c.real + img * c.img)
			/ (c.real * c.real + c.img * c.img);
	number.img = real * c.img
			- img * c.real / (c.real * c.real + c.img * c.img);
	return number;
}

int main() {
	Complex c1;
	Complex c2;
	Complex c3;

	cout << "1st Object" << endl;
	cin >> c1;
	cout << endl;
	cout << "2nd Object" << endl;
	cin >> c2;

	cout << "Real and Imaginary Value For 1st Object :" << c1 << endl;
	cout << "Input The Real and Imaginary Value For 1st Object :" << c2 << endl
			<< endl;

	c3 = c1 + c2;
	cout << "Addition of Complex Number " << c3 << endl;

	c3 = c1 - c2;
	cout << "Subtraction of Complex Number : " << c3 << endl;

	c3 = c1 * c2;
	cout << "Multiplication of Complex Number : " << c3 << endl;

	c3 = c1 / c2;
	cout << "Division of Complex Number : " << c3 << endl;
	return 0;
}
