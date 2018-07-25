#include <iostream>

void bubble_sort(int * arr, int size) {
	for (int i = 0; i < size - 1; ++i)
		for (int j = size - 1; j > i; --j)
			if (arr[j] < arr[j - 1]) {
				int key = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = key;
			}
}

int main() {
	int m[10] = {};
	for (int i = 0; i != 10; ++i) {
		std:: cin >> m[i];
	}

	bubble_sort(m, 10);

	for (int i = 0; i != 10; ++i) {
		std:: cout << m[i] << ' ';
	}

	return 0;
}