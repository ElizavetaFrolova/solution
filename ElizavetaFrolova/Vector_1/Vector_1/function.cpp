#include <iostream>
#include <cmath>
#include "header.h"

using namespace std;

Vector::Vector()
{
	x = 0;
	y = 0;
	z = 0;
}

Vector::Vector(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector::~Vector()
{

}

Vector& Vector::operator=(const Vector& vec)
{
	if (this != &vec)
	{
		x = vec.x;
		y = vec.y;
		z = vec.z;
	}
	return *this;
}

Vector Vector::operator+(const Vector& vec)
{
	Vector res;
	res.x = x + vec.x;
	res.y = y + vec.y;
	res.z = z + vec.z;
	return res;
}

Vector Vector::operator-(const Vector& vec)
{
	Vector res;
	res.x = x - vec.x;
	res.y = y - vec.y;
	res.z = z - vec.z;
	return res;
}

float Vector::operator*(const Vector& vec)
{
	float res = 0.0;
	res = (x * vec.x) + (y * vec.y) + (z * vec.z);
	return res;
}

float Vector::vectorLength()
{
	float c;
	c = sqrt((x * x) + (y * y) + (z * z));
	return c;
}

float Vector::cosineOfTheAngleBetweenVectors(const Vector& vec)
{
	float a;
	a = ((x * vec.x) + (y * vec.y) + (z * vec.z)) / (sqrt((x * x) + (y * y) + (z * z))) + (sqrt((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z)));
	return a;
}

ostream& operator<<(ostream& stream, const Vector& vec)
{
	stream << " x = " << vec.x << ";" << " y = " << vec.y << ";" << " z = " << vec.z << ";" << endl;
	return stream;
}



