#include <iostream>
//Возврат индекса родителя узла--------------------------------------------------------------------
int parent(int i) {
	return i / 2;
}
//Возварат левого дочернего узла-------------------------------------------------------------------
int left(int i) {
	return (2 * i + 1);
}
//Возврат правого дочернего узла-------------------------------------------------------------------
int right(int i) {
	return (2 * i + 2);
}
//Поддержка свойства пирамиды----------------------------------------------------------------------
void max_heapify(int * arr, int size, int i) {
	int l = left(i);
	int r = right(i);
	int largest = 0;
	if (l < size && arr[l] > arr[i])
		largest = l;
	else largest = i;
	if (r < size && arr[r] > arr[largest])
		largest = r;
	if (largest != i) {
		arr[i] += arr[largest];
		arr[largest] = arr[i] - arr[largest];
		arr[i] -= arr[largest];
		max_heapify(arr, size, largest);
	}
}
//Построение пирамиды------------------------------------------------------------------------------
void build_max_heap(int * arr, int size) {
	for (int i = size / 2; i >= 0; --i) {
		max_heapify(arr, size, i);
	}
}
//Пирамидальная сортировка-------------------------------------------------------------------------
void heap_sort(int * arr, int size) {
	build_max_heap(arr, size);
	for (int i = size - 1; i >= 0; --i) {
		arr[i] += arr[0];
		arr[0] = arr[i] - arr[0];
		arr[i] -= arr[0];
		size -= 1;
		max_heapify(arr, size, 0);
	}
}
//Основная функция---------------------------------------------------------------------------------
int main() {
	int size = 0;
	std:: cin >> size;
	int arr[size] = {};
	for (int i = 0; i != size; ++i)
		std::cin >> arr[i];

	heap_sort(arr, size);

	for (int i = 0; i != size; ++i)
		std::cout << arr[i] << ' ';
	std::cout << "\n";

	return 0;
}