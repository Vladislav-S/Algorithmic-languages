// TiMP_laba7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream> 
#include <string>
#include "Windows.h"
using namespace std;

int main() {
	string s;
	int ch;
	cin >> s;
	HINSTANCE h=0;

	if (s == "PQ")
		h = LoadLibrary(L"PQ");
	if (s == "Q")
		h = LoadLibrary(L"Q");

	if (h) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> s;
			if (s == "add") {
				cin >> ch;
				typedef void z(int s);
				FARPROC add = (FARPROC)GetProcAddress((HMODULE)h, "add");
				((z*)add)(ch);
			}
			if (s == "get") {
				FARPROC get = (FARPROC)GetProcAddress((HMODULE)h, "get");
				cout << get() << endl;
			}
			if (s == "del") {
				FARPROC del = (FARPROC)GetProcAddress((HMODULE)h, "del");
				del();
			}
		}
	}
	system("pause");
	return 0;
}




