#include <iostream>
using namespace std;

unsigned strlen(const char *str) {
    unsigned len = 0;
    while (*(str + len))
        len++;
    return len;
}

bool test(const char *text, const char *pattern, unsigned lenpattern, int i) {
    for (int j = i; j < i + lenpattern; ++j)
        if (text[j] != pattern[j - i])
            return false;
    return true;
}

int strstr(const char *text, const char *pattern) {
    unsigned lentext = strlen(text);
    unsigned lenpattern = strlen(pattern);
    if (lentext < lenpattern)
        return -1;
    if (lenpattern == 0)
        return 0;
    for (int i = 0; i <= lentext - lenpattern; ++i) {
        if (test(text, pattern, lenpattern, i))
            return i;
    }
    return -1;
}

int main() {
    char text[] = "baaa", pattern[] = "aaa";
    cout << strstr(text, pattern);

    return 0;
}