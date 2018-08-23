#include <iostream>
using namespace std;

class Person {
public:
	virtual string name() const { // virtual function
		return name_;
	}
	...
};

class Professor : public Person {
	string name() const {
		return "Prof. " + Person::name();
	}
	...
};

int main( ) {
	Professor pr("Cormen");
	cout << pr.name() << endl; //Prof. Cormen
	Person * p = &pr;
	cout << p->name() << endl; //Prof. Cormen, function is picked depending on the object
}