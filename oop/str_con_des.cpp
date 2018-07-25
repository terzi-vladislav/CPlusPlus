#include <iostream>
#include <cstddef> 
#include <cstring>
using namespace std;

struct String {
	String(size_t n, char c) {
        char *new_str = new char[n + 1];
        for (int i = 0; i != n; ++i)
            new_str[i] = c;
        this->str = new_str;
        this->size = n;
    }

	~String() {
        delete [] str;
    }
    
	size_t size;
	char *str;
};

int main() {
	char * str = 0;
	int n = 0;
	char c = '\0';
	cin >> n >> c;

	String st1 = {n, c};
	cout << st1 << endl;

	return 0;
}