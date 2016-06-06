#include "stdafx.h"
#include <iostream>
#include <string>
#include <clocale>
using namespace std;

string rezult = "";

class List {
public:
	List();
	List(List&, string);
	void Add(string ch);
	void Del();
	void Get();
private:
	string ch;
	List *Head;
};


List::List(List& p, string x) {
	Head = &p;
	ch = x;
}

List::List() {
	Head = nullptr;
	ch = "";
}

/** \func void List::Add(string x)
функция добавляет элемент в конец стека
*/
void List::Add(string x) {
	List *N = new List(*Head,ch);
	ch = x;
	Head = N;
}


/** \func void List::Get()
функция получает элемент,находящийся в конце стека
*/
void List::Get() {
	rezult = rezult + ch + " ";
}


/** \func void List::Del()
функция удаляет элемент,находящийся в конце стека
*/
void List::Del() {
    ch = Head->ch;
    Head = Head->Head;	
}

int main()
{
	int N;
	string x;
	string s;
	List A;

	setlocale(LC_CTYPE, "Russian");
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> s;
		if (s == "add") {
			cin >> x;
			A.Add(x);
		}
		if (s == "get") {
			A.Get();
		}
		if (s == "del") {
			A.Del();
		}
	}

	cout << endl << "Выход:" << endl;
	cout << rezult;
	system("pause");
	return 0;
}
