#include <iostream>
using namespace std;

void bar() {
	int c;
	cout << c << endl;
}

void foo() {
	int b = 3;
	bar();
}

int main() {
	int a = 3;
	foo();
	bar();

	return 0;
}