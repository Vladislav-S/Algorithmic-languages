#include <cassert> // ��� assert
#include <iostream>
#include <string>
#include <iomanip> // ��� setw
#include "stdio.h"
/** 
@mainpage ���������, ����������� ����
@brief template class Stack
@detailed ��������� �����, ����������� ���� � �������  ���������� 
*/

template <typename T>
class Stack
{
private:
	T *stackPtr;                      // ��������� �� ����
	const int size;                   // ������������ ���������� ��������� � �����
	int top;                          // ����� �������� �������� �����
public:
	Stack(int = 10);                  // �� ��������� ������ ����� ����� 10 ���������
	Stack(const Stack<T> &);          // ����������� �����������
	~Stack();                         // ����������

	inline void push(const T &);     // ��������� ������� � ������� �����
	inline T pop();                   // ������� ������� �� ������� ����� � ������� ���
	inline void printStack();         // ����� ����� �� �����
	inline const T &Peek(int) const; // n-� ������� �� ������� �����
	inline int getStackSize() const;  // �������� ������ �����
	inline T *getPtr() const;         // �������� ��������� �� ����
	inline int getTop() const;        // �������� ����� �������� �������� � �����
};

// ���������� ������� ������� ������ STack

// ����������� �����
template <typename T>
Stack<T>::Stack(int maxSize) :
	size(maxSize) // ������������� ���������
{
	stackPtr = new T[size]; // �������� ������ ��� ����
	top = 0; // �������������� ������� ������� �����;
}

// ����������� �����������
template <typename T>
Stack<T>::Stack(const Stack<T> & otherStack) :
	size(otherStack.getStackSize()) // ������������� ���������
{
	stackPtr = new T[size]; // �������� ������ ��� ����� ����
	top = otherStack.getTop();

	for (int ix = 0; ix < top; ix++)
		stackPtr[ix] = otherStack.getPtr()[ix];
}

// ������� ����������� �����
template <typename T>
Stack<T>::~Stack()
{
	delete[] stackPtr; // ������� ����
}

// ������� ���������� �������� � ����
template <typename T>
inline void Stack<T>::push(const T &value)
{
	// ��������� ������ �����
	assert(top < size); // ����� �������� �������� ������ ���� ������ ������� �����

	stackPtr[top++] = value; // �������� ������� � ����
}

// ������� �������� �������� �� �����
template <typename T>
inline T Stack<T>::pop()
{
	// ��������� ������ �����
	assert(top > 0); // ����� �������� �������� ������ ���� ������ 0

	return stackPtr[--top]; // ������� ������� �� �����
}

// ������� ���������� n-� ������� �� ������� �����
template <class T>
inline const T &Stack<T>::Peek(int nom) const
{
	//
	assert(nom <= top);

	return stackPtr[top - nom]; // ������� n-� ������� �����
}

// ����� ����� �� �����
template <typename T>
inline void Stack<T>::printStack()
{
	for (int ix = top - 1; ix >= 0; ix--)
		cout << "|" << setw(4) << stackPtr[ix] << endl;
}

// ������� ������ �����
template <typename T>
inline int Stack<T>::getStackSize() const
{
	return size;
}

// ������� ��������� �� ���� (��� ������������ �����������)
template <typename T>
inline T *Stack<T>::getPtr() const
{
	return stackPtr;
}

// ������� ������ �����
template <typename T>
inline int Stack<T>::getTop() const
{
	return top;
}

using namespace std;

int main()
{
	string str;
	string arg;
	Stack<int> stack;
	int i;
	int ii;
	cout << "enter command in format: [command] <arg> (type help for more information)" << endl;
	while (true)
	{

		getline(cin, str);
		if (!str.find("add")) {
			int i = str.find(" ");
			//cout << i << endl;
			//int k = str.find("a", i+1);
			//cout << k << endl;
			arg = str.substr(i+1, str.length()-i);
			cout << arg << endl;
			ii = atoi(arg.c_str());
			//cout << ii << endl;
			stack.push(ii);
			
		}
		else if (!str.find("del")) {
			//cout << "del activated" << endl;
			stack.pop();
		}
		else if (!str.find("get")) {
			//cout << "get activated" << endl;
			cout << stack.pop() << endl;
		}
		else if (!str.find("exit")) {
			break;
		}
		else if (!str.find("help")) {
			cout << "programm 'stack'\nadd <arg> - add an <arg> in the stack\nget - show and pop the argument\ndel - delete argument\nhelp - show help \nexit - for exit" << endl;
		}
		
	}

	//system("pause");
	return 0;
}









/*
cout << "program" << endl;
Stack<char> stackSymbol(5);
int ct = 0;
char ch;

while (ct++ < 5)
{
cin >> ch;
stackSymbol.push(ch); // �������� �������� � ����
}

cout << endl;

stackSymbol.printStack(); // ������ �����

cout << "\n\nRemove items from the stack\n";
stackSymbol.pop();

stackSymbol.printStack(); // ������ �����

Stack<char> newStack(stackSymbol);

cout << "Activated copy constructor" << endl;
newStack.printStack();

cout << "The second item in the queue: " << newStack.Peek(2) << endl;

*/