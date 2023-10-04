#include <clocale>
#include <iomanip>
#include <iostream>
//#include <cmath>
#include<math.h>

#include "header1.h"

using namespace std;

int main()
{
	Vector<int> IntVec1;
	Vector<int> IntVec2;
	Vector<int> IntVec3;
	bool a,b;
//	double a;
	cout << "enter int vector 1:" << endl;
	cin >> IntVec1;
	cout << "enter int vector 2:" << endl;
	cin >> IntVec2;
	cout << "enter int vector 3:" << endl;
	cin >> IntVec3;
	cout <<"vector 1 :"<< IntVec1 << endl;
	cout << "vector 2 :" << IntVec2 << endl;
	cout << "vector 3 :" << IntVec3 << endl;
//	a = IntVec1.lenght();
	
//	cout << "lenght vector 1" << IntVec1.mod() << endl;

//	cout << "lenght vector 2" << IntVec2.mod() << endl;
//	cout << "lenght vector 3" << IntVec3.mod() << endl;
	a = (IntVec1 == IntVec2);
	b= (IntVec1 != IntVec2);
	cout << "(IntVec1 == IntVec2) :" << a << endl;
	cout << "(IntVec1 != IntVec2) :" << b << endl;
	cout << "vector 1  +  vector 2 = " << IntVec1 + IntVec2 << endl;
	cout << "vector 1  -  vector 2 = " << IntVec1 - IntVec2 << endl;
	cout << "vector 1  *  vector 2 = " << IntVec1 * IntVec2 << endl;
	IntVec3 = IntVec2;
	cout << "vector 3  =  vector 2 = " << IntVec3 << endl;
	
	return 0;
}