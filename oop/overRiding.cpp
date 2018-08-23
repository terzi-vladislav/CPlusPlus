#include <iostream>
using namespace std;

class Person {
public:
	string name() const {
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
	cout << p->name() << endl; //Cormen
}