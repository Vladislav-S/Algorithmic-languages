// Q.cpp: определяет экспортированные функции для приложения DLL.
//

#include "stdafx.h"
#include <vector> 
#include <string>
#include <algorithm>
#include <clocale>
using namespace std;

vector<int> mas;

extern "C" {
	__declspec(dllexport) void add(int ch) {
		mas.push_back(ch);
	}

	__declspec(dllexport) int get() {
		return mas.front();
	}

	__declspec(dllexport) void del() {
		mas.erase(mas.begin());
	}
}