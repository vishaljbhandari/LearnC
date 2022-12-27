#include <stdexcept>
#include <iostream>
#include <memory>
using namespace std;

/*
FDP - Factory Design Pattern - Virtual Creator/Interface for objection creation
Creates object for you.

Implementation
Define an interface/abstract class to create blank/sample objects dynamically.

User/subclass will call this FDP interface and initiate object returned by pattern interface


Simple Example to Implement-----
One Abstract Class with pure virtual function and virtual destructor
Multiple Sub/derived Classes
One Interface class/function to instantiate derived class pointer and pass to user

*/

class Pizza {
public:
	virtual int getPrice() const = 0;
	virtual ~Pizza() {
	}
	;
	/* without this, no destructor for derived Pizza's will be called. */
};

class HamAndMushroomPizza: public Pizza {
public:
	virtual int getPrice() const {
		return 850;
	}
	;
	virtual ~HamAndMushroomPizza() {
	}
	;
};

class DeluxePizza: public Pizza {
public:
	virtual int getPrice() const {
		return 1050;
	}
	;
	virtual ~DeluxePizza() {
	}
	;
};

class HawaiianPizza: public Pizza {
public:
	virtual int getPrice() const {
		return 1150;
	}
	;
	virtual ~HawaiianPizza() {
	}
	;
};


// ----------------


class PizzaFactory {		/// this an abstract interface, Creator Class,  Factory Class
public:
	enum PizzaType {
		HamMushroom, Deluxe, Hawaiian
	};

	static unique_ptr<Pizza> createPizza(PizzaType pizzaType) {		/// tell me which dynamic type you want, I will provide you object of that.
		switch (pizzaType) {
		case HamMushroom:
			return make_unique<HamAndMushroomPizza>();
		case Deluxe:
			return make_unique<DeluxePizza>();
		case Hawaiian:
			return make_unique<HawaiianPizza>();
		}
		throw "invalid pizza type.";
	}
};

/*
 * Create all available pizzas and print their prices
 */
void pizza_information(PizzaFactory::PizzaType pizzatype) {
	unique_ptr<Pizza> pizza = PizzaFactory::createPizza(pizzatype);
	cout << "Price of " << pizzatype << " is " << pizza->getPrice()
			<< std::endl;
}

int main() {
	pizza_information(PizzaFactory::HamMushroom);
	pizza_information(PizzaFactory::Deluxe);
	pizza_information(PizzaFactory::Hawaiian);
}
