#include <iostream>
using namespace std;

unsigned long factorial(unsigned long n) {
	if (n < 2)
		return 1;
	return n * factorial (n - 1);
}

int main() {
	unsigned long n = 0;
	cin >> n;
	cout << factorial(n) << endl;

	return 0;
}