#include <iostream>
#include <cmath>
#include "Header.h"

using namespace std;

int main()
{
	Vector a(1, 2, 3);
	Vector b(1, 2, 3);
	Vector c(0,0,0);
	float g;
//	cout << a << endl;
//	cout << b << endl;
//	c = a - b;
//	cout << c << endl;

//	g = a * b;
//	cout << g << endl;

//	cout << a.vectorLength() << endl;

	cout << a.cosineOfTheAngleBetweenVectors(b) << endl;


}