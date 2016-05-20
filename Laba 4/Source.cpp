#include "Head.h"

//-------------- class Complex ---------------
Complex::Complex(){re=0; im=0;}
Complex::Complex(int a){re=a;}
Complex::Complex(int a, int b){re=a; im=b;}

int Complex::getRe(){return re;}
int Complex::getIm(){return im;}
void Complex::print(){std::cout << "real: " << re << " imagine: " << im <<std::endl;}

Complex &Complex::operator=(Complex& cmp){
	re=cmp.re;
	im=cmp.im;
	return (*this);
}

Complex Complex::operator+(Complex& cmp){
	return Complex(re+cmp.getRe(), im+cmp.getIm());
}

Complex Complex::operator*(Complex& cmp){
	return Complex(re*cmp.getRe() - im*cmp.getIm(), re*cmp.getIm()+im*cmp.getRe());
}

//----------- class Line ------------------

//int Line::getSize(){return size;}
//Complex Line::operator[](int index){return ln[index];} //May be error
//
//Line::Line(){ln = new Complex[10]; size=10;}
//Line::Line(int a){ln = new Complex[a]; size=a;}
//Line::~Line(){delete[] ln;} //Деструктор
//Line::Line(Line& line){
//	ln = new Complex[size = line.getSize()];
//	for(int i(0); i < size; i++){ln[i] = line[i];}
//}
//
//
//Line Line::operator*(Line l){ //надо реализовать проверку на совпадение рамеров
//	int size;
//	Line tmp(size = l.getSize());
//	for(int i(0); i < size; i++){tmp[i] = ln[i]*l[i];}
//	return tmp;
//}
//
//Line Line::operator+(Line l){
//	int size = l.getSize();
//	Line tmp(size = l.getSize());
//	for(int i(0); i < size; i++){tmp[i] = ln[i]+l[i];}
//	return tmp;
//}
//
//void Line::print(){
//	std::cout << "<------------ Line ------------>" << std::endl;
//	for(int i(0); i < size; i++){ ln[i].print();}
//}

//--------------- class Matrix ------------------

//Line Matrix::operator[](int index){return mat[index];}
Complex& Matrix::operator()(int i, int j){return mat[i][j];}
Matrix::Matrix(){
	size = 10;
	mat = new Complex*[10];
	for(int i(0); i < size; i++){
		
		mat[i] = new Complex[10];
	}
	square = true;
	s_x = 10;
	s_y = 10;
}
Matrix::Matrix(int n){
	size = n;
	mat = new Complex*[n];
	for(int i(0); i < size; i++){
		
		mat[i] = new Complex[n];
	}
	square = true;
	s_x = n;
	s_y = n;
}
Matrix::Matrix(int n, int m){
	square = false;
	size=n;
	s_x = n;
	s_y = m;
	mat = new Complex*[n]; 
	for(int i(0); i < n; i++){
		
		mat[i] = new Complex[m];
	}
}
Matrix::Matrix(const Matrix& m){
	if(!m.square){
	square = false;
	s_x = m.s_x;
	s_y = m.s_y;
	size = m.size;
	mat = new Complex*[s_x]; 
	for(int i(0); i < size; i++){
		
		mat[i] = new Complex[s_y];
	}
	for(int i(0); i < m.getX(); i++){
		for(int j(0); j < m.getY(); j++){
			mat[i][j] = m.mat[i][j];
		}
	}
	}
	else if(m.square){
		square = true;
		size = m.size;
		s_x = m.s_x;
		s_y = m.s_y;
		mat = new Complex*[size]; 
	for(int i(0); i < size; i++){
		
		mat[i] = new Complex[size];
	}
	for(int i(0); i < m.getX(); i++){
		for(int j(0); j < m.getY(); j++){
			mat[i][j] = m.mat[i][j];
		}
	}
	}
}
Matrix::~Matrix(){
if(square){
	for(int i(0); i < size; i++){delete [] mat[i];}
}
delete [] mat;
}


int Matrix::getSize(){return size;}
int Matrix::getX() const{return s_x;}
int Matrix::getY() const{return s_y;}
int Matrix::getSquare(){return square;}
void Matrix::PrintRe(){
	if(square){
		std::cout << "<------- square matrix --------->" << std::endl;
		for(int i(0); i < size; i++){
			for(int j(0); j < size; j++){
				std::cout << mat[i][j].getRe() << ' ';
			}
			std::cout << std::endl;
		}
	}
	else if(!square){
		std::cout << "<-------  matrix --------->" << std::endl;
		for(int i(0); i < s_x; i++){
			for(int j(0); j < s_y; j++){
				std::cout << mat[i][j].getRe() << ' ';
			}
			std::cout << std::endl;
		}
	}
}

Matrix Matrix::operator*(Matrix m){
	if(!(s_y == m.s_x))return 0;
	Matrix tmp(s_x, m.s_y);
	for(int i(0); i<s_x; i++){
		for(int j(0); j<m.s_y; j++){
			Complex ctmp;
			for(int k(0); k<m.s_x; k++){
				ctmp = ctmp + (mat[i][k]*m(j, k));
			}
			tmp(i, j) = ctmp;
		}
	}
}
Matrix Matrix::operator+(Matrix m){
	int size;
	Matrix tmp(size = m.getSize());
	for(int i(0); i < size; i++){
		for(int j(0); j < size; j++){
			tmp(i, j) = mat[i][j]+m(i, j);
		}
	}
	return tmp;
}

void Matrix::Trans(){
	Matrix tmp(*this);
	if(square){
		for(int i(0); i< size; i++){
			for(int j(0); j < size; j++){
				mat[i][j] = tmp(j, i);
			}
		}
	}
	else if(!square){
		Matrix tmp(*this);
		for(int i(0); i < s_x; i++){delete [] mat[i];}
		delete [] mat;
		mat = new Complex*[s_y];
		for(int k(0); k < s_y; k++){mat[k] = new Complex[s_x];}
		
		for(int i(0); i < s_y; i++){
			for(int j(0); j<s_x; j++){
				mat[i][j] = tmp(j, i);
			}
		}
		int tmmp = s_x;
		s_x = s_y;
		s_y = tmmp;
	}

}