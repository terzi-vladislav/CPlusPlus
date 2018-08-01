#include <cmath>
#include <time.h>

int random(int a, int b) {
	double delta = b - a;
	int temp = 0;
	delta *= sin(delta);
	delta *= (b - a);
	delta *= sin(clock()) * cos(clock());
	delta *= sin(clock()) * clock() * (b - a);
	temp = std::abs(delta);
	temp %= (b - a);
	temp += a;
	return temp;
}