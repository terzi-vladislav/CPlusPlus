#include <iostream>
using namespace std;

int ** create_array2d(int a, int b) {
	int ** m = new int *[a];
	m[0] = new int[a * b];
	for (int i = 1; i != a; ++i)
		m[i] = m[i - 1] + b;
	return m;
}

void free_array2d(int ** m, int a, int b) {
	delete [] m[0];
	delete [] m;
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

	for (int i = 0; i < a; ++i) {
		for (int j = 0; j < b; ++j) {
			cout << arr [i][j] << ' ';
		}
		cout << endl;
	}

	free_array2d(arr, a, b);

	arr = 0;

	return 0;
}