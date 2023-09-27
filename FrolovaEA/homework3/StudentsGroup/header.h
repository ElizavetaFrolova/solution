#ifndef _HEADER_H
#define _HEADER_H
#include <string>
#include <cstring>
using namespace std;

struct Date
{
	int day;
	int month;
	int year;
};

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

	Students& operator[](int index)const;
	void print();
	void find_Name();
	void find_Surname();
	void find_Patronymic();
	void find_PhoneNmber();
	void find_Data();
	void realloc();
	void AddStudent();
	void DeleteStudent();

};

int cntLines(const string filename);
void allocate_stock(Students*& p, int size);
void fill_sklad(Students*& p, int size, const string filename);

#endif