#include <iostream>
using namespace std;

int main() {

	try{
		int momAge = 30;
		int sonAge = 34;

		if (sonAge > momAge) {
			throw 99;
		}
	} catch(...){ //general catch function 
		cout << "son cannot be older then mom" << endl;
	}
}