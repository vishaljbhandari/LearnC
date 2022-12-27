#include <iostream>
#include <cstdio>
using namespace std;



int main() {
	// Every system is made up of objects in real time
	// Objects are instance of a class
	// Objects are run time entity of the class
	// Different objects collaborate with each others
	// This collaboration defines the behavior of the system


	// This collaboration is defined/decided using

	// COMPOSITION (HAS-A, Reuse of Object)
	/*
	 * Relationship of Inner & Outer -> (OUTER has INNER)
	 * One object is composed into another object {One object(inner object) is a property of another object(outer object)}
	 * Represent = "HAS-A" relationship {one has another}
	 * This also allows to reuse existing objects
	 * Outer object reuses the behavior of inner object for its functionality
	 * Example - > Car Object(Outer), Engine Object(Inner), Each car(outer) has engine(inner object.
	 * 		So each CAR has an Engine [HAS-A] Relationship
	 */

	// INHERITENCE (IS-A, Reuse of Behavior)
	/*
	 * One class inherits feature of another class
	 * Child inherits and reuses behaviour of parent
	 * Presents = "IS-A" relationship (Child is a Parent)
	 * Example - > Animal(Base), Sheep, Dog are (Child)
	 * 		All children Dog, Sheep are reusing behaviour of Animal Class
	 * 		Also each child, sheep and dog are Animal(parent) [IS-A] Relationship
	 */



	return 0;
}
