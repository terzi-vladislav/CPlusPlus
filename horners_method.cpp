#include <iostream>

double horner(int * arr, double x, int size) {
	double result = 0;
	for (int i = size - 1; i >= 0; --i)
		result = result * x + arr[i];
	return result;
}

int main() {
	int size = 0;
	std:: cin >> size;
	int arr[size] = {};
	for (int i = 0; i != size; ++i) {
		std::cin >> arr[i];
	}

	double x = 0, y = 0;

	std:: cin >> x;

	y = horner(arr, x, size);

	std:: cout << y;

	return 0;
}