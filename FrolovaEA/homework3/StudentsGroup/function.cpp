#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <iomanip>
#include "header.h"
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

Students::Students(string name, string surname, string patronymic, long long phoneNmber, int day, int month, int year)
{
    this->name = name;
    this->surname = surname;
    this->patronymic = patronymic;
    this->phoneNmber = phoneNmber;
    this->data.day = day;
    this->data.month = month;
    this->data.year = year;

}

void Students::SetStudents(string _surname, string _name, string _patronymic, long long _phoneNmber, int _day, int _month, int _year)
{
    surname = _surname;
    name = _name;
    patronymic = _patronymic;
    phoneNmber = _phoneNmber;
    data.day = _day;
    data.month = _month;
    data.year = _year;
}

Students& Students::operator=(const Students& _str)
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

void Students::SetRes(string _surname, string _name, string _patronymic, long long _phoneNmber, int _day, int _month, int _year)
{
    name = _name;
    surname = _surname;
    patronymic = _patronymic;
    phoneNmber = _phoneNmber;
    data.day = _day;
    data.month = _month;
    data.year = _year;

}

ostream& operator <<(ostream& stream, const Students& p)
{
    stream << p.surname << " " << p.name << " " << p.patronymic << " " << p.phoneNmber << " " << p.data.day << "/" << p.data.month << "/" << p.data.year << endl;
    return stream;
}

Group::Group(int size, Students* a, int max_size)
{
    this->size = size;
    students = a;
    this->max_size = max_size;
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

void Group::print()
{
    for (int i = 0; i < size; i++)
        cout << i+1 << ":" << students[i] << endl;
}

void Group::find_Name()
{
    string str;
    cout << "enter name: ";
    cin >> str;
    cout << endl;
    int k = 0;
    for (int i = 0; i < size; i++)
    {
        if (students[i].GetName() == str) {
            cout << students[i].GetSurname() << "\t" << students[i].GetName() << "\t" << students[i].GetPatronymic() << "\t" << students[i].GetPhoneNumber() << "\t";
            cout << setw(2) << setfill('0') << students[i].GetDay() << "." << setw(2) << setfill('0') << students[i].GetMonth() << "." << students[i].GetYear() << endl;
            k++;
        }

    }
    if (k == 0) {
        cout << "name not found" << endl;
    }
}

void Group::find_Surname()
{
    string str;
    cout << "enter surname: ";
    cin >> str;
    cout << endl;
    int k = 0;
    for (int i = 0; i < size; i++)
    {
        if (students[i].GetSurname() == str) {
            cout << students[i].GetSurname() << "\t" << students[i].GetName() << "\t" << students[i].GetPatronymic() << "\t" << students[i].GetPhoneNumber() << "\t";
            cout << setw(2) << setfill('0') << students[i].GetDay() << "." << setw(2) << setfill('0') << students[i].GetMonth() << "." << students[i].GetYear() << endl;
            k++;
        }

    }
    if (k == 0) {
        cout << "name not found" << endl;
    }
}

void Group::find_Patronymic()
{
    string str;
    cout << "enter patronymic: ";
    cin >> str;
    cout << endl;
    int k = 0;
    for (int i = 0; i < size; i++)
    {
        if (students[i].GetPatronymic() == str) {
            cout << students[i].GetSurname() << "\t" << students[i].GetName() << "\t" << students[i].GetPatronymic() << "\t" << students[i].GetPhoneNumber() << "\t";
            cout << setw(2) << setfill('0') << students[i].GetDay() << "." << setw(2) << setfill('0') << students[i].GetMonth() << "." << students[i].GetYear() << endl;
            k++;
        }

    }
    if (k == 0) {
        cout << "name not found" << endl;
    }
}

void Group::find_PhoneNmber()
{
    long long str;
    cout << "enter phoneNmber: ";
    cin >> str;
    cout << endl;
    int k = 0;
    for (int i = 0; i < size; i++)
    {
        if (students[i].GetPhoneNumber() == str) {
            cout << students[i].GetSurname() << "\t" << students[i].GetName() << "\t" << students[i].GetPatronymic() << "\t" << students[i].GetPhoneNumber() << "\t";
            cout << setw(2) << setfill('0') << students[i].GetDay() << "." << setw(2) << setfill('0') << students[i].GetMonth() << "." << students[i].GetYear() << endl;
            k++;
        }

    }
    if (k == 0) {
        cout << "name not found" << endl;
    }
}

void Group::find_Data()
{
    int _day;
    int _month;
    int _year;
    cout << "enter day: ";
    cin >> _day;
    cout << endl;
    cout << "enter month: ";
    cin >> _month;
    cout << endl;
    cout << "enter year: ";
    cin >> _year;
    cout << endl;
    int k = 0;
    for (int i = 0; i < size; i++)
    {
        if ((students[i].GetDay() == _day) && (students[i].GetMonth() == _month) && (students[i].GetYear() == _year)) {
            cout << students[i].GetSurname() << "\t" << students[i].GetName() << "\t" << students[i].GetPatronymic() << "\t" << students[i].GetPhoneNumber() << "\t";
            cout << setw(2) << setfill('0') << students[i].GetDay() << "." << setw(2) << setfill('0') << students[i].GetMonth() << "." << students[i].GetYear() << endl;
            k++;
        }

    }
    if (k == 0) {
        cout << "name not found" << endl;
    }
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

void Group::AddStudent()
{
    if (size == max_size) {
        realloc();
    }
    string _name,_surname,_patronymic;
    long long  _phoneNmber;
    int _day, _month, _year;

    cout << "enter name: ";
    cin >> _name;
    cout << endl;
    cout << "enter sourname: ";
    cin >> _surname;
    cout << endl;
    cout << "enter patronymic: ";
    cin >> _patronymic;
    cout << endl;
    cout << "enter phoneNmber: ";
    cin >> _phoneNmber;
    cout << endl;
    cout << "enter day: ";
    cin >> _day;
    cout << endl;
    cout << "enter month: ";
    cin >> _month;
    cout << endl;
    cout << "enter year: ";
    cin >> _year;
    cout << endl;
    students[size].SetRes(_name, _surname, _patronymic, _phoneNmber, _day, _month, _year);
    size++;
}

void Group::DeleteStudent()
{
    int index;
    print();
    cout << "enter index: ";
    cin >> index;
    while ((index < 1) || (index > size))
    {
        cout << "enter index: ";
        cin >> index;
    }
    int pocition = index - 1;
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

int cntLines(const string filename)
{

    string line;
    int f = 0;
    ifstream file(filename); // �������� ���� ��� ������

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
    ifstream file(filename); // �������� ���� ��� ������
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
                        p[j].SetRes(_surname, _name, _patronymic, _phoneNmber, _day, _month, _year);
                    }


                }
                flag = 0;
                j++;
            }

        }




    }

    file.close();     // ��������� ����


}