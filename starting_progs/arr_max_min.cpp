#include <iostream>
using namespace std;

int max_elem(int * p, int * q){
	int max = *p;
	for (; p != q; ++p)
		if (*p > max)
			max = *p;

	return max;
}

int min_elem(int * p, int * q){
	int min = *p;
	for (; p != q; ++p)
		if (*p < min)
			min = *p;

	return min;
}

int main(){
	int size = 0;
	cin >> size;
	int arr[size] = {};
	int temp = 0;
	for (int i = 0; i < size; ++i){
		cin >> temp;
		arr[i] = temp;
	}
	cout << "Max element = " << max_elem(arr, arr + size) << endl << "Min element =" << min_elem(arr, arr + size) << endl;

	return 0;
}
