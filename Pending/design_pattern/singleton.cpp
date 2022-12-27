/*
 Singleton design pattern is a software design principle that is used to restrict the instantiation of a class to one object.
 This is useful when exactly one object is needed to coordinate actions across the system.

 The singleton pattern is a design pattern that restricts the instantiation of a class to one object.

 Where to use singleton pattern



 Advantage/Pros
 1) Instance control: Singleton prevents other objects from instantiating their own copies of the Singleton object, ensuring that all objects access the single instance.
 2) Flexibility: Since the class controls the instantiation process, the class has the flexibility to change the instantiation process.
 3) Easy to implement: Easy to create and we could use it anywhere for the lifetime of the app The advantage of Singleton over global variables is that
 you are absolutely sure of the number of instances when you use Singleton.
 However, you can still change your mind and manage any number of instances.
 Having a very versatile design pattern that can work well for many different applications and processes.


 Disadvantage/Cons of Singleton
 1) They are a global mutable shared state. Their state is automatically shared across the entire app, and bugs can often start occurring when that state changes unexpectedly.
 2) The relationships between Singletons and the code that depends on them is usually not very well defined.
 Since Singletons are so convenient and easy to access — using them extensively usually leads to very hard to maintain “spaghetti code” that doesn’t have clear separations between objects.
 3) Managing their life-cycle can be tricky.
 Since Singletons are alive during the entire lifespan of an application, managing them can be really hard, and they usually have to rely on optionals to keep track of values.
 This also makes code that relies on Singletons really hard to test, since you can’t easily start from a “clean slate” in each test case.
 The disadvantages of Singleton over a global mutable shared state can give you a real headache if the state changes unexpectedly and also keep your code tightly coupled.
 It will make difficult to test when your code is not loosely coupled so it will cause a lot problems to maintain.


 Dependency Injection (Singleton problem solved)
 Even if you decide to use Singleton in a project, that doesn't mean you have to access them anywhere or any time in your project.
 You can still use dependency injection to pass the Singleton object to the objects that need it.
 By adopting dependency injection to pass Singletons around, the interface of your class remains clear and transparent.
 In other words, the interface of the class describes its dependencies.
 This is very, very useful. It immediately shows which objects the class needs to perform its duties.

 Characteristics of Singleton Class
 1) Only private constructors
 2) One static pointer instance of singleton class to hold the singleton object
 3) A static getInstance function to return instance of singleton class
 This function returns instance if it is initialized else initialize and return the instance
 4) Initialize pointer instance of singleton class with NULL before use
 */

#include <iostream>
using namespace std;

class Singleton {
	static Singleton *instance;	// sole instance, which will be used all time for Singleton class
	int data;

	// Private constructor so that no objects can be created.
	Singleton() :
			data(0) {
	}

	Singleton(int data) :
			data(data) {
	}

public:
	static Singleton* getInstance() {
		if (!instance)
			instance = new Singleton;
		return instance;
	}

	static Singleton* getInstance(int data) {
		if (!instance)
			instance = new Singleton(data);
		return instance;
	}

	static void destroyInstance() {
		if (!instance)
			delete instance;
		instance = NULL;
	}

	~Singleton() {
		data = 0;
	}

	int getData() {
		return this->data;
	}

	void setData(int data) {
		this->data = data;
	}
};

//Initialize pointer to zero so that it can be initialized in first call to getInstance
Singleton *Singleton::instance = NULL;

int main() {
	Singleton *single;
	single = Singleton::getInstance();
	cout << single->getData() << endl;
	single->setData(100);
	cout << single->getData() << endl;

	Singleton::destroyInstance();
	single = NULL;

	single = Singleton::getInstance(5);
	cout << single->getData() << endl;
	single->setData(100);
	cout << single->getData() << endl;
	return 0;
}
