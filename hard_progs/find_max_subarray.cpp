#include <iostream>

struct index_sum {
	int low;
	int high;
	int sum;
};

int max(int a, int b) {
	return (a > b) ? a : b;
}

index_sum find_max_crossing_subarray(int * arr, int low, int mid, int high) {
	int left_sum = -10000;
	int max_left = 0;
	int sum = 0;
	for (int i = mid; i >= low; --i) {
		sum += arr[i];
		if (sum > left_sum) {
			left_sum = sum;
			max_left = i;
		}
	}
	int right_sum = -10000;
	int max_right = 0;
	sum = 0;
	for (int i = mid + 1; i <= high; ++i) {
		sum += arr[i];
		if (sum > right_sum) {
			right_sum = sum;
			max_right = i;
		}
	}
	index_sum isum = {max_left, max_right, left_sum + right_sum};
	return isum;
}

index_sum find_max_subarray(int * arr, int low, int high) {
	if (high == low) {
		index_sum isum = {low, high, arr[low]};
		return isum;
	}
	else {
		int mid = (low + high) / 2;
		index_sum ileft_sum = find_max_subarray(arr, low, mid);
		index_sum iright_sum = find_max_subarray(arr, mid + 1, high);
		index_sum icross_sum = find_max_crossing_subarray(arr, low, mid, high);
		if (ileft_sum.sum >= iright_sum.sum && ileft_sum.sum >= icross_sum.sum) 
			return ileft_sum;
		else if (iright_sum.sum >= icross_sum.sum)
			return iright_sum;
		return icross_sum;
	}
}

int main() {
	int size = 0;
	std:: cin >> size;
	int arr[size] = {};
	for (int i = 0; i != size; ++i) {
		std::cin >> arr[i];
	}

	index_sum isum_max = find_max_subarray(arr, 0, size - 1);

	std:: cout << isum_max.low << " " << isum_max.high << " " << isum_max.sum << "\n";

	return 0;
}