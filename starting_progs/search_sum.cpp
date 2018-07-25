#include <iostream>

void merge(int * arr, int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;
	int * L = new int[n1];
	int * R = new int[n2];
	for (int i = 0; i < n1; ++i)
		L[i] = arr[p + i];
	for (int i = 0; i < n2; ++i)
		R[i] = arr[q + i + 1];
	int i = 0;
	int j = 0;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[p + i + j] = L[i];
			i++;
		}
		else {
			arr[p + i + j] = R[j];
			j++;
		}
	}
	if (i == n1)
		for (int k = p + i + j; k <= r; ++k) {
			arr[k] = R[j];
			j++;
		}
	else
		for (int k = p + i + j; k <= r; ++k) {
			arr[k] = L[i];
			i++;
		}
}

void merge_sort(int * arr, int p, int r) {
	if (p < r) {
		int q  = (p + r) / 2;
		merge_sort(arr, p, q);
		merge_sort(arr, q + 1, r);
		merge(arr, p, q, r);
	}
}

bool binary_search(int * arr, int value, int low, int high) {
	int mid = 0;
	while (low <= high) {
		mid = (high + low) / 2;
		if (value == arr[mid])
			return true;
		if (value > arr[mid]) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return false;
}

bool search_sum(int * arr, int size, int value) {
	for (int  i = 0; i < size; ++i)
		if (binary_search(arr, value - arr[i], i + 1, size - 1))
			return true;
	return false;
}

int main() {
	int size = 0;
	std:: cin >> size;
	int arr[size] = {};
	for (int i = 0; i < size; ++i) 
		std:: cin >> arr[i];

	int value = 0;
	std:: cin >> value;

	merge_sort(arr, 0, size - 1);

	for (int i = 0; i < size; ++i)
		std:: cout << arr[i] << " ";
	std:: cout << "\n";

	std:: cout << binary_search(arr, value, 0, size - 1);

 	if (search_sum(arr, size, value)) {
 		std:: cout << "YES\n";
 	} else {
 		std:: cout << "NO\n";
 	}

 	return 0;
}