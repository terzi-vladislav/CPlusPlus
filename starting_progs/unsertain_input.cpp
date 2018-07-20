#include <iostream>
using namespace std;

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
	char * str = 0;
	str = getline();
	cout << str << endl;

	return 0;
}