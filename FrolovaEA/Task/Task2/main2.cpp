#include <iostream>
#include "Header2.h"

using namespace std;

int main() {


	int n;
	int* arr;
	scan(n, arr);

	print(n, arr);

	switching_places(n, arr);

	print(n, arr);

	delete[] arr;

}