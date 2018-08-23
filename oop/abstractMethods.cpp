#include <iostream>
using namespace std;

class Person {
public:
	virtual string occupation() const = 0;
	...
};

class Student : public Person {
	string occupation() const {
		return "student";
	}
	...
};

class Professor : public Person {
	string occupation() const {
		return "professor";
	}
	...
};

int main( ) {
	...
	Person * p = next_person();
	cout << p->occupation();
	...
}