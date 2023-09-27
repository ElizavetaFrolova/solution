#include <clocale>
#include <iomanip>
#include <iostream>
using namespace std;
#include "header1.h"

// Генерация элементов массива
template <class T>
void InitArray(T* arr, int arrCount, T minVal, T maxVal)
{
	float d;
	for (int i = 0; i < arrCount; ++i)
	{
		d = float(RAND_MAX - rand()) / RAND_MAX;
		arr[i] = minVal + T(d * (maxVal - minVal));
	}
}
int main()
{
	setlocale(LC_CTYPE, "Russian");
	// задание точности и формата вывода
//	cout << setprecision(2) << fixed;
	int vCount = 5;
	int* itArr = new int[vCount];
	long* lgArr = new long[vCount];
	short* shArr = new short[vCount];
	float* flArr = new float[vCount];
	double* dbArr = new double[vCount];

	cout << "int ====================================" << endl;
	InitArray(itArr, vCount, -10000, 10000);
	Vector<int> vIn(vCount, itArr);
	cout << "nachalnae znachenia vIn:" << endl;
	vIn.outPut("vIn");
	cout << vIn << endl;
	cout << "vIn[2] = " << vIn[2] << endl;
	vIn[3] = 5;
	cout << "vIn[3] = 5" << endl;
	vIn.outPut("vIn");
	Vector<int> vIn1(vCount);
	vIn1 = vIn;
	vIn1.outPut("vIn1");
	vIn1 = 2 * vIn;
	cout << "vIn1 = 2 * vIn;" << endl;
	vIn1.outPut("vIn1");
	/*
	cout << "long ====================================" << endl;
	InitArray(lgArr, vCount, -1000000L, 1000000L);
	Vector<long> vLg(vCount, lgArr);
	vLg.outPut("vLG");
	cout << "vLg[2] = " << vLg[2] << endl;
	vLg[3] = 5;
	vLg.outPut("vLg");
	Vector<long> vLg1(vCount);
	vLg1 = vLg;
	vLg1.outPut("vLg1");
	vLg1 = 2L * vLg;
	vLg1.outPut("vLg1");
	cout << "short ==================================" << endl;
	InitArray(shArr, vCount, short(-1000), short(1000));
	Vector<short> vSh(vCount, shArr);
	vSh.outPut("vSh");
	cout << "vSh[2] = " << vSh[2] << endl;
	vSh[3] = 5;
	vSh.outPut("vSh");
	Vector<short> vSh1(vCount);
	vSh1 = vSh;
	vSh1.outPut("vSh1");
	vSh1 = short(2) * vSh;
	vSh1.outPut("vSh1");
	cout << "float ==================================" << endl;
	InitArray(flArr, vCount, -1.0e5F, 1.0e5F);
	Vector<float> vFl(vCount, flArr);
	vFl.outPut("vFl");
	cout << "vFl[2] = " << vFl[2] << endl;
	vFl[3] = 5;
	vFl.outPut("vFl");
	Vector<float> vFl1(vCount);
	vFl1 = vFl;
	vFl1.outPut("vFl1");
	vFl1 = 2.0F * vFl;
	vFl1.outPut("vFl1");
	cout << "double ==================================" << endl;
	InitArray(dbArr, vCount, -1.0e8, 1.0e8);
	Vector<double> vDb(vCount, dbArr);
	vDb.outPut("vDb");
	cout << "vDb[2] = " << vDb[2] << endl;
	vDb[3] = 5;
	vDb.outPut("vDb");
	Vector<double> vDb1(vCount);
	vDb1 = vDb;
	vDb1.outPut("vDb1");
	vDb1 = 2.0 * vDb;
	vDb1.outPut("vDb1");
	*/
	return 0;
}