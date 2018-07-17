#include <iostream>
using namespace std;

int foo() {
	cout << "Hello" << endl;
	return 2;
}

int bar() {
	int * m[1];
	m[2] = (int *) &foo;
	return 1;
}

int main() {
	bar(); 

	return 0;
}