#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <iomanip>
#include "header.h"
#include "DateArr.h"

using namespace std;

Students::Students()
{
    name = "";
    surname = "";
    patronymic = "";
    phoneNmber = 0;
    data.day = 0;
    data.month = 0;
    data.year = 0;
}

Students::Students(const string& name, const string& surname, const string& patronymic, long long phoneNmber, int day, int month, int year)
{
    this->name = name;
    this->surname = surname;
    this->patronymic = patronymic;
    this->phoneNmber = phoneNmber;
    this->data.day = day;
    this->data.month = month;
    this->data.year = year;

}

const Students& Students::operator=(const Students& _str)
{
    name = _str.name;
    surname = _str.surname;
    patronymic = _str.patronymic;
    phoneNmber = _str.phoneNmber;
    data.day = _str.data.day;
    data.month = _str.data.month;
    data.year = _str.data.year;
    return *this;
}


ostream& operator <<(ostream& stream, const Students& p)
{
    stream << p.surname << " " << p.name << " " << p.patronymic << " " << p.phoneNmber
        << " " << setw(2) << setfill('0') << p.data.day << "/" << setw(2) << setfill('0') << p.data.month << "/" << p.data.year << endl;
    return stream;
}

Group::Group(int size, Students* a, int max_size)
{
    this->size = size;
    students = a;
    this->max_size = max_size;
}

Group::Group(int size, const string filename, int max_size)
{
    this->size = size;
    this->max_size = max_size;
    allocate_stock(students, size);
    fill_sklad(students, size,filename);
}

Group::~Group()
{
    delete[] students;
}

Students& Group::operator[](int index) const
{
    if (index < 0 || index >= max_size) {
        throw"error";
    }
    return students[index];
}
/*
void Group::print()
{
    for (int i = 0; i < size; i++)
        cout << i+1 << ":" << students[i] << endl;
}
*/

Arr Group::find_Name(const string& str)
{
    int k = 0;
    for (int i = 0; i < size; i++)
    {
        if (students[i].name == str) {
            k++;
        }
    }
    Arr index(k);
    int num = 0;
    for (int i = 0; i < size; i++)
    {
        if (students[i].name == str) {
            index.arr[num] = i;
            num++;
        }
    }
    return index;
}

Arr Group::find_Surname(const string& str)
{
    int k = 0;
    for (int i = 0; i < size; i++)
    {
        if (students[i].surname == str) {
            k++;
        }
    }
    Arr index(k);
    int num = 0;
    for (int i = 0; i < size; i++)
    {
        if (students[i].surname == str) {
            index.arr[num] = i;
            num++;
        }
    }
    return index;
}

Arr Group::find_Patronymic(const string& str)
{
    int k = 0;
    for (int i = 0; i < size; i++)
    {
        if (students[i].patronymic == str) {
            k++;
        }
    }
    Arr index(k);
    int num = 0;
    for (int i = 0; i < size; i++)
    {
        if (students[i].patronymic == str) {
            index.arr[num] = i;
            num++;
        }
    }
    return index;
}

Arr Group::find_Data(int _day, int _month, int _year)
{
   int k = 0;
    for (int i = 0; i < size; i++)
    {
        if ((students[i].data.day == _day)&& (students[i].data.month == _month) && (students[i].data.year == _year)) {
            k++;
        }
    }
    Arr index(k);
    int num = 0;
    for (int i = 0; i < size; i++)
    {
        if ((students[i].data.day == _day) && (students[i].data.month == _month) && (students[i].data.year == _year)) {
            index.arr[num] = i;
            num++;
        }
    }
    return index;
}

void Group::realloc()
{
    max_size += step;
    Students* tmp = new Students[max_size];
    for (int i = 0; i < size; i++)
    {
        tmp[i] = students[i];
    }
    delete[] students;
    students = tmp;
}

void Group::AddStudent(const string& _name, const string& _surname, const string& _patronymic, long long _phoneNmber, int _day, int _month, int _year)
{
    if (size == max_size) {
        realloc();
    }
    students[size].name = _name;
    students[size].surname = _surname;
    students[size].patronymic = _patronymic;
    students[size].phoneNmber = _phoneNmber;
    students[size].data.day = _day;
    students[size].data.month = _month;
    students[size].data.year = _year;
    size++;
}

void Group::DeleteStudent(int index)
{
    int pocition = index ;
    Students* tmp=new Students[max_size];
    for (int i = 0; i < pocition; i++)
    {
        tmp[i] = students[i];
    }
    for (int i = pocition; i < size-1; i++)
    {
        tmp[i] = students[i+1];
    }
    size--;
    delete[] students;
    students = tmp;
}

int Group::find_PhoneNmber(long long number)
{
    int k = -1;
    for (int i = 0; i < size; i++)
    {
        if (students[i].phoneNmber == number) {
            k=i;
        }
    }
    return k;
}

ostream& operator<<(ostream& stream, const Group& p)
{
    for(int i=0;i<p.size;i++)
    stream <<i<<" : "<<p.students[i] << endl;
    return stream;
}

int cntLines(const string filename)
{

    string line;
    int f = 0;
    ifstream file(filename); // окрываем файл для чтения

    if (!file.is_open())
        throw "File open error";

    if (file.is_open())
    {
        while (getline(file, line))
        {
            //			            cout << line << endl;
            f++;
        }
    }
    return f;

}

void allocate_stock(Students*& p, int size)
{
    p = new Students[size];
}

void fill_sklad(Students*& p, int size, const string filename)
{
    string line;
    char str[200];
    char* istr;
    ifstream file(filename); // окрываем файл для чтения
    int j = 0, flag = 0;

    if (!file.is_open())
        throw "File open error";

    if (file.is_open())
    {
        while (j != size) {

            while (getline(file, line))
            {
                string _name = " ";
                string _surname = " ";
                string _patronymic = " ";
                long long  _phoneNmber = 0;
                int _day = 0;
                int _month = 0;
                int _year = 0;
                strcpy(str, line.c_str());
                istr = strtok(str, ";/");
                flag++;
                if (flag == 1) {
                    _surname = string(istr);
                //    cout << _surname << endl;
                }
                while (istr != NULL)
                {
                    istr = strtok(NULL, ";/");
                    flag++;

                    if (flag == 2) {
                        _name = string(istr);
                    //    cout << _name << endl;
                    }

                    if (flag == 3) {
                        _patronymic = string(istr);
                    //    cout << _patronymic << endl;
                    }

                    if (flag == 4) {
                        _phoneNmber = atoll(istr);
                    //    cout << _phoneNmber << endl;
                    }

                    if (flag == 5) {
                        _day = atoi(istr);
                    //    cout << _day << endl;
                    }

                    if (flag == 6) {
                        _month = atoi(istr);
                    //    cout << _month << endl;
                    }

                    if (flag == 7) {
                        _year = atoi(istr);
                    //    cout << _year << endl;
                        p[j].name = _name;
                        p[j].surname = _surname;
                        p[j].patronymic = _patronymic;
                        p[j].phoneNmber = _phoneNmber;
                        p[j].data.day = _day;
                        p[j].data.month = _month;
                        p[j].data.year = _year;
                        
                    }


                }
                flag = 0;
                j++;
            }

        }




    }

    file.close();     // закрываем файл


}
