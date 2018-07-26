#include <iostream>

int merge_inversions(int * arr, int p, int q, int r) {
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
	int inversions = 0;
	bool counted = false;
	while (i < n1 && j < n2) {
		if (counted == false && R[j] < L[i]) {
			inversions += n1 - i;
			counted = true;
		}
		if (L[i] <= R[j]) {
			arr[p + i + j] = L[i];
			i++;
		}
		else {
			arr[p + i + j] = R[j];
			j++;
			counted = false;
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
	return inversions;
}

int count_inversions(int * arr, int p, int r) {
	int inversions = 0;
	if (p < r) {
		int q  = (p + r) / 2;
		inversions += count_inversions(arr, p, q);
		inversions += count_inversions(arr, q + 1, r);
		inversions += merge_inversions(arr, p, q, r);
	}
	return inversions;
}


int main() {
	int size = 0;
	std:: cin >> size;
	int m[size] = {};
	for (int i = 0; i != size; ++i) {
		std::cin >> m[i];
	}

	int inversions = 0;
	inversions = count_inversions(m, 0, size - 1);

	for (int i = 0; i != size; ++i) {
		std:: cout << m[i] << ' ';
	}

	std:: cout << "\n" << inversions;

	return 0;
}