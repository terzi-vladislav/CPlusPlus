#include <iostream>
#include <string>
using namespace std;

class Person {
public:
	Person(string name, int age) : name_(name), age_(age) {}

	string name() const {
		return name_;
	}

	int age() const {
		return age_;
	}

private:
	string name_;
	int age_;
};

class Student : public Person {
public:
	Student(string name, int age, string uni) : Person(name, age), uni_(uni) {
	}

	string university() const {
		return uni_;
	}

private:
	string uni_;
};

int main() {

	Student s("sally", 16, "mipt");
	cout << s.name() << endl;

	Person * s1 = &s; //приведение 
	Person & s2 = s;

}