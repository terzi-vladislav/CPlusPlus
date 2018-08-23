#include <iostream>
using namespace std;

class Person {
public:
	virtual ~Person() {} //good for inheritance
	...
};

class Student : public Person {
public:
	string occupation() const {
		return "student";
	}
	~Student() {
		... 
	}
	...
private:
	string uni;
};

int main( ) {
	Person * p = new Student("Alex", 21, "Oxford");
	...
	delete p; //will not call a uni destructor
}