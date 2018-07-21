#include <string>
#include <fstream>
using namespace std;

int main() {
	string name, sirname;
	ifstream input("input.txt");
	input >> name >> sirname;

	ofstream output("output.txt");
	output << "Hi, \n" << name << ' ' << sirname << endl;

	return 0;
}