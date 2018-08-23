#include <iostream>
using namespace std;

class Vector2D {
public:
	Vector2D( double x, double y ) : x( x ), y( y ) {}

	Vector2D mult(double d) const {
		return Vector2D( x * d, y * d );
	}

	double mult( Vector2D const& p ) const {
		return x * p.x + y * p.y;
	}

private:
	double x, y;
};

int main( ) {
	Vector2D p(1, 2);
	Vector2D q = p.mult( 10 );
	double vectorMult = p.mult(q);

	cout << vectorMult << endl;
}