#include <iostream>
#include <stdlib.h>
//Процедура обменя местами элементов-------------------------------------------------------------
void change(int * arr, int index_1, int index_2) {
	int temp = arr[index_1];
	arr[index_1] = arr[index_2];
	arr[index_2] = temp;
}
//Функция разбиения массива с использованием рандомного опорного элемента------------------------
int rand_partion(int * arr, int low, int high) {
	int value = arr[high];
	int i = low - 1;
	for (int j = low; j < high; ++j)
		if (arr[j] <= value) {
			i++;
			change(arr, i, j);
		}
	change(arr, i + 1, high);
	return i + 1;
}
//Быстрая сортировка-------------------------------------------------------------------------------
void quick_sort(int * arr, int low, int high) {
	if (low < high) {
		int flag = rand_partion(arr, low, high);
		quick_sort(arr, low, flag - 1);
		quick_sort(arr, flag + 1, high);
	}
}
//Основная функция---------------------------------------------------------------------------------
int main() {
	int size = 0;
	std:: cin >> size;
	int arr[size] = {};
	for (int i = 0; i != size; ++i)
		std::cin >> arr[i];

	quick_sort(arr, 0, size - 1);

	for (int i = 0; i != size; ++i)
		std::cout << arr[i] << ' ';
	std::cout << "\n";

	return 0;
}