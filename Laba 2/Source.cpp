#include "Header.h"

using namespace std;

Vect::Vect() {d = new double[100]; size=0; memset(d, 0, sizeof(double)*100);}
Vect::Vect(int a) {d= new double[a]; size=0; memset(d, 0, sizeof(double)*a);}
Vect::Vect(const Vect& a)
{
	d = new double[100];
	for(int i = 0; i < a.size; i++){
		d[i] = a.d[i];
	}
	//d = a.d; 
	//a.d = nullptr;
	//size = a.size;
}
Vect::~Vect(){delete[] d;}


double Vect::operator[](int index){
	return d[index];
}

Vect Vect::operator*(double a){
	for(int i = 0; i< size; i++){
		d[i]*=a;
	}
	return *this;
}

int Vect::operator*=(double a){
	for(int i = 0; i<size; i++){
		d[i] *= a;
	}
	return 1;
}

int Vect::operator+=(double a){
	d[size] = a;
	size++;
	return 1;
}

Vect& Vect::operator+(double a){
	d[size] = a;
	size++;
	return *this;
}

Vect Vect::operator&(const Vect& v){
	Vect temp;
	for(int i=0; i<100; i++){
		if(d[i]==v.d[i]) temp+=d[i];
	}
	return temp;
}

Vect Vect::operator|(const Vect& v){
	Vect temp;
	for(int i = 0; i<100; i++){
		if(d[i] != 0)temp+=d[i];
	}
	for(int i = 0; i<100; i++){
		if(v.d[i] != 0)temp+=v.d[i];
	}

	return temp;
}
//double * Vect::GetD(){
//	return d;
//}

