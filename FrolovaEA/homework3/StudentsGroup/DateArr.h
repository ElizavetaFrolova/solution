#ifndef _DATEARR_H
#define _DATEARR_H
#include <string>
#include <cstring>
#include "header.h"

using namespace std;

struct Date
{

	int day;
	int month;
	int year;

};

class Arr
{
public:

	int* arr;
	int number;

	Arr();
	Arr(int number);
	~Arr();
	const Arr& operator=(const Arr& _str);

};

void allocate_arr(int*& p, int size);

#endif