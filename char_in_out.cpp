#include <iostream>

int main()
{
  char c = '\0';

  while (std::cin.get(c)) {
  	if (c != 'a') {
  		std::cout << c << "\n";
  	}
  }
  return 0;
}