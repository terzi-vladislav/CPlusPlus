#include <iostream>
using namespace std;

int ** create_array2d(int a, int b) {
	int ** m = new int *[a];
	m[0] = new int[a * b];
	for (int i = 1; i != a; ++i)
		m[i] = m[i - 1] + b;
	return m;
}

void free_array2d(const int * const * m, int a, int b) {
	delete [] m[0];
	delete [] m;
}

int ** transpose(const int * const * m, unsigned rows, unsigned cols) {
    int ** arr = new int * [cols];
    for(int i = 0; i < cols; ++i) {
        arr[i] = new int[rows];
        for(int j = 0; j < rows; ++j) {
            arr[i][j] = m[j][i];
        }
    }
    free_array2d(m, rows, cols);

	m = 0;
    return arr;
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

	arr = transpose(arr, a, b);

	for (int i = 0; i < b; ++i) {
		for (int j = 0; j < a; ++j) {
			cout << arr [i][j] << ' ';
		}
		cout << endl;
	}

	return 0;
}