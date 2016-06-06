#include "stdafx.h"
#include <iostream>
#include <string>
#include <locale.h>
using namespace std;

string rezult = " ";

class List {
public:
	List();
	List(List&, string);
	void Add(int i , string ch);
	void Del(int i);
	void Get(int i);
private:
	string ch;
	List *Next;
};

List::List(List& p, string x) {
	ch = x;
	Next = &p;
}

/** func void List::Del(int i)
    функция,удаляющая i-ый элемент
*/
void List::Del(int i)
{
	if (i == 0) {
		if (Next != nullptr) {
			ch = Next->ch;
			Next = Next->Next;
		}
		else {
			ch = "";
		}
		return;
	}
	else {
		Next->Del(i - 1);
	}
}

List::List() {
	Next = nullptr;
	ch = "";
}

/** func void List::Get(int i)
    функция,получающая i-ый элемент
*/
void List::Get(int i)
{
	if (i == 0) {
		rezult = rezult + ch + " ";
		return;
	}
	else {
		Next->Get(i - 1);
	}
}

/** func void List::Add(int i,string x)
    функция,добавляющая x на i-ый элемент
*/
void List::Add(int i, string x) {
	if (i == 0) {
		if (ch != "") {
			List *N = new List(*Next, ch);
			ch = x;
			Next = N;
		}
		else
			ch = x;
		return;
	}
	else
	{
		if (Next == nullptr)
			Next = new List();
		Next->Add(i - 1, x);
	}
}


int main()
{
	int N;
	int index;
	string x;
	string s;
	List A;

	setlocale(LC_CTYPE, "Russian");
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> s;
		if (s == "add") {
			cin >> index;
			cin >> x;
			A.Add(index, x);
		}
		if (s == "get") {
			cin >> index;
			A.Get(index);
		}
		if (s == "del") {
			cin >> index;
			A.Del(index);
		}
	}

	cout << endl << "Выход:" << endl;
	cout << rezult;
	system("pause");
	return 0;
}
