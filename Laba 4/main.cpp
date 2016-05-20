#include "Head.h"

int main(){
	Complex cmp(4, 5);
	Complex cmp1(7, 8);
	cmp.print();
	//cmp1.print();
	Complex cmp2 = cmp + cmp1;
	//cmp2.print();

	Matrix m(3, 1);
	Matrix m1(m);
	m(0, 0) = cmp;
	m(1, 0) = cmp1;
	//m.PrintRe();
	m.Trans();
	//m.PrintRe();
	Matrix m3 = m1*m;
	m3.PrintRe();
	//m(1, 1).print();
	system("pause");
	return 0;
}