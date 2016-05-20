//include "Header.h"
#include <iostream>

using namespace std;
template <class T, int d = 100> class Vector {
	T *v;
public:
	Vector() { v = new T[d]; for (int i = 0; i < d; i++) v[i] = NULL; }
	Vector(const Vector<T, d>&) {
		v = new T[vect.d];
		for (int k = 0; k < vect.d; k++) v[k] = vect[k];
	}

	~Vector() { delete[] v; }
	//----------------------------------- functions-------------------------
	//int getDim() { return dim; }
	int Size() {
		int size = 0;
		for (int i = 0; i < d; i++) {
			if (v[i] == 0 | v[i] == NULL) return size;
			size++;
		}
		return size;
	}



	//------------------------------------operators--------------------------
	T & operator[](int index)
	{
		if (index >= 0 && index < d) return v[index];
		else {
			std::cout << "wrong index\n";
			exit(-1);
		}
	}
	Vector<T, d>& operator+(Vector<T, d>& vect)
	{

		for (int k = 0; k < d; k++) v[k] += vect.v[k];
		return *this;
	}
	Vector<T, d>& operator+(const T t) {
		v[Size()] = t;                   // тут выход за границы был
		return *this;
	}
	Vector<T, d>& operator+(T& t) {
		v[Size()] = t;                   // тут выход за границы был
		return *this;
	}

	Vector<T, d>& operator-(int k) {
		for (int i = 0; i < k; i++) v[this.size() - 1] = null;
	}
	Vector<T, d>& operator&(Vector<T, d>& vect) { // тут возможны проблемы
		Vector<T, d> temp;
		cout << temp.Size() << "\n";
		for (int i = 0; i < d; i++) {
			if (v[i] == vect[i]&v[i]!=NULL&vect[i]!=NULL ) { 
				temp[temp.Size()] = v[i];
				//cout << temp.Size() << " ";
			}
		}
		cout << temp.Size() << "\n";
		return temp;
	}
	Vector<T, d>& operator|(Vector<T, d>& vect) { // тут возможны проблемы
		Vector<T, d> temp;
		for (int i = 0; i < k; i++) {
			if (vect[i] != NULL) temp + vect[i];
			else if (v[i] != null) temp + v[i];
		}
		return temp;
	}

};


//---------------------------------main----------------------------


int main() {
	//vector<MyCl> v;

	//MyCl a1 = MyCl(14);
	//MyCl a2 = MyCl(14);

	Vector<int> v1;
	Vector<int> v2;
	//Vector<MyCl> v2;
	v1 = v1 + 5;
	v1 = v1 + 5;
	v1 = v1 + 5;
	v1 = v1 + 5;
	v1 = v1 + 5;

	v2 = v2 + 5;
	/*cout << "\n\n\n\n\n\n\n---------------------------------------";
	for (int i = 0; i < 100; i++) {
		cout << v2[i] << "  ";
	}
	cout << "\n\n\n\n\n\n\n---------------------------------------";*/
	cout << v1.Size() << "\n";
	cout << (v1&v2).Size() << "\n";
	system("PAUSE");
	return 0;
}
