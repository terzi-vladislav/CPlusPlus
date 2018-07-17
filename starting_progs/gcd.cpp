#include <iostream>
using namespace std;

unsigned gcd(unsigned a, unsigned b){
	return b ? gcd(b, a % b) : a;
}

int main() {
	unsigned a = 0;
	unsigned b = 0;
	cin >> a >> b;
	cout << gcd(a, b) << endl;

	return 0;
}