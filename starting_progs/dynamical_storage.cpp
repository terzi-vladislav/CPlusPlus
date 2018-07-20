#include <iostream>
using namespace std;

int *resize(int *str, unsigned size, unsigned new_size) {
    int * m;
    m = new int[new_size];
    for (int i = 0; i < new_size; ++i)
        *(m + i) = *(str + i);
    delete [] str;
    return m;
}


int main() {
	int * str;
	str = new int[10];
	int size = 0;
	cin >> size;
	for (int i = 0; i < size; ++i) {
		str[i] = i;
		cout << str[i] << " ";
	}

	int new_size = 0;
	cin >> new_size;

	str = resize(str, size, new_size);

	cout << endl;
	for (int i = 0; i < new_size; ++i) {
		cout << str[i] << " ";
	}

	delete [] str;
	str = 0;

	return 0;
}