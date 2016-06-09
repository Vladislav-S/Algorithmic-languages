#include <iostream>
#include "stdlib.h"
#include <iomanip>
#include "stdio.h"
#include "conio.h"
//SAPRYKIN IU8-24
using namespace std;

template<class T>
class matrix {
private:
	T **mas;
	int n, m;
public:
	matrix() {}
	int matrix_get_n() { return n; }
	int matrix_get_m() { return m; }
	T** get() { return mas; }
	void set(T** mas1) { mas = mas1; }
	matrix(int n1, int m1);
	void out();
	matrix(const matrix<T> &a);
	~matrix();

	matrix<T> operator +(matrix<T> &b);
	matrix<T> operator -(matrix<T> &b);
	matrix<T> operator *(matrix <T> &b);
	T& at(int ind, int ind2);
};

template<class T>
matrix<T>::matrix(int n1, int m1) {
	n = n1;
	m = m1;
	mas = new T*[n];
	for (int i = 0; i<n; i++) {
		mas[i] = new T[m];
	}
	for (int k = 0; k<n; k++) {
		for (int i = 0; i<m; i++) {
			mas[k][i] = rand() % 10;
		}
	}
}
template<class T>
void matrix<T>::out()
{
	for (int k = 0; k<n; k++) {
		for (int i = 0; i<m; i++) {
			cout << setw(4) << mas[k][i];
		}
		cout << endl;
	}
	cout << endl;
}
template<class T>
matrix<T>::matrix(const matrix<T> &a)
{
	n = a.n;
	m = a.m;
	mas = new T*[n]; // ????ой м*????
	for (int i = 0; i<n; i++) {
		mas[i] = new T[m];
	}
	for (int k = 0; k<n; k++) {
		for (int i = 0; i<m; i++) {
			mas[k][i] = a.mas[k][i];
		}
	}
}
template<class T>
matrix<T>::~matrix() {
	for (int i = 0; i<n; i++) delete[] mas[i];
	delete[]mas;
}

template<class T>
matrix<T> matrix<T>::operator +(matrix<T> &b) {
	matrix<T> c(n, m);
	for (int k = 0; k<n; k++) {
		for (int i = 0; i<m; i++) {
			c.mas[k][i] = b.mas[k][i] + mas[k][i];
		}
	}
	return c;
}

template<class T>
matrix<T> matrix<T>::operator -(matrix<T> &b) {
	matrix<T> c(n, m);
	for (int k = 0; k< n; k++) {
		for (int i = 0; i<m; i++) {
			c.mas[k][i] = mas[k][i] - b.mas[k][i];
		}
	}
	return c;
}


template<class T>
matrix<T> matrix<T>::operator *(matrix<T> &b) {
	matrix<T> c(n, m);
	for (int k = 0; k< n; k++) {
		for (int i = 0; i<m; i++)
		{
			c.mas[k][i] = 0;
			for (int j = 0; j<b.n; j++) {
				c.mas[k][i] += (mas[k][j] * b.mas[j][i]);
			}
		}
	}
	return c;
}

template<class T>
T& matrix<T>::at(int ind, int ind2)
{
	return mas[ind][ind2];
}

template<class T>
class Iterator
{
private:
	int index;
	int* f, *e;
	matrix<T>*m;
	int eend;

public:
	Iterator(matrix<T>* mm)
	{
		m = mm;
		index = 0;
	}
	Iterator(Iterator *it) {
		index = it->index;
		m = it->m;
	}

	int end() {
		return ((m->matrix_get_m())*(m->matrix_get_n()));
	}

	Iterator &  operator++(int) {
		index++;
		return *this;
	}

	void null() {
		index = 0;
	}

	T& operator*() {

		int stolb = index / m->matrix_get_n();//???????
		int strok = index - m->matrix_get_m() * stolb;// stroka
		return m->index(stolb, strok);

	}

	T& operator[] (int b) {

		int stolb = b / m->matrix_get_m();//???????
		int strok = b - m->matrix_get_m() * stolb;// stroka
		return m->at(stolb, strok);
	}

	int getInd() {
		return index;
	}

};

template<class T, class U, class IN, class OUT>
 OUT * my_cast(IN  obj) {
	
	Iterator<T> iter(obj);
	OUT * mat = new OUT(3, 3);
	Iterator<U> iter1(mat);

	for (int i = 0; i < iter.end(); i++) {
		iter1[iter1.getInd()] = static_cast<U>(iter[iter.getInd()]);
		iter++;
		iter1++;
	}
	return mat;
}


int main() {
	
	matrix<int> k(3, 3), p(3, 3);

	matrix<int> pp = k + p;
	
	pp.out();

	matrix<int> * kk = new matrix<int>(3, 3);

	Iterator<int> iter(kk);
	
	for (int i = 0; i < iter.end(); i++) {
		cout << iter[iter.getInd()] << " ";

		iter++;
	}

	cout << endl;

	kk->out();

	matrix<uint16_t> * maa = my_cast<int, uint16_t, matrix<int> *, matrix<uint16_t>>(kk);
	maa->out();
	system("pause");
	return 0;
}