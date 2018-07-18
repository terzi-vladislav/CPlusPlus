#include <iostream>
using namespace std;

unsigned strlen(const char *str) {
    unsigned len = 0;
    while (*(str + len))
        len++;
    return len;
}

void strcon(char *to, const char *from) {
    unsigned lento = strlen(to);
    unsigned lenfrom = strlen(from);
    for (int i = 0; i < lenfrom + 1; ++i)
        to[i + lento] = from[i];
    return;
}

int main() {
	char to[] = "string1", from[] = "string2";
	strcon(to, from);
	cout << to;

	return 0;
}