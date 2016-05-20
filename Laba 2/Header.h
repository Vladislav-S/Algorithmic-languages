#include <iostream>
#include <cstring>

using namespace std;
class Vect{
	
	
public:
	double * d;
	int size;
	Vect();
	Vect(int);
	Vect(const Vect&);
	~Vect();
	//double * GetD();
	double operator[](int index);
	Vect& operator+(double);
	int operator+=(double);
	//Antivir operator-(Vectorr);
	Vect operator*(double);
	int operator*=(double);

	Vect operator&(const Vect&);

	Vect operator|(const Vect&);
	//Antivir operator/(Vectorr);
};