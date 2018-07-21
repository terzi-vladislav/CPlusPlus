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
};

double length(Segment * s) {
	double dx = s->p1.x - s->p2.x;
	double dy = s->p1.y - s->p2.y;
	return sqrt(dx * dx + dy * dy);
}

int main() {
	double x1, x2, y1, y2;
	cout << "Введите координаты двух точек:" << endl;
	cin >> x1 >> y1 >> x2 >> y2;
	Point p1 = {x1, y1};
	Point p2 = {x2, y2};
	Segment s = {p1, p2};
	cout << length(&s);

	return 0;
}