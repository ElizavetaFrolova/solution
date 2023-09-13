#include <iostream>
#include "Header.h"

using namespace std;

int main() {


	int n;
	float* arr;
	scan(n, arr);
	try {

		print(n, arr);
		square_root(n, arr);
		print(n, arr);
	}
	catch (const char* exl)
	{
		cout << exl << endl;
	}
	delete[] arr;

}