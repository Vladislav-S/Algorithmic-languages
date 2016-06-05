// TiMP_laba2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main()
{
	char name[255];
	string s;
	int i = 1;
	string rezult;
	bool ch = false;
	int pos,k;

	cin >> name;
	ifstream F(name);

	while (getline(F,s)) {
		if (s.find("/**") != string::npos) {
			ch = true;
		}
		pos = s.find("\\func");
		k = s.find("*/");
		if (ch & (pos != string::npos)) {
			if (k != string::npos) {
				cout << i << ". " << s.substr(s.find("\\func") + 6, s.find("*/") - s.find("\\func") - 6) << endl;
				i++;
			}
			string temp = s.substr(s.find("\\func") + 6);
			if (k == string::npos)
			{
				getline(F, s);
				if (s.find("*/") != string::npos) {
					cout << i << ". " << temp << endl;
					i++;
				}
			}
			ch = false;
		}
	}
	system("pause");
    return 0;
}

