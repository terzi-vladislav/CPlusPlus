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

	void append(String &other) {
		int length = strlen(str) + strlen(other);
		this->size = length;
		char * new_str = new char[length + 1];
		for (int i = 0; i < strlen(str); ++i)
			new_str[i] = str[i];
		for (int i = strlen(str); i < length; ++i)
			new_str[i] = other[i];
		delete [] str;
		delete[] other;
		retern new_str;


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

	String str1, str2;
	str1.append(str2);
	cout << str1;


	return 0;
}