#include <iostream>
using namespace std;

template <class T>
class Whatever {
public:
	Whatever(T x) {
		cout << x << " is not a charachter" << endl;
	}
};

template<>
class Whatever<char> {
public:
	Whatever(char x) {
		cout << x << " is indeed a character" << endl;
	}
};

int main() {
	Whatever<int> wo1(1);
	Whatever<double> wo2(2.71);
	Whatever<char> wo3('w');

}