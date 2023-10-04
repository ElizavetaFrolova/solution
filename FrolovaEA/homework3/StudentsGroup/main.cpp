#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <iomanip>

#include "header.h"
#include "DateArr.h"

using namespace std;

int main()
{

    int size = cntLines("students.txt");

    cout << size << endl;

	Group StudGroup(size, "students.txt", size);

    cout<<StudGroup<<endl;

	int level1{}, level0{};
	do {
		cout << "search by first name, last name, patronymic, phone number, date of birth: " << endl;
		cout << "1: search by first name" << endl;
		cout << "2: search by sourname" << endl;
		cout << "3: search by patronymic" << endl;
		cout << "4: search by phone number" << endl;
		cout << "5: search by date of birth" << endl;
		cout << "6: show students" << endl;
		cout << "7: add student" << endl;
		cout << "8: delete student" << endl;
		cout << "9: exit" << endl;
		cout << "Choose: ";
		cin >> level1;
		if (!cin) {
			cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "ERROR. Please enter numbers only: 1 - 9" << endl;
		}
		switch (level1) {
		case 1:
		{
			string str;
			cout << "enter name: ";
			cin >> str;
			cout << endl;
			Arr index = StudGroup.find_Name(str);
			if (index.number == 0)
				cout << "name not found" << endl;
			if (index.number != 0)
			{
				for (int i = 0; i < index.number; i++)
				{
					cout<<StudGroup.GetStudents(index.arr[i]) << endl;
				}
			}

		}	
			break;
		case 2:
		{
			string str;
			cout << "enter sourname: ";
			cin >> str;
			cout << endl;
			Arr index = StudGroup.find_Surname(str);
			if (index.number == 0)
				cout << "sourname not found" << endl;
			if (index.number != 0)
			{
				for (int i = 0; i < index.number; i++)
				{
					cout << StudGroup.GetStudents(index.arr[i]) << endl;
				}
			}
		}

			break;
		case 3:
		{
			string str;
			cout << "enter patronymic: ";
			cin >> str;
			cout << endl;
			Arr index = StudGroup.find_Patronymic(str);
			if (index.number == 0)
				cout << "patronumic not found" << endl;
			if (index.number != 0)
			{
				for (int i = 0; i < index.number; i++)
				{
					cout << StudGroup.GetStudents(index.arr[i]) << endl;
				}
			}
		}
			break;
		case 4:
		{
			long long str;
			cout << "enter phoneNmber: ";
			cin >> str;
			cout << endl;
			int k = 0;

			k = StudGroup.find_PhoneNmber(str);
			if (k != -1) {
				cout << StudGroup.GetStudents(k);
			}
			if (k == -1) {
				cout << "phonenimber not found" << endl;
			}
		}
			break;
		case 5:
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
			Arr index = StudGroup.find_Data(_day, _month, _year);
			if (index.number == 0)
				cout << "date not found" << endl;
			if (index.number != 0)
			{
				for (int i = 0; i < index.number; i++)
				{
					cout << StudGroup.GetStudents(index.arr[i]) << endl;
				}
			}
		}
			break;
		case 6:

			cout << StudGroup << endl;

			break;

		case 7:
		{
			string name, sourname, patronumic;
			long long phonenumber;
			int day, month, year;
			cout << "enter name : ";
			cin >> name;
			cout << endl;
			cout << "enter sourname : ";
			cin >> sourname;
			cout << endl;
			cout << "enter patronumic : ";
			cin >> patronumic;
			cout << endl;
			cout << "enter phonenumber : ";
			cin >> phonenumber;
			cout << endl;
			cout << "enter day : ";
			cin >> day;
			cout << endl;
			cout << "enter month : ";
			cin >> month;
			cout << endl;
			cout << "enter year : ";
			cin >> year;
			cout << endl;
			StudGroup.AddStudent(name, sourname, patronumic, phonenumber, day, month, year);
		}
			break;
		case 8:
		{
			int index;
			cout<<StudGroup<<endl;
			cout << "enter index: ";
			cin >> index;
			while ((index < 1) || (index > StudGroup.GetSize()))
			{
				cout << "enter index: ";
				cin >> index;
			}
			StudGroup.DeleteStudent(index);
		}
			break;
		default:
			break;
		}
	} while (level1 != 9);

    return 0;
}