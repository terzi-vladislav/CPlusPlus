#include <iostream>
using namespace std;

void rotate(int * a, unsigned size, int shift) {

	shift %= size;
	int first = 0;

	for (int j = 0; j < shift; ++j){
		first = *a;
		for (int i = 0; i < size; ++i){
			a[i] = a[i + 1];
		}
		a[size - 1] = first;
	}
	return;
}

int main(){
	int a[5] = {1, 2, 3, 4, 5};
	int shift = 0;
	cin >> shift;
	rotate(a, 5, shift);
	int i = 0;
	while(i < 5){
		cout << a[i];
		i++;
	}


	return 0;
}