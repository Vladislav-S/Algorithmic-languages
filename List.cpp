#include <iostream>
#include <string>
using namespace std;
/** 
@mainpage первая моя программа по лабораторной работе, реализует список
@brief class List
@detailed класс, реализующий список с помощью  указателей 
*/
class list
{
	list* Next;
	string Data;
public:
	list() : Next(nullptr), Data("") {};
	void add(int i, string data);
	void get(int i);
	void del(int i);
	~list() { if (Next != nullptr) delete Next; }
}List;

void list::add(int i, string data)
{
	if (i == 0)
	{
		Data = data;
		return;
	}
	if (Next == nullptr)
		Next = new list();
	Next->add(i - 1, data);
}

void list::get(int i)
{
	if (i == 0)
	{
		cout << Data << endl;
		return;
	}
	if (Next == nullptr)
		Next = new list();
	Next->get(i - 1);
}

void list::del(int i)
{
	add(i, "");
}



	int main()
	{
		cout << "program - list. for the first, enter number of operations: " << endl;
		size_t n;       //Number of commands
		int ind;        //Index of element
		string line;    //Command name
		cin >> n;
		cout << "now you can enter operations with list: " << endl;
		for (size_t i = 0; i < n; i++)
		{
			cin >> line;
			if (line == "add")
			{
				cin >> ind >> line;
				List.add(ind, line);
			}
			else if (line == "get")
			{
				cin >> ind;
				List.get(ind);
			}
			else if (line == "del")
			{
				cin >> ind;
				List.del(ind);
			}
			else
				return 1;

		}

		return 0;
	}

