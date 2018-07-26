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


int main() {
	int size = 0;
	std:: cin >> size;
	int m[size] = {};
	for (int i = 0; i != size; ++i) {
		std::cin >> m[i];
	}

	merge_sort(m, 0, size - 1);
	for (int i = 0; i != size; ++i) {
		std:: cout << m[i] << ' ';
	}

	return 0;
}