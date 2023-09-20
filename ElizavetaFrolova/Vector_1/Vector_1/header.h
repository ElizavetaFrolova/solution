#ifndef _HEADER3_H_
#define _HEADER3_H_
#include <iostream>

using namespace std;


class Vector
{
private:

	float x;
	float y;
	float z;

public:

	Vector();// конструктор по умолчанию
	Vector(float x,float y,float z);//конструктор инициализатор
	~Vector();// деструктор

	Vector& operator=(const Vector& vec); // операция присваивания
	Vector operator+(const Vector& vec); // операция суммирования
	Vector operator-(const Vector& vec); // операция вычитания
	float operator*(const Vector& vec); // операция скалярного произведения
	friend ostream& operator<<(ostream& stream, const Vector& vec);// вывод в поток

	float vectorLength();// длина вектора
	float cosineOfTheAngleBetweenVectors(const Vector& vec);//косинус угла между векторами
};

# endif