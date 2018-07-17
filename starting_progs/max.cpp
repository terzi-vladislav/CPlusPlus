#include <iostream>
using namespace std;

bool max_elem(int * p, int * q, int * res) {
	if (p == q)
		return false;
	*res = *p;
	for (; p != q; ++p)
		if (*p > *res)
			*res = *p;
	return true;
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
	int max = 0;
	if (max_elem(arr, arr + size, &max))
		cout << max << endl;
	
	return 0;
}