/** Implementation of Prototype Method **/

/*

Because copying is cheaper than creating new object.
Copy Instead Of Create
Creational Design Pattern, Used when object creation is time consuming
Example


hide the complexity of making new instances from the client.
copy an existing object rather than creating a new instance from scratch, which may be a costly operation
existing object acts as a prototype and contains the state of the object
The newly copied object may change same properties only if required.

This approach saves costly resources and time, especially when the object creation is a heavy process.

Advantages of Prototype Design Pattern

    Adding and removing products at run-time – Prototypes let you incorporate a new concrete product class into a system simply by registering a prototypical instance with the client. That’s a bit more flexible than other creational patterns, because a client can install and remove prototypes at run-time.
    Specifying new objects by varying values – Highly dynamic systems let you define new behavior through object composition by specifying values for an object’s variables and not by defining new classes.
    Specifying new objects by varying structure – Many applications build objects from parts and subparts. For convenience, such applications often let you instantiate complex, user-defined structures to use a specific subcircuit again and again.
    Reduced subclassing – Factory Method often produces a hierarchy of Creator classes that parallels the product class hierarchy. The Prototype pattern lets you clone a prototype instead of asking a factory method to make a new object. Hence you don’t need a Creator class hierarchy at all.

Disadvantages of Prototype Design Pattern

    Overkill for a project that uses very few objects and/or does not have an underlying emphasis on the extension of prototype chains.
    It also hides concrete product classes from the client
    Each subclass of Prototype must implement the clone() operation which may be difficult, when the classes under consideration already exist. Also implementing clone() can be difficult when their internals include objects that don’t support copying or have circular references.

Example - Where a lot of loading api, databases etc is required.

*/

#include <iostream>
#include <unordered_map>
#include <string>
#include <memory>
using namespace std;

/** Record is the base Prototype */
class Record {
public:
	virtual ~Record() {
		cout<<"Record Destructor"<<endl;
	}
	virtual void print() = 0;					// pure virtual function
	virtual unique_ptr<Record> clone() = 0;		// pure virtual function
};

/** CarRecord is a Concrete Prototype */
class CarRecord: public Record {
private:
	string m_carName;
	int m_ID;

public:
	CarRecord(string carName, int ID) :
			m_carName(carName), m_ID(ID) {
	}

	void print() override
	{
		cout << "Car Record" << endl << "Name  : " << m_carName << endl
				<< "Number: " << m_ID << endl << endl;
	}

	unique_ptr<Record> clone() override
	{
		return make_unique < CarRecord > (*this);
	}
};

/** BikeRecord is the Concrete Prototype */
class BikeRecord: public Record {
private:
	string m_bikeName;
	int m_ID;

public:
	BikeRecord(string bikeName, int ID) :
			m_bikeName(bikeName), m_ID(ID) {
	}

	void print() override
	{
		cout << "Bike Record" << endl << "Name  : " << m_bikeName << endl
				<< "Number: " << m_ID << endl << endl;
	}

	unique_ptr<Record> clone() override
	{
		return make_unique < BikeRecord > (*this);
	}
};

/** PersonRecord is the Concrete Prototype */
class PersonRecord: public Record {
private:
	string m_personName;
	int m_age;

public:
	PersonRecord(string personName, int age) :
			m_personName(personName), m_age(age) {
	}

	void print() override
	{
		cout << "Person Record" << endl << "Name : " << m_personName << endl
				<< "Age  : " << m_age << endl << endl;
	}

	unique_ptr<Record> clone() override
	{
		return make_unique < PersonRecord > (*this);
	}
};

/** Opaque record type, avoids exposing concrete implementations */
// Enum to choose multiple prototypes
enum RecordType {
	CAR, BIKE, PERSON
};

/** RecordFactory is the client */
class RecordFactory {
private:
	// Prototype List
	unordered_map<RecordType, unique_ptr<Record>, hash<int> > m_records;

public:
	RecordFactory() {
		// List of prototypes
		m_records[CAR] = make_unique < CarRecord > ("Ferrari", 5050);
		m_records[BIKE] = make_unique < BikeRecord > ("Yamaha", 2525);
		m_records[PERSON] = make_unique < PersonRecord > ("Tom", 25);
	}

	unique_ptr<Record> createRecord(RecordType recordType) {
		return m_records[recordType]->clone();
	}
};

int main() {
	RecordFactory recordFactory;

	auto record = recordFactory.createRecord(CAR);
	record->print();

	record = recordFactory.createRecord(BIKE);
	record->print();

	record = recordFactory.createRecord(PERSON);
	record->print();
}
