#include <iostream>
#include "header3.h"

using namespace std;

void allocate_mass(int& n, int*& arr)
{
	arr = new int[n];
}

void scan(int& n, int*& arr)
{
	cin >> n;
	cout << "__________" << endl;
	allocate_mass(n, arr);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

int size_determination(int n, int* originalArr)
{
	int k = 1;
	bool flag = true;
	for (int i = 1; i < n; i++)
	{
		flag = true;
		for (int j = 0; j < i; j++)
		{
			if (originalArr[i] == originalArr[j])
			{
				cout << "find repeat" << endl;
				flag = false;
				break;
			}
		}
		if (flag)
		{
			k++;
			cout << "k= " << k << endl;
		}
	}

	return k;
}

void remove_repetitions(int n, int* originalArr, int*& newArr)
{

	int k = 1;
	bool flag = true;
	newArr[0] = originalArr[0];
	for (int i = 1; i < n; i++)
	{
		flag = true;
		for (int j = 0; j < i; j++)
		{
			if (originalArr[i] == originalArr[j])
			{
				cout << "find repeat" << endl;
				flag = false;
				break;
			}
		}
		if (flag)
		{
			newArr[k] = originalArr[i];
			k++;
			cout << "k= " << k << endl;
		}
	}


}


void print(int n, int* arr)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << endl;
}

//void remove repeat(int n,int *arr,)