#include <iostream>

using namespace std;

int main() {

  int k = 0, a = 0;
  int b = 1;
  int log = 0;

  cin >> k;
  while (k--) {
    cin >> a;
    while (true) {
      if (b == a) {
        cout << log << endl;
        break;
      }
      if (b > a){
        cout << (log - 1) << endl;
        break;
      }
      ++log;
      b *= 2;
    }
    b = 1;
    log = 0;
  }

  return 0;
}