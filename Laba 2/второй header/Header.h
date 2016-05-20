#pragma once
#include <iostream>
using namespace std;

//class MAC {
//	virtual int operator+(int a) = 0;
//	virtual int operator-(int a) = 0;
//	virtual int operator/(int a) = 0;
//	virtual int operator*(int a) = 0;
//	virtual int operator==(int a) = 0;
//	virtual int operator%(int a) = 0;
//};


//--------------класс с переопределенными операторами--------------
class MyCl {
protected:
	int a;
public:

	MyCl();
	MyCl(int aa);

	int Get_a();

	MyCl operator+(MyCl& b);
	MyCl operator+(const int b);
	MyCl operator-(MyCl& b);
	MyCl operator-(const int b);
	MyCl operator/(MyCl& b);
	MyCl operator/(const int b);
	MyCl operator*(MyCl& b);
	MyCl operator*(const int b);
	bool operator==(MyCl& b);
	bool operator==(const int b);
	MyCl operator%(MyCl& b);
	MyCl operator%(const int b);
	MyCl operator^(MyCl& b);
	MyCl operator^(const int b);

private:

};

//-----------класс контейнер--------------

//template <class T, int d = 100> class Vector {
//	T *v;
//public:
//	Vector() { v = new T[d]; }
//	Vector(const Vector<T, d>&);
//
//	~Vector() { delete[] v; }
//
//	//int getDim() { return dim; }
//	int Size() {
//		int size = 0;
//		for (int i = 0; i < d; i++) {
//			if (v[i] == NULL) return size;
//			size++;
//		}
//		return size;
//	}
//
//	T & operator[](int index);
//	Vector<T, d>& operator+(Vector<T, d>&);
//	Vector<T, d>& operator+(T& t);
//	Vector<T, d>& operator-(int k);
//	Vector<T, d>& operator&(Vector<T, d>&);
//	Vector<T, d>& operator|(Vector<T, d>&);
//
//	//T norm1();
//	//T norm2();
//	//T normInfinity();
//};

//template <class T, int d = 100> class Vector {
//	T *v;
//public:
//	Vector() { v = new T[d]; }
//	Vector(const Vector<T, d>&) {
//		v = new T[vect.d];
//		for (int k = 0; k < vect.d; k++) v[k] = vect[k];
//	}
//
//	~Vector() { delete[] v; }
//
//	//int getDim() { return dim; }
//	int Size() {
//		int size = 0;
//		for (int i = 0; i < d; i++) {
//			if (v[i] == NULL) return size;
//			size++;
//		}
//		return size;
//	}
//
//	T & operator[](int index)
//	{
//		if (index >= 0 && index < d) return v[index];
//		else {
//			std::cout << "wrong index\n";
//			exit(-1);
//		}
//	}
//	Vector<T, d>& operator+(Vector<T, d>&)
//	{
//		if (dim != vect.d) {
//			std::cout << "wrong size\n";
//			exit(-1);
//		}
//		for (int k = 0; k < d; k++) v[k] += vect.v[k];
//		return *this;
//	}
//	Vector<T, d>& operator+(T& t) {
//		v[Size()] = t;
//		return *this;
//	}
//	Vector<T, d>& operator-(int k) {
//		for (int i = 0; i < k; i++) v[this.size() - 1] = null;
//	}
//	Vector<T, d>& operator&(Vector<T, d>& vect) { // тут возможны проблемы
//		Vector<T, d> temp;
//		for (int i = 0; i < d; i++) {
//			if (v[i] == vect[i] != NULL) temp + v[i];
//		}
//		return temp;
//	}
//	Vector<T, d>& operator|(Vector<T, d>& vect) { // тут возможны проблемы
//		Vector<T, d> temp;
//		for (int i = 0; i < k; i++) {
//			if (vect[i] != NULL) temp + vect[i];
//			else if (v[i] != null) temp + v[i];
//		}
//		return temp;
//	}
//
//	//T norm1();
//	//T norm2();
//	//T normInfinity();
//};