#include <iostream>

struct  node {
	int key;
	node * next;
	node * prev;

	node() : key(0), next(0), prev(0) {}
};

node * init(int a) {
	node * new_node;
	new_node = new node();

	new_node->key = a;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

node * add_elem(node * node1, int value) {
	node * temp;
	node * p;
	temp = new node();
	p = node1->next;
	node1->next = temp;
	temp->key = value;
	temp->next = p;
	temp->prev = node1;
	if (p != NULL) {
		p->prev = temp;
	}
	return temp;
}

node * del_elem(node * node1) {
	node * prev;
	node * next;
	prev = node1->prev;
	next = node1->next;
	if (prev != NULL) {
		prev->next = node1->next;
	}
	if (next != NULL) {
		next->prev = node1->prev;
	}
	delete node1;
	return prev;
}

int main() {
	int size = 0;
	std::cin >> size;
	int first_key = 0;
	std::cin >> first_key;
	node * list1 = 0;
	*list1 = init(first_key)
	node * p;
	p = list1;
	for (int i = 1; i < size; ++i) {
		int temp_key = 0;
		std::cin >> temp_key;
		add_elem(p, temp_key);
		p = p->next;
	}

	return 0;
}