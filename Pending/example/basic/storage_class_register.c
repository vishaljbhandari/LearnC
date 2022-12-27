#include <stdio.h>
// The register Storage Class
/*

 The register storage class is used to define local variables that should be stored in a register instead of RAM.
 This means that the variable has a maximum size equal to the register size (usually one word) and can't have the unary '&' operator applied to it (as it does not have a memory location).

 */
int main() {
	register int miles;
	printf("register variable int miles = %d\n", miles);
	return 0;
}
/*
 The register should only be used for variables that require quick access such as counters.
 It should also be noted that defining 'register' does not mean that the variable will be stored in a register.
 It means that it MIGHT be stored in a register depending on hardware and implementation restrictions.
 */
