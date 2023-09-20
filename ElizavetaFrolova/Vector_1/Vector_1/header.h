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

	Vector();// ����������� �� ���������
	Vector(float x,float y,float z);//����������� �������������
	~Vector();// ����������

	Vector& operator=(const Vector& vec); // �������� ������������
	Vector operator+(const Vector& vec); // �������� ������������
	Vector operator-(const Vector& vec); // �������� ���������
	float operator*(const Vector& vec); // �������� ���������� ������������
	friend ostream& operator<<(ostream& stream, const Vector& vec);// ����� � �����

	float vectorLength();// ����� �������
	float cosineOfTheAngleBetweenVectors(const Vector& vec);//������� ���� ����� ���������
};

# endif