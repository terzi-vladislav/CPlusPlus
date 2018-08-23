#include <iostream>
using namespace std;

class File {
public:
	void write( char const * str );
	...
};

class FormatFile : public File {
	void whrite( int i );
	void whrite( double d );
	using File::whrite;
	...
};

int main( ) {
	//okay to use all of of the write functions with derived class from the base class
}