#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <iomanip>
#include "header.h"
#include "DateArr.h"

using namespace std;

void allocate_arr(int*& p, int size)
{
	p = new int[size];
}

Arr::Arr()
{
	number = 0;
	arr = NULL;
}

Arr::Arr(int number)
{
	this->number = number;
	arr = new int[number];
}

Arr::~Arr()
{
	delete[] arr;
}

const Arr& Arr::operator=(const Arr& _str)
{
	if (this != &_str)
	{
		if (number != _str.number)
		{
			delete[] arr;
			number = _str.number;
			arr = new int[number];
		}
		for (int i = 0; i < number; ++i)
			arr[i] = _str.arr[i];
	}
	return *this;
}