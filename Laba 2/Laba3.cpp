#include "Header.h"

using namespace std;
int main(){
	{
		Vect a; 
		a+=3; 
		a*=3;
		a+=4;
		Vect b;
		b+=9;
		Vect c = a&b;
		Vect d = a|b;
		cout << a[0] <<"\n";
		cout << a[1] <<"\n";
		cout << c[0] <<"\n";
		cout << d[2] <<"\n";
	} // delete [] a.d;
	// delete[] b.d;
	system("PAUSE");
	return 0;
}