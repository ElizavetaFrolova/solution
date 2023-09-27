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
private:

	string name;
	string surname;
	string patronymic;
	long long  phoneNmber;
	Date data;

public:
	Students(void);
	Students(string name, string surname, string patronymic, long long phoneNmber, int day, int month, int year);

	void SetName(string _name) { name = _name; }
	void SetSurname(string _surname) { surname = _surname; }
	void SetPatronymic(string _patronymic) { patronymic = _patronymic; }
	void SetPhoneNmber(long long _phoneNmber) { phoneNmber = _phoneNmber; }
	void SetData(int _day, int _month, int _year) { data.day = _day; data.month = _month; data.year = _year; }
	void SetStudents(string _surname, string _name, string _patronymic, long long _phoneNmber, int _day, int _month, int _year);
	void SetRes(string _name, string _surname, string _patronymic, long long _phoneNmber, int _day, int _month, int _year);

	string GetName()const { return name; }
	string GetSurname()const { return surname; }
	string GetPatronymic()const { return patronymic; }
	long long GetPhoneNumber()const { return phoneNmber;}
	int GetDay()const { return data.day; }
	int GetMonth()const { return data.month; }
	int GetYear()const { return data.year; }

	friend ostream& operator <<(ostream& stream, const Students& p);
	Students& operator=(const Students& _str);
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