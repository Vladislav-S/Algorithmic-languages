#include <iostream>
#include <string>

class employee {
protected:
	std::string FIO;
	int Salary;
	int Premium;
	int XP;
public:
	employee();
	employee(std::string, int);
	virtual ~employee();
	int count_Salary();
	int count_Premium();
	virtual void Print();

	std::string GetFIO();
	int GetSalary();
	int GetPremium();

};

class Chief: public employee {
protected:
	int CPremium;
public:
	Chief();
	Chief(std::string, int);
	~Chief();
	int count_Salary();
	int count_Premium();
	void Print();
};