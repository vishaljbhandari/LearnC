// TO CONVERT INTERGER AND FLOATING VALUES  TO ASCII STRING.

// gcc -Wall -Wextra -Werror -lm -lstdc++ num_to_string.cp

#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;

void NumToAscii(int num) {
	char str[20], ch;
	int i = 0, no = 0, tmp;
	tmp = num;
	while (num) {
		no *= 10;
		no += num % 10;
		num /= 10;
	}
	num = 0;
	while (no) {
		num = no % 10;
		ch = (char) num;
		str[i++] = ch + 48;
		no /= 10;
	}
	str[i] = '\0';
	cout << "Ascii String Of " << tmp << " is " << str;

}
void NumToAscii(float fnum, int dec) {
	long num, no = 0;
	char str[20], ch;
	int i = 0, power = 0;
	int bdec = 0;
	power = pow10(dec);
	num = fnum;
	while (num) {
		bdec++;
		num = num / 10;
	}
	num = fnum * power;
	num += 1;
	while (num) {
		no *= 10;
		no += num % 10;
		num /= 10;
	}
	num = 0;
	while (no) {
		num = no % 10;
		ch = num;
		if (bdec == 0) {
			str[i++] = '.';
			str[i++] = ch + 48;
		} else
			str[i++] = ch + 48;
		bdec--;
		no /= 10;
	}
	str[i] = '\0';
	cout << "\n\nAscii String Of " << fnum << " is " << str;
}
int main() {
	int num, dec;
	float fnum;
	cout << "Enter Any Integer Value : ";
	cin >> num;
	NumToAscii(num);
	cout << "\n\nNow Enter Float Value : ";
	cout << "\n\nHow many Digits After Decimal  : ";
	cin >> dec;
	cout << "Enter Any Float Value With Specified Decimal Point : ";
	cin >> fnum;
	NumToAscii(fnum, dec);
	return 0;
}
