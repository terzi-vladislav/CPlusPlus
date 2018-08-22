#include <iostream>
#include <fstream>
using namespace std;

int main() {

	ofstream theFile("someFile.txt");
	cout << "Enter ID, Name, Money" << endl;
	cout << "press Ctrl+Z to quit\n" << endl;

	int id;
	string name;
	double money;

	while (cin >> id >> name >> money) {
		theFile << id << ' ' << name << ' ' << money << endl;
	}

}