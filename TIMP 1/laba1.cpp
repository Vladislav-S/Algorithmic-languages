#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void proverka(string n1, string n2) {
	int i = 1;
	ifstream F1(n1);
	while (!F1.eof()) {
		string s1, s2;
		bool ch = false;
		ifstream F2(n2);
		getline(F1, s1);
		while (!F2.eof()) {
			getline(F2, s2);
			if (s1 == s2) {
				ch = true;
			}
		}
		F2.close();
		if (ch == false) {
			cout << n1 << " " << i << " " << s1 << endl;
			i++;
		}
	}
	F1.close();
}

int main()
{
	string name1;
	string name2;
	cin >> name1;
	cin >> name2;
	proverka(name1, name2);
	proverka(name2, name1);
	system("pause");
    return 0;
}

