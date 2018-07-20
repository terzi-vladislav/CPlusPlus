#include <iostream>
using namespace std;

int ** create_array2d(int a, int b) {
	int ** m = new int *[a];
	m[0] = new int[a * b];
	for (int i = 1; i != a; ++i)
		m[i] = m[i - 1] + b;
	return m;
}

void swap_min(int ** m, unsigned rows, unsigned cols) {
	int min = m[0][0], pos_min = 0;
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			if (m[i][j] < min) {
				min = m[i][j];
				pos_min = i;
			}
		}
	}
	int * tmp[] = {};
	*tmp = m[pos_min];
	m[pos_min] = m[0];
	m[0] = *tmp;
}

int main() {
	int a = 0, b = 0;
	cin >> a >> b;
	int ** arr = 0;
	arr = create_array2d(a, b);

	for (int i = 0; i < a; ++i) {
		for (int j = 0; j < b; ++j) {
			cin >> arr [i][j];
		}
		cout << endl;
	}
	swap_min(arr, a, b);

	for (int i = 0; i < a; ++i) {
		for (int j = 0; j < b; ++j) {
			cout << arr [i][j] << ' ';
		}
		cout << endl;
	}

	return 0;
}