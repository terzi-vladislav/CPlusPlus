#include <iostream>
#include <fstream>
using namespace std;

int main() {

	ofstream randomFile("tuna.docx "); //tuna is now assosiated with randomFile object

	if (randomFile.is_open()) {
		cout << "file is open" << endl;
		randomFile << "I love tuna and tuna loves me!\n"; //outputting text into tuna file
	} else {
		cout << "file is not opened" << endl; 
	}

	randomFile.close(); 
} 