#include <stdio.h>

enum card_suit {
	SPD, HRT, DIA, CLB
};
enum card_rank {
	ACE = 1, JACK = 11, QUEEN, KING
};

const char *aceString = "Ace";		// character arrays
const char *jckString = "Jack";
const char *queString = "Queen";
const char *kngString = "King";
const char *spdString = "Spades";
const char *hrtString = "Hearts";
const char *diaString = "Diamonds";
const char *clbString = "Clubs";

typedef struct card {
	unsigned char r;
	unsigned char s;
} card_t;

card_t deck[52] = { { ACE, SPD }, { 2, SPD }, { 3, SPD }, { 4, SPD },
		{ 5, SPD }, { 6, SPD }, { 7, SPD }, { 8, SPD }, { 9, SPD }, { 10, SPD },
		{ JACK, SPD }, { QUEEN, SPD }, { KING, SPD }, { 1, HRT }, { 2, HRT }, {
				3, HRT }, { 4, HRT }, { 5, HRT }, { 6, HRT }, { 7, HRT }, { 8,
				HRT }, { 9, HRT }, { 10, HRT }, { JACK, HRT }, { QUEEN, HRT }, {
				KING, HRT }, { 1, DIA }, { 2, DIA }, { 3, DIA }, { 4, DIA }, {
				5, DIA }, { 6, DIA }, { 7, DIA }, { 8, DIA }, { 9, DIA }, { 10,
				DIA }, { JACK, DIA }, { QUEEN, DIA }, { KING, DIA }, { 1, CLB },
		{ 2, CLB }, { 3, CLB }, { 4, CLB }, { 5, CLB }, { 6, CLB }, { 7, CLB },
		{ 8, CLB }, { 9, CLB }, { 10, CLB }, { JACK, CLB }, { QUEEN, CLB }, {
				KING, CLB } };

void print_card(const card_t *c);

int main(int argc, char **argv) {

	for (int i = 0; i < 52; i++) {
		print_card(&deck[i]);
	}

	return 0;
}

void print_card(const card_t *c) {
	if (c->r >= 2 && c->r <= 10) {
		printf("%d", c->r);
	} else {
		switch (c->r) {
		case ACE:
			fputs(aceString, stdout);
			break;
		case JACK:
			fputs(jckString, stdout);
			break;
		case QUEEN:
			fputs(queString, stdout);
			break;
		case KING:
			fputs(kngString, stdout);
			break;
		}
	}
	fputs(" of ", stdout);
	switch (c->s) {
	case SPD:
		fputs(spdString, stdout);
		break;
	case HRT:
		fputs(hrtString, stdout);
		break;
	case DIA:
		fputs(diaString, stdout);
		break;
	case CLB:
		fputs(clbString, stdout);
		break;
	}
	fputs("\n", stdout);
}
