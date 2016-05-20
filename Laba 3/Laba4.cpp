#include "Header.h"

using namespace std;

int main(){
	employee * e1 = new employee("Ivan Nikitich", 2);
	Chief * ch1 = new Chief("Pavel Stepanovich", 8);
	delete e1;
	delete ch1;
	cout << "\n";
	system("PAUSE");
	return 0;
};