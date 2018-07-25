#include <iostream>

void select_sort(int * arr, int size) {
	for (int j = 0; j < size - 1; ++j) {
		int min = arr[j];
		int pointer = j;
		for (int i = j + 1; i < size; ++i)
			if (arr[i] < min) {
				pointer = i;
				min = arr[i];
			}
		arr[pointer] = arr[j];
		arr[j] = min;
	}
}

int main() {
	int m[10] = {};
	for (int i = 0; i != 10; ++i) {
		std::cin >> m[i];
	}

	select_sort(m, 10);

	for (int i = 0; i != 10; ++i) {
		std:: cout << m[i] << ' ';
	}

	return 0;
}