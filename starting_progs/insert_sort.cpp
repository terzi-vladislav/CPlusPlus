#include <iostream>
using namespace std;

void sort(int * arr, int size) {
	for (int j = 1; j < size; ++j) {
		int key = arr[j];
		int i = j - 1;
		while (i >= 0 && arr[i] > key) {
			arr[i + 1] = arr[i];
			--i;
		} 
		arr[i + 1] = key;
	}
}

int main() {
	int m[10] = {};
	for (int i = 0; i != 10; ++i) {
		cin >> m[i];
	}

	sort(m, 10);

	for (int i = 0; i != 10; ++i) {
		cout << m[i] << ' ';
	}

	return 0;
}