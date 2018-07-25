#include <iostream>

int *bin_sum(int * a, int * b, int n) {
	int *sum = new int[n + 1];
	for (int  i = n - 1; i >= 0; --i) {
		sum[i] = (a[i] + b[i] + sum[i + 1]) / 2;
		sum[i + 1] = ((a[i] + b[i] + sum[i + 1]) % 2);
	}
	return sum;
}

int main() {
	int n = 5;
	int a[5] = {1, 1, 1, 1, 0}, b[5] = {1, 0, 1, 1, 0};

	int *arr = 0;
	arr = bin_sum(a, b, n);

 	for (int i = 0; i < n + 1; ++i)
 		std:: cout << arr[i];

 	return 0;
}