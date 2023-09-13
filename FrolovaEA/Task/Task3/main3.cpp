#include <iostream>
#include "Header3.h"

using namespace std;

int main() {


	int n, a;
	int* arr1;
	int* arr2;
	scan(n, arr1);


	print(n, arr1);
	a = size_determination(n, arr1);
	cout << a << endl;
	allocate_mass(a, arr2);
	remove_repetitions(n, arr1, arr2);
	print(a, arr2);

	delete[] arr2;
	delete[] arr1;


}