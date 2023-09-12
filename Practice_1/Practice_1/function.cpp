#include <iostream>
#include <cmath>
#include "Header.h"

using namespace std;

void scan(int& n, float*& arr)
{
	cin >> n;
	arr = new float[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void print(int n, float* arr)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << endl;
}

void square_root(int n, float*& arr)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > 10)
		{
			arr[i] = sqrt(arr[i]);
		}
	}
}


