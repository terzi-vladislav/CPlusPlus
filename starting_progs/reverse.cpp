#include <iostream>
using namespace std;

void func() {
	int a = -1;
	cin >> a;
	if (a == 0)
		return;
	func();
	cout << a << " ";
	return;
}

int main() {
	func();

	return 0;
}