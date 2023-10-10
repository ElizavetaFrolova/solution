#pragma once
//#include <cmath>
#include <math.h>
using namespace std;
template<class T>
class Vector {

private:
	T* memo;
	int count;

public:
	Vector();
	explicit Vector(int _count);
	Vector(int _count, T d);
	Vector(int _count, T* ar);
	Vector(const Vector& vec);
	~Vector();

	// вывод на консоль
	void outPut(const char* name) const;

	// ѕерегрузка операций
	T& operator[](int index);
	const Vector& operator=(const Vector<T>& vec);
	Vector operator+(const Vector<T>& V1);
	Vector operator-(const Vector<T>& V1);
	double operator*(const Vector<T>& V1) const;//скал€рное произведение
	bool operator == (const Vector<T>& V1) const;
	bool operator != (const Vector<T>& V1) const;
//	double lenght() const;
	double mod() const;
	friend istream& operator>>(istream& stream, Vector<T>& vec) // ввод из потока
	{
		int strCount;
		stream >> strCount;
		if (vec.count != strCount)
		{
			if (vec.memo != NULL)
				delete[] vec.memo;
			vec.count = strCount;
			vec.memo = new T[strCount];
		}
		for (int i = 0; i < vec.count; ++i)
			stream >> vec.memo[i];
		return stream;
	}

	friend ostream& operator<<(ostream& os, const Vector<T>& v)
	{
		os << "Vector: (";
		for (int i = 0; i < v.count; i++)
			{
				os << v.memo[i];
				if (i == v.count - 1)
					os << ")\n";
				else
					os << ",";
			}
		return os;
		
	}
	template<class T>
	friend Vector<T> operator*(T d, const Vector<T>& vec); // умножени€ скал€ра на вектор
};

template<class T>
Vector<T>::Vector()
{
	
	count = 0;
	memo = NULL;
}

template<class T>
Vector<T>::Vector(int _count) : count(_count)
{
	memo = new T[count];
}

template<class T>
Vector<T>::Vector(int _count, T d) :
	count(_count)
{
	memo = new T[count];
	for (int i = 0; i < count; ++i)
		memo[i] = d;
}

template<class T>
Vector<T>::Vector(int _count, T* ar) :
	count(_count)
{
	memo = new T[count];
	for (int i = 0; i < count; ++i)
		memo[i] = ar[i];
}

template<class T>
Vector<T>::Vector(const Vector<T>& vec) {
	count = vec.count;
	memo = new T[count];
	for (int i = 0; i < count; ++i)
		memo[i] = vec.memo[i];
}

template<class T>
Vector<T>::~Vector() {
	if (memo != NULL)
	{
		delete[] memo;
		memo = NULL;
		count = 0;
	}
}

template<class T>
void Vector<T>::outPut(const char* name) const
{
	cout << name << ": ";
	for (int i = 0; i < count; ++i)
		cout << memo[i] << ",\t";
	cout << endl;
}

template<class T>
T& Vector<T>::operator[](int index) {
	if (index < 0 || index >= count)
		abort();
	return memo[index];
}

template<class T>
const Vector<T>& Vector<T>::operator=(const Vector<T>& vec)
{
	if (this != &vec)
	{
		if (count != vec.count) 
		{
			delete[] memo;
			count = vec.count;
			memo = new T[count];
		}
		for (int i = 0; i < count; ++i)
			memo[i] = vec.memo[i];
	}
	return *this;
}

template<class T> Vector<T> Vector<T>:: operator+(const Vector<T>& V1)
{
	if (count != V1.count)
		throw "Error";
	Vector<T> res(count);
	for (int i = 0; i < count; i++)
	{
		res.memo[i] = memo[i] + V1.memo[i];
	}
	return res;
}

template<class T> Vector<T> Vector<T>:: operator-(const Vector<T>& V1)
{
	if (count != V1.count)
		throw "Error";
	Vector<T> res(count);
	for (int i = 0; i < count; i++)
	{
		res.memo[i] = memo[i] - V1.memo[i];
	}
	return res;
}

template<class T> double Vector<T>::operator*(const Vector<T>& V1) const
{
	if (count != V1.count)
		throw "Error";
	double res = 0.0;
	for (int i = 0; i < count; i++)
	{
		res += memo[i] * V1.memo[i];
	}
	return res;
}

template<class T> bool Vector<T>::operator==(const Vector<T>& V1) const
{
	if (count != V1.count)
		return false;
	for (int i = 0; i < count; i++)
		if (memo[i] != V1.memo[i])
			return false;
	return true;
}

template<class T> bool Vector<T>::operator!=(const Vector<T>& V1) const
{
	if (count != V1.count)
		return true;
	for (int i = 0; i < count; i++)
		if (memo[i] != V1.memo[i])
			return true;
	return false;
}

template<class T>
double Vector<T>::mod() const
{
	T ans = 0;
	for (int i = 0; i < count; i++)
		ans += (memo[i] * memo[i]);
	return sqrt((double)ans);
}

/*
template<class T>
double Vector<T>::lenght() const
{	
	T res = 0;
//	double res1;
	for (int i = 0; i < count; i++)
	{
		res += memo[i] * memo[i];
		cout <<"number of operation: "<< i+1 << endl;
		cout << res << endl;
		cout << "-------------------------------------------------"<< endl;
	}
	cout << "itogo: "<<res << endl;
	cout << sqrt(res) << endl;
	return sqrt(res);
}
*/



template<class T> Vector<T> operator*(T d, const Vector<T>& vec)
{
	Vector<T> res(vec.count);
	for (int i = 0; i < vec.count; ++i)
		res.memo[i] = d * vec.memo[i];
	return res;
}

