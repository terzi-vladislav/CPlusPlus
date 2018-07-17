#include <iostream>

using namespace std;

int main(){
  char c = '\0';
  char c_prev = '\0';
  while (cin.get(c)){
    if ((c_prev == ' ') && (c != ' ')) {
      cout << ' ';
    }
    if (c != ' ') {
  	  cout << c;
  	}
    c_prev = c;
  }
  return 0;
}