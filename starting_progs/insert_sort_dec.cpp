#include <iostream>
using namespace std;

void sort_decend(int * arr, int size) {
	for (int j = size - 2; j >= 0; --j) {
		int key = arr[j];
		int i = j + 1;
		while (i <= size - 1 && arr[i] > key) {
			arr[i - 1] = arr[i];
			++i;
		} 
		arr[i - 1] = key;
	}
}

int main() {
	int m[5] = {};
	for (int i = 0; i != 5; ++i) {
		cin >> m[i];
	}

	sort_decend(m, 5);

	for (int i = 0; i != 5; ++i) {
		cout << m[i] << ' ';
	}

	return 0;
}