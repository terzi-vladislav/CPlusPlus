#include <fstream>
#include <string>
#include <iostream>
using namespace std;

void sort(string * arr, int size) {
	for (int j = 1; j < size; ++j) {
		string key = arr[j];
		int i = j - 1;
		while (i >= 0 && arr[i] > key) {
			arr[i + 1] = arr[i];
			--i;
		} 
		arr[i + 1] = key;
	}
}

int main() {
	int size = 0;
	cin >> size;
	string a[size] = {};
	ifstream input("input.txt");
	for (int i = 0; i < size; ++i) {
		input >> a[i];
	}

	sort(a, size);

	ofstream output("output.txt");
	for (int i = 0; i < size; ++i) {
		output << a[i] << endl;
	}

	return 0;
}