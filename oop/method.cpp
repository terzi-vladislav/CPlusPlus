#include <iostream>
#include <cmath>
using namespace std;

struct Point {
	double x;
	double y;
};

struct Segment {
	Point p1;
	Point p2;
	double length() {
		double dx = p1.x - p2.x;
		double dy = p1.y - p2.y;
		return sqrt(dx * dx + dy * dy);
	}
};


int main() {
	double x1, x2, y1, y2;
	cout << "Input coordinates of two points" << endl;
	cin >> x1 >> y1 >> x2 >> y2;
	Segment s = {{x1, y1}, {x2, y2}};
	cout << s.length() << endl;

	return 0;
}