#include <iostream>

class Complex{
	int re;
	int im;
public:
	Complex();
	Complex(int);
	Complex(int, int);

	int getRe();
	int getIm();
	void print();

	Complex &operator=(Complex&);
	Complex operator+(Complex&);
	Complex operator*(Complex&);
};


//class Line{
//	Complex* ln;
//	int size;
//public:
//	Complex operator[](int);
//	Line();
//	Line(int);
//	Line(Line&);
//	~Line();
//	int getSize();
//	void print();
//
//	Line operator*(Line);
//	Line operator+(Line);
//};



class Matrix{
	//Complex* matt;
	Complex** mat;
	int size;
	bool square;
	int s_x, s_y;
public:
	Complex& operator()(int index, int index1);
	Matrix();
	Matrix(int);
	Matrix(int, int);
	Matrix(const Matrix&);
	~Matrix();

	int getSize();
	int getX() const;
	int getY() const;
	int getSquare();
	void PrintRe();
	void Trans();

	Matrix operator*(Matrix);
	//Matrix operator*(Complex);
	Matrix operator+(Matrix);
	//Matrix operator+(Complex);
	
};