
#include "stdafx.h"
#include <iostream>
#include <string>
#include <clocale>
using namespace std;

string rezult = "";

class List {
public:
	List();
	void Add(string ch);
	void Del();
	void Get();
private:
	string ch;
	List *Next;
};

List::List() {
	Next = nullptr;
	ch = "";
}

/** func void List::Add(string x)
    функция,добавляющая элемент в конец очереди 
*/
void List::Add(string x) {
	if (Next == nullptr) {
		if (ch == "") {
			ch = x;
		}
		else {
			Next = new List();
			Next->ch = x;
		}
		return;
	}
	else {
		Next->Add(x);
	}
}

/** func void List::Get()
функция получает элемент,находящийся в начале очереди
*/
void List::Get() {
		rezult = rezult + ch + " ";
}

/** func void List::Del()
функция,удаляющая первый элемент
*/
void List::Del() {
	if (Next != nullptr) {
		ch = Next->ch;
		Next = Next->Next;
	}
	else {
		Next = nullptr;
		ch = "";
	}
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
