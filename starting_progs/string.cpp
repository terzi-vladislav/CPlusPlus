#include <iostream>
#include <string> //string functions
using namespace std;

int main() {

	string x;
	getline(cin, x); // end of input id determined by new line entered
	cout << x << endl;

	string s1("hamster "); //constructor
	string s2;
	string s3;

	s2 = s1; //copys s1
	s3.assign(s1); //copys s1

	cout << s1 << s2 << s3 << endl;

	string s4 = "omgwtfbbq";
	cout << s4.at(3) << endl; //getting elements

	for (int x = 0; x < s4.length(); x++) { //length() holds the length of the line
		cout << s4.at(x); //strings are arrays of chars
	}

	string s5("OMG i think i am cool"); 
	cout << s5.substr(5, 7) << endl; //creating a substring

	cout << s1 << ' ' << s5 << endl;

	s1.swap(s5); //swaps strings s1 and s5

	cout << s1 << ' ' << s5 << endl;

	string s6("ham is spam oh yes i am!");

	cout << s6.find("am") << endl; //gives a starting location of the first occurance
	cout << s6.rfind("am") << endl; //gives a last occurance location

	string s7("hi my name is vlad and i like bacon");

	/*cout << s7 << endl;
	s7.erase(15); //erases everything from 15th character til the end*/
	cout << s7 << endl;

	s7.replace(14, 4, "sam"); //replaces from, hom many with what
	cout << s7 << endl;

	s7.insert(14, "lucky "); //inserts a substring into a string
	cout << s7 << endl;

}