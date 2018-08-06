#include <iostream>
#include <assert.h>
//Элемент двусвязного списка с целочисленным ключом------------------------------------------------
struct cnode {
	int data;
	cnode* next;
	cnode* prev;

	cnode() : data(0), next(0), prev(0) {}	
};
//Поиск по связанному списку, в худшем случае работа за O(n)---------------------------------------
cnode* search(cnode* head, int a) {
	cnode* current = head;
	while(current != 0) {
		if (current->data == a)
			return current;
		current = current->next;
	}
	return 0;
}
//Вставка элемента после текущего------------------------------------------------------------------
cnode* insert_after (cnode* node, int a) {
	assert(node != 0);
	cnode* new_node = new cnode();
	new_node->data = a;
	new_node->next = node->next;
	new_node->prev = node;
	if (node->next != 0) {
		node->next->prev = new_node;
	}
	node->next = new_node;
	return new_node;
}
//Удаление элемента--------------------------------------------------------------------------------
void delete_at(cnode* node) {
	assert (node != 0);
	if (node->next != 0) {
		node->next->prev = node->prev;
	}
	if (node->prev != 0) {
		node->prev->next = node->next;
	}
	delete node;
}
//Объединение двух двусвязанных списков в один-----------------------------------------------------
cnode* unity(cnode* head1, cnode* head2) {
	if (head1 == 0) {
		return head2;
	}
	if (head2 == 0) {
		return head1;
	}
	cnode* tail = head1;
	while (tail->next != 0) {
		tail = tail->next;
	}
	tail->next = head2;
	return head1;
}
//Основная функция
int main() {
	cnode list_1;
	cnode * list1;
	list1 = &list_1;
	int size = 0;
	std::cin >> size;
	cnode * p;
	p = list1;
	for (int i = 0; i < size; ++i) {
		int value = 0;
		std::cin >> value;
		insert_after(p, value);
		p = p->next;
	}

	cnode list_2;
	cnode * list2;
	list2 = &list_2;
	p = list2;
	for (int i = 0; i < size; ++i) {
		int value = 0;
		std::cin >> value;
		insert_after(p, value);
		p = p->next;
	}
	unity(list1, list2->next);

	p = list1->next;
	for (int i = 0; i < size * 2; ++i) {
		std::cout << p->data << ' ';
		p = p->next;
	}

	return 0;
}