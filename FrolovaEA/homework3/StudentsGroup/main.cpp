#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <iomanip>

#include "header.h"
using namespace std;

int main()
{
    Students* p;

    int size = cntLines("students.txt");

    cout << size << endl;

//    allocate_stock(p, size);

//    fill_sklad(p, size, "students.txt");

//    Group StudGroup(size, p, size);
	Group StudGroup(size, "students.txt", size);

    StudGroup.print();

//	StudGroup.AddStudent();

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
			cout << "ERROR. Please enter numbers only: 1 - 8" << endl;
		}
		switch (level1) {
		case 1:
			StudGroup.find_Name();
			
			break;
		case 2:
			StudGroup.find_Surname();

			break;
		case 3:
			StudGroup.find_Patronymic();
			break;
		case 4:
			StudGroup.find_PhoneNmber();
			break;
		case 5:
			StudGroup.find_Data();
			break;
		case 6:
			StudGroup.print();
			break;
		case 7:
			StudGroup.AddStudent();
			break;
		case 8:
			StudGroup.DeleteStudent();
			break;
		default:
			break;
		}
	} while (level1 != 9);

	
 //   StudGroup.find_Name(size);
 //   StudGroup.find_Surname(size);
 //   StudGroup.find_Patronymic(size);
 //   StudGroup.find_PhoneNmber(size);
 //   StudGroup.find_Data(size);
//    delete[] p;
    return 0;
}