#ifndef _HEADER_H
#define _HEADER_H
#include <string>
#include <cstring>
#include "DateArr.h"

using namespace std;


class Students
{
public:

	string name;
	string surname;
	string patronymic;
	long long  phoneNmber;
	Date data;

public:
	Students(void);
	Students(const string& name, const string& surname, const string& patronymic, long long phoneNmber, int day, int month, int year);
	friend ostream& operator <<(ostream& stream, const Students& p);
	const Students& operator=(const Students& _str);
};

class Group
{
private:

	int size;
	Students* students;
	int max_size;
	int step=10;

public:
	Group(int size, Students* a, int max_size);
	Group(int size, const string filename, int max_size);
	~Group();
	int GetSize() { return size; };

	friend ostream& operator <<(ostream& stream, const Group& p);
	Students& operator[](int index)const;
	Arr find_Name(const string& str);
	Arr find_Surname(const string& str);
	Arr find_Patronymic(const string& str);
	Arr find_Data(int _day,int _month,int _year);
	void realloc();
	void AddStudent(const string& name, const string& surname, const string& patronymic, long long phoneNmber, int day, int month, int year);
	void DeleteStudent(int index);

	int find_PhoneNmber(long long number);
	Students GetStudents(int i) { return students[i]; }

};

int cntLines(const string filename);
void allocate_stock(Students*& p, int size);
void fill_sklad(Students*& p, int size, const string filename);

#endif