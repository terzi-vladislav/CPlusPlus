#include <iostream>
using namespace std;

template <class FIRST, class SECOND>
FIRST add(FIRST a, SECOND b) {
	return a + b;
}

double add(int a, double b) {
	return a + b;
}

int main() {
	int x = 1;
	double y = 2.3;
	cout << add(x, y) << endl;
}