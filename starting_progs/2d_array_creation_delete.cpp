#include <iostream>
using namespace std;

int ** create_array2d(int a, int b) {
	int ** m = new int *[a];
	for (int i = 0; i != a; ++i)
		m[i] = new int[b];
	return m;
}

void free_array2d(int ** m, int a, int b) {
	for (int i = 0; i != a; ++i)
		delete [] m[i];
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