#include <cstdio>
using namespace std;

// used to give a type a new name
// renaming(creating alias) any existing type

typedef unsigned char points_t;
typedef unsigned char rank_t;

struct score {
	points_t p;
	rank_t r;
};

typedef struct score scores;

int main() {
	struct score s1 = { 5, 1 };
	scores s2 = { 6, 2 };
	printf("score s1 had %d points and a rank of %d\n", s1.p, s1.r);
	printf("score s2 had %d points and a rank of %d\n", s2.p, s2.r);

	return 0;
}

/*
 #define is a C-directive which is also used to define the aliases for various data types similar to typedef but with the following differences −

 typedef is limited to giving symbolic names to types only
 whereas #define can be used to define alias for values as well, q., you can define 1 as ONE etc.

 typedef interpretation is performed by the compiler
 whereas #define statements are processed by the pre-processor.

 */
