#include <cassert> // для assert
#include <iostream>
#include <string>
#include <iomanip> // для setw
#include "stdio.h"
/** 
@mainpage программа, реализующая Стек
@brief template class Stack
@detailed шаблонный класс, реализующий стек с помощью  указателей 
*/

template <typename T>
class Stack
{
private:
	T *stackPtr;                      // указатель на стек
	const int size;                   // максимальное количество элементов в стеке
	int top;                          // номер текущего элемента стека
public:
	Stack(int = 10);                  // по умолчанию размер стека равен 10 элементам
	Stack(const Stack<T> &);          // конструктор копирования
	~Stack();                         // деструктор

	inline void push(const T &);     // поместить элемент в вершину стека
	inline T pop();                   // удалить элемент из вершины стека и вернуть его
	inline void printStack();         // вывод стека на экран
	inline const T &Peek(int) const; // n-й элемент от вершины стека
	inline int getStackSize() const;  // получить размер стека
	inline T *getPtr() const;         // получить указатель на стек
	inline int getTop() const;        // получить номер текущего элемента в стеке
};

// реализация методов шаблона класса STack

// конструктор Стека
template <typename T>
Stack<T>::Stack(int maxSize) :
	size(maxSize) // инициализация константы
{
	stackPtr = new T[size]; // выделить память под стек
	top = 0; // инициализируем текущий элемент нулем;
}

// конструктор копирования
template <typename T>
Stack<T>::Stack(const Stack<T> & otherStack) :
	size(otherStack.getStackSize()) // инициализация константы
{
	stackPtr = new T[size]; // выделить память под новый стек
	top = otherStack.getTop();

	for (int ix = 0; ix < top; ix++)
		stackPtr[ix] = otherStack.getPtr()[ix];
}

// функция деструктора Стека
template <typename T>
Stack<T>::~Stack()
{
	delete[] stackPtr; // удаляем стек
}

// функция добавления элемента в стек
template <typename T>
inline void Stack<T>::push(const T &value)
{
	// проверяем размер стека
	assert(top < size); // номер текущего элемента должен быть меньше размера стека

	stackPtr[top++] = value; // помещаем элемент в стек
}

// функция удаления элемента из стека
template <typename T>
inline T Stack<T>::pop()
{
	// проверяем размер стека
	assert(top > 0); // номер текущего элемента должен быть больше 0

	return stackPtr[--top]; // удаляем элемент из стека
}

// функция возвращает n-й элемент от вершины стека
template <class T>
inline const T &Stack<T>::Peek(int nom) const
{
	//
	assert(nom <= top);

	return stackPtr[top - nom]; // вернуть n-й элемент стека
}

// вывод стека на экран
template <typename T>
inline void Stack<T>::printStack()
{
	for (int ix = top - 1; ix >= 0; ix--)
		cout << "|" << setw(4) << stackPtr[ix] << endl;
}

// вернуть размер стека
template <typename T>
inline int Stack<T>::getStackSize() const
{
	return size;
}

// вернуть указатель на стек (для конструктора копирования)
template <typename T>
inline T *Stack<T>::getPtr() const
{
	return stackPtr;
}

// вернуть размер стека
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
stackSymbol.push(ch); // помещаем элементы в стек
}

cout << endl;

stackSymbol.printStack(); // печать стека

cout << "\n\nRemove items from the stack\n";
stackSymbol.pop();

stackSymbol.printStack(); // печать стека

Stack<char> newStack(stackSymbol);

cout << "Activated copy constructor" << endl;
newStack.printStack();

cout << "The second item in the queue: " << newStack.Peek(2) << endl;

*/