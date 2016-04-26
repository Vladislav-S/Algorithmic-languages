#include "Header.h"

MyException::MyException() {
	msg = "ERROR";
}

MyException::MyException(string m) {
	msg = m;
}

MyException::MyException(int i) { // Это не путь C++. 
	// Путь с++: одна ошибка -- один класс ошибки.
	switch (i)
	{
	// Для этого есть enum
	case 1:
		msg = "Unknown Region"; // class BadParamsError
		break;
	case 2:
		msg = "Unknown Person"; // class BadParamsError
		break;
	case 3:
		msg = "Invalid name or surname"; // class BadParamsError
		break;
	case 4:
		msg = "elections have not started"; // // class InvalidStateError
		break;
	case 5:
		msg = "too much args"; // class ParsingError
		break;
	case 6:
		msg = "too few arguments"; // class ParsingError
	default:
		break;
	}
}

string MyException::MSG()
{
	return msg;
}
