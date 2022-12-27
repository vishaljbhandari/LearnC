// gcc -Wall -Wextra -Werror -lm -o enum enum.cpp  -lstdc++
#include <iostream>
using namespace std;

// just like other elements
// enum => type

enum card_suit {
	SPD, HRT, DIA, CLB	// enum constants with a value mechanism
	// first enum value is 0, then next is 1, 2, 3 .... and so on
};
enum card_rank {
	ACE = 1, JACK = 11, QUEEN, KING
	// here explicit values are defined so those values will be considered as value of that enum constant
	// in case any value is not specified, then value will be assigned in incremental manner from last defined variable value.
	// here ACE is explicitly defined as 1 so ACE is 1
	// JACK is explicitly defined as 11, so JACK is 11
	// No value for QUEEN so last defined value + 1, therefore QUEEN will be 12
	// similarly for KING, value will be 13
};

const string aceString = "Ace";
const string jckString = "Jack";
const string queString = "Queen";
const string kngString = "King";
const string spdString = "Spades";
const string hrtString = "Hearts";
const string diaString = "Diamonds";
const string clbString = "Clubs";

struct card {
	unsigned char r;
	unsigned char s;
};

// Using uniform initialization

card deck[52] = { { ACE, SPD }, { 2, SPD }, { 3, SPD }, { 4, SPD }, { 5, SPD },
		{ 6, SPD }, { 7, SPD }, { 8, SPD }, { 9, SPD }, { 10, SPD },
		{ JACK, SPD }, { QUEEN, SPD }, { KING, SPD }, { 1, HRT }, { 2, HRT }, {
				3, HRT }, { 4, HRT }, { 5, HRT }, { 6, HRT }, { 7, HRT }, { 8,
				HRT }, { 9, HRT }, { 10, HRT }, { JACK, HRT }, { QUEEN, HRT }, {
				KING, HRT }, { 1, DIA }, { 2, DIA }, { 3, DIA }, { 4, DIA }, {
				5, DIA }, { 6, DIA }, { 7, DIA }, { 8, DIA }, { 9, DIA }, { 10,
				DIA }, { JACK, DIA }, { QUEEN, DIA }, { KING, DIA }, { 1, CLB },
		{ 2, CLB }, { 3, CLB }, { 4, CLB }, { 5, CLB }, { 6, CLB }, { 7, CLB },
		{ 8, CLB }, { 9, CLB }, { 10, CLB }, { JACK, CLB }, { QUEEN, CLB }, {
				KING, CLB } };

// {x,y} is one value of card

void print_card(const card &c);

int main() {

	for (int i = 0; i < 52; i++) {
		print_card(deck[i]);
	}

	return 0;
}

void print_card(const card &c) {
	if (c.r >= 2 && c.r <= 10) {
		printf("%d", c.r);
	} else {
		switch (c.r) {
		case ACE:
			cout << aceString;
			break;
		case JACK:
			cout << jckString;
			break;
		case QUEEN:
			cout << queString;
			break;
		case KING:
			cout << kngString;
			break;
		}
	}
	cout << " of ";
	switch (c.s) {
	case SPD:
		cout << spdString;
		break;
	case HRT:
		cout << hrtString;
		break;
	case DIA:
		cout << diaString;
		break;
	case CLB:
		cout << clbString;
		break;
	}
	cout << endl;
}
