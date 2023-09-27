#pragma once
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

	// Перегрузка операций
	T& operator[](int index);
	const Vector& operator=(const Vector& vec);
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
	friend Vector<T> operator*(T d, const Vector<T>& vec); // умножения скаляра на вектор
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

template<class T> Vector<T> operator*(T d, const Vector<T>& vec)
{
	Vector<T> res(vec.count);
	for (int i = 0; i < vec.count; ++i)
		res.memo[i] = d * vec.memo[i];
	return res;
}

/*
 template<typename T>
 ostream& operator<<(ostream& os, const Vector<T>& v)
 {
	 os << "Vector: (";
	 for (int i = 0; i < v.size; i++)
	 {
		 os << v.arr[i];
		 if (i == v.size - 1)
			 os << ")\n";
		 else
			 os << ",";
	 }
	 return os;
 }
 */
