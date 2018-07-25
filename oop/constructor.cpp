#include <iostream>
#include <cmath>
using namespace std;

struct Point {
	Point() {
		x = y = 0;
	}
	Point(double x, double y) {
		this->x = x;
		this->y = y;
	}
	double x;
	double y;
};

/* could be written in another way:
struct Point {
	Point(double x = 0, double y = 0)
		: x(x), y(y)
	{}
	double x;
	double y;
} zeros are values by default*/

int main() {
	Point p1;
	Point p2(3, 7);

	cout << p1.x << p1.y << endl << p2.x << p2.y << endl;

	return 0;
}