#include <iostream>
#include "Header2.h"

using namespace std;

void scan(int& n, int*& arr)
{
	cout << "enter an even number" << endl;
	cin >> n;
	while (n % 2 != 0)
	{
		cout << "enter a multiple of two" << endl;
		cin >> n;
	}

	arr = new int[n];

	cout << "enter the numbers in the array" << endl;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void switching_places(int n, int* arr)
{

	for (int i = 0; i < n / 2; i++)
	{
		int tmp = arr[i];
		arr[i] = arr[n / 2 + i];
		arr[n / 2 + i] = tmp;
	}
}

void print(int n, int* arr)
{
	cout << "--------------------------------------------------" << endl;
	for (int i = 0; i < n; i++)
		cout << arr[i] << endl;
}


