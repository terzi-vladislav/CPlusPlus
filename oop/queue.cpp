#include <iostream>
#include <assert.h>

class c_queue {
public:
	c_queue(int size) : buffer_size(size), head(0), tail(0) {
		buffer = new int[buffer_size];
	}
	~c_queue() {
		delete [] buffer;
	}
	void enqueue(int a) {
		assert((tail + 1) % buffer_size != head);
		buffer[tail] = a;
		tail = (tail + 1) % buffer_size;
	}
	int deqeueue() {
		assert(head != tail);
		int result = buffer[head];
		head = (head + 1) % buffer_size;
		return result;
	}

	bool is_empty() const {
		return head == tail;
	}
private:
	int * buffer;
	int buffer_size;
	int head;
	int tail;
};

int main() {
	int size = 0;
	std::cin >> size;
	c_queue queue_test(size);
	for (int i = 0; i < size - 1; ++i) {
		int temp = 0;
		std::cin >> temp;
		queue_test.enqueue(temp);
	}

	for (int i = 0; i < size - 1; ++i) {
		std::cout << queue_test.deqeueue();
	}

	return 0;
}