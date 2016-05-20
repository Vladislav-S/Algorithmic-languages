#include "Header.h"


//------------------- class employee ---------------------
//------------------- constructors   ---------------------
employee::employee(){FIO = ""; Salary=0; Premium=0; XP=0; Print();}
employee::employee(std::string s, int x_p){
	FIO = s; 
	XP = x_p;
	Salary = employee::count_Salary(); 
	Premium = employee::count_Premium();
	Print();
}

employee::~employee(){std::cout << "\nemployee deleted ";}
//------------------- functions      ---------------------
int employee::count_Salary(){return 25000*employee::XP;}
int employee::count_Premium(){return 5000*employee::XP;}
void employee::Print(){
	std::cout << "Employee: " << FIO <<
		", Salary: " << GetSalary() << 
		", Premium: " << GetPremium() << "\n";
}

//------------------- Get --------------------------------
std::string employee::GetFIO(){return FIO;}
int employee::GetPremium(){return employee::Premium;}
int employee::GetSalary(){return employee::Salary;}



//------------------- class Chief ------------------------
//------------------- constructors -----------------------
Chief::Chief():employee(){Chief::CPremium = 0; Print();}
Chief::Chief(std::string s, int x_p):employee(s, x_p){
	Chief::CPremium = Chief::count_Salary()/50; Print();
}
Chief::~Chief(){std::cout << "\nChief deleted ";}

//------------------- functions --------------------------
int Chief::count_Salary(){return 36000*Chief::XP;}
int Chief::count_Premium(){return Chief::XP*3000;}
void Chief::Print(){
	employee::Print();
	std::cout << " -Chief" << "\n";
}