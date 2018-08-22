#include <iostream>
#include <cmath>
using namespace std;

struct Point {
	double x;
	double y;

	void shift(double x, double y) {
		this->x += x;
		this->y += y;
	}
};


int main() {
	double x1, y1;
	cout << "Input coordinates of a point" << endl;
	cin >> x1 >> y1;

	double dx, dy;
	cout << "Input shift on x and y" << endl;
	cin >> dx >> dy;

	Point p1 = {x1, y1};
	p1.shift(dx, dy);

	cout << p1.x << ' ' << p1.y << endl;

	return 0;
}