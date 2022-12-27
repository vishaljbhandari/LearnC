#include <stdio.h>

int main() {
	typedef float radius;

	radius a;

	a = 27.5;

	printf("A circle with radius %.2f has an area of  %.2f\n", a,
			a * a * 3.1415926);

	struct person {
		char name[32];
		int iq;
	};
	struct person me;
	typedef struct person human;

	strcpy(me.name, "Dan Gookin");
	me.iq = 567;

	printf("%s has an IQ of %d\n", me.name, me.iq);

	human me;

	strcpy(me.name, "Dan Gookin");
	me.iq = 567;

	printf("%s has an IQ of %d\n", me.name, me.iq);

	return (0);
}

