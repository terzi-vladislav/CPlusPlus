#include <cstddef>
#include <cstring>
#include <iostream>
using namespace std;

/* Реализация строкового конструктора, с использованием стандартной библиотеки */

struct String {

	String(const char *str = "") {
		int length = strlen(str);
		this->size = length;
		char * new_str = new char[length + 1];
		strcpy(new_str, str);
		this->str = new_str;
	}

	String(size_t n, char c) {
        char *new_str = new char[n + 1];
        for (int i = 0; i != n; ++i)
            new_str[i] = c;
        this->str = new_str;
        this->size = n;
    }

    char operator[] (int i) {
    	return str[i];
    }

	void append(String &other) {
		int length = size + other.size;
		this->size = length;
		char * new_str = new char[length + 1];
		for (int i = 0; i < strlen(str); ++i)
			new_str[i] = str[i];
		for (int i = strlen(str); i < length; ++i)
			new_str[i] = other.str[i - strlen(str)];
        new_str[length] = '\0';
        delete [] str;
        this->str = new_str;
    }

	~String() {
        delete [] str;
    }

	size_t size;
	char *str;
};

char *resize(char *str, unsigned size, unsigned new_size) {
    char * m;
    m = new char[new_size];
    for (int i = 0; i < new_size; ++i)
        *(m + i) = *(str + i);
    delete [] str;
    return m;
}

char *getline() {
    char *str;
	str = new char[1];
	char c = '\0';
	for(int i = 0; cin.get(c) && c != '\n'; ++i) {
		str[i] = c;
		str = resize(str, i + 1, i + 2);
		str[i + 1] = '\0';
	}
    
    return str;
}

int main() {
	char * str1 = 0;
	str1 = getline();

	char * str2 = 0;
	str2 = getline();

	String st1 = {str1};
	String st2 = {str2};
	st1.append(st2);
	
	for (int i = 0; i < st1.size; ++i)
		cout << st1[i];

	return 0;
}