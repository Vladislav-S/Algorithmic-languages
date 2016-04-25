#include "Header.h"

MyException::MyException() {
	msg = "ERROR";
}

MyException::MyException(string m) {
	msg = m;
}

MyException::MyException(int i) {
	switch (i)
	{
	case 1:
		msg = "Unknown Region";
		break;
	case 2:
		msg = "Unknown Person";
		break;
	case 3:
		msg = "Invalid name or surname";
		break;
	case 4:
		msg = "elections have not started";
		break;
	case 5:
		msg = "too much args";
		break;
	case 6:
		msg = "too few arguments";
	default:
		break;
	}
}

string MyException::MSG()
{
	return msg;
}
