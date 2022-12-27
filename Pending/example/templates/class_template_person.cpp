// gcc -lstdc++ -lm class_template_person.cpp
#include <iostream>
#include <string>
using namespace std;

template<class T>
class Person {
	T age;
	T height;
	T weight;

public:
	Person(T t_age, T t_height, T t_weight) {
		age = t_age;
		height = t_height;
		weight = t_weight;
	}
	T get_age();
	T get_height();
	T get_weight();
	void get_detail();
};

template<class T>
T Person<T>::get_age() {
	return this->age;
}

template<class T>
T Person<T>::get_height() {
	return this->height;
}

template<class T>
T Person<T>::get_weight() {
	return this->weight;
}

template<class T>
void Person<T>::get_detail() {
	cout << "Age: " << get_age() << endl << "Height: " << get_height() << endl
			<< "Weight: " << get_weight() << endl;
}

int main() {
	Person<int> intDetails(20, 5, 50);
	Person<float> floatDetails(20.5, 5.3, 50.6);
	Person<string> stringDetails("Twenty", "5 Feet, 4 Inches", "50 KG");

	intDetails.get_detail();
	floatDetails.get_detail();
	stringDetails.get_detail();
	return 0;
}
