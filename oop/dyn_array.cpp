#include <iostream>
#include <assert.h>

class CArray {
public:
	CArray(): 
	buffer( 0 ), bufferSize( 1 ), realSize( 0 ) {
		buffer = new double[bufferSize];
	}
	~CArray() {
		delete[] buffer;
	}
	double GetAt( int index ) const {
		assert( index >= 0 && index < realSize && buffer != 0 );
		return buffer[index]; 
	}
	double operator[] ( int index ) {
		return GetAt( index );
	}

	void Add( double element ) {
		if ( realSize == bufferSize )
			grow();
		assert( realSize < bufferSize && buffer != 0);
		buffer[realSize++] = element;
	}
private:
	double* buffer;
	int bufferSize;
	int realSize;

	void grow() {
		int newBufferSize = bufferSize * 2;
		double* newBuffer = new double[newBufferSize];
		for ( int i = 0; i < realSize; ++i )
			newBuffer[i] = buffer[i];
		delete[] buffer;
		buffer = newBuffer;
		bufferSize = newBufferSize;
	}
};

int main() {
	CArray arr;
	int size  = 0;
	std::cin >> size;

	for ( int i = 0; i < size; ++i ) {
		double temp = 0;
		std::cin >> temp;
		arr.Add( temp );
	}

	for ( int i = 0; i < size; ++i ) {
		std::cout << arr[i] << ' ';
	}

	return 0;
}