#include <iostream>
using namespace std;

bool contain_test(int * arr, int size, int value){
	for (int i = 0; i != size; ++i)
		if (arr[i] == value)
			return true;
	return false;
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
	int value = 0;
	cin >> value;
	if (contain_test(arr, size, value))
		cout << "YES" << endl;
	else
		cout << "NO";

	return 0;
}