#include "Header.h"

vector<Region *> regs;
bool elections = false;
vector<Person *> cands;

int main() {
	string str = "";
	vector<string> vect;
	cout << "---------- Vlado's homework ----------" << endl;
	cout << "---------- type 'man' for more information ----------" << endl;

	//----- цикл обработки сообщений
	while (str != "exit") {
		cout << ">>>"; getline(cin, str);
		vect = split(str, " "); if (vect.size() == 0) continue;

		//----- блок обработки команд
		//--------------------------------------------
		//----- Создание нового избирательного участка
		if (vect.at(0) == "mkreg") {
			try
			{
				if (vect.size() == 1) throw MyException(1);
				else if (vect.size() > 2) throw MyException(5);
				else if (FindReg(vect.at(1), regs) != nullptr) throw MyException("region already exists");
				cout << "success" << endl;
				regs.push_back(new Region(vect.at(1)));

			}
			catch (const std::exception& ex)
			{
				cout << ex.what() << endl;
			}
			catch (MyException& exx) {
				cout <<"ERROR: "<<exx.MSG() << endl;
			}
			
		}
		//----- Вывод списка регионов
		if (vect.at(0) == "listp") {
			try
			{
				if (regs.size() == 0) throw MyException("No regions");
				for (int i(0); i < regs.size(); i++) {
					cout << i << " - " << regs.at(i)->getName() << endl;
				}
			}
			catch (const std::exception& ex)
			{
				cout <<ex.what() << endl;
			}
			catch (MyException& exx) {
				cout << "ERROR: " << exx.MSG() << endl;
			}
			
		}
		//----- Вывод списка кандидатов
		if (vect.at(0) == "listc") {
			try
			{
				if (!elections)throw MyException(4);
				else if (cands.size() == 0) throw MyException("no candidates");
				for (int i(0); i < cands.size(); i++) {
					cout << i << " - " << cands.at(i)->getName() << endl;
				}
			}
			catch (const std::exception& ex)
			{
				cout << ex.what() << endl;
			}
			catch (MyException& exx) {
				cout << "ERROR: " << exx.MSG() << endl;
			}
			
		}
		//----- Вывод списка избирателей в регионе
		if (vect.at(0) == "list") {
			try
			{
				if (vect.size() == 1) throw MyException(1);
				else if (vect.size() > 2) throw MyException(5);
				else if (FindReg(vect.at(1), regs) == nullptr) throw MyException("No such region");
				FindReg(vect.at(1), regs)->Print();
			}
			catch (const std::exception& ex)
			{
				cout << ex.what() << endl;
			}
			catch (MyException& exx) {
				cout << "ERROR: " << exx.MSG() << endl;
			}
			
		}
		
		if (vect.at(0) == "add") {
			//----- Добавление избирателя на участок
			try
			{
				if (vect.at(1) == "person") {
					if (vect.size() < 5) throw MyException(3);
					else if (FindReg(vect.at(2), regs) == nullptr) throw MyException(1);
					FindReg(vect.at(2), regs)->addPerson(vect.at(3), vect.at(4));
					
				}
				if (vect.at(1) == "candidate") {
					if (!elections) throw MyException(4);
					else if (FindPers(vect.at(2), regs) == nullptr) throw MyException(2);
					Person * temp = FindPers(vect.at(2), regs);
					temp->SetCand(true);
					cands.push_back(temp);
				}
			}
			catch (const std::exception& ex)
			{
				cout << ex.what() << endl;
			}
			catch (MyException& exx) {
				cout << "ERROR: " << exx.MSG() << endl;
			}
			
		}
		//----- Удаление элементов
		if (vect.at(0) == "rm") {
			try
			{
				if (vect.at(1) == "person") {
					if (FindPers(vect.at(2), regs) == nullptr) throw MyException(2);
					else if (vect.size() < 3) throw MyException(6);
					else if (vect.size() > 3) throw MyException(5);
					for (int i(0); i < regs.size(); i++) {
						regs.at(i)->removePerson(vect.at(2));
					}
				}
				if (vect.at(1) == "region") {
					if (FindReg(vect.at(2), regs) == nullptr) throw MyException(1);
					else if (vect.size() < 3) throw MyException(6);
					else if (vect.size() > 3) throw MyException(5);
					rmReg(vect.at(2), regs);
				}
				if (vect.at(1) == "candidate") {
					if (!elections) throw MyException(4);
					else if (vect.size() < 3) throw MyException(6);
					else if (vect.size() > 3) throw MyException(5);
					else if (FindCand(vect.at(2), cands) == nullptr)throw MyException("Invalid Candidate");
					rmCand(vect.at(2), cands);
				}
			}
			catch (const std::exception& ex)
			{
				cout << ex.what() << endl;
			}
			catch (MyException& exx) {
				cout << "ERROR: " << exx.MSG() << endl;
			}
			
		}
		//----- Слияние участков
		if (vect.at(0) == "merge") {
			try
			{
				if (vect.size() > 2) throw MyException(5);
				else if (vect.size() < 2) throw MyException(6);
				vect = split(vect.at(1), ">");
				if (vect.size() > 2) throw MyException(5);
				else if (vect.size() < 2) throw MyException(6);
				regs.at(stoi(vect.at(1)))->Merge(regs.at(stoi(vect.at(0))));//само проверит на выход за границы
				rmReg(regs.at(stoi(vect.at(0))), regs);
			}
			catch (const std::exception& ex)
			{
				cout << ex.what() << endl;
			}
			catch (MyException& exx) {
				cout << "ERROR: " << exx.MSG() << endl;
			}

		}
		//----- Старт выборов
		if (vect.at(0) == "start") {
			try
			{
				if (elections == true) throw MyException("Elections are already");
				elections = true;
				StartElections(regs);
			}
			catch (const std::exception& ex)
			{
				cout << ex.what() << endl;
			}
			catch (MyException& exx) {
				cout << "ERROR: " << exx.MSG() << endl;
			}

		}
		//----- Конец выборов
		if (vect.at(0) == "stop") {
			try
			{
				if (elections == false) throw MyException("Elections are not going now");
				elections = false;
				StopElections(regs);
				for (int i(0); i < cands.size(); i++) {
					cout << cands.at(i)->getName() <<
						" has: " << cands.at(i)->getVotes() << " votes" << endl;
				}
				cands.clear();
			}
			catch (const std::exception& ex)
			{
				cout << ex.what() << endl;
			}
			catch (MyException& exx) {
				cout << "ERROR: " << exx.MSG() << endl;
			}

		}
		//----- Голосование
		if (vect.at(0) == "vote") {
			try
			{
				if (vect.size() > 3) throw MyException(5);
				else if (vect.size() < 3) throw MyException(6);
				else if (FindPers(vect.at(1), regs) == nullptr) throw MyException(2);
				else if (FindCand(vect.at(2), cands) == nullptr) throw MyException("Invalid Candidate");

				Person * temp1 = FindPers(vect.at(1), regs);
				Person * temp2 = FindCand(vect.at(2), cands);
				temp1->Vote(temp2);
			}
			catch (const std::exception& ex)
			{
				cout << ex.what() << endl;
			}
			catch (MyException& exx) {
				cout << "ERROR: " << exx.MSG() << endl;
			}

		}
		//----- Вызов статистики по участкам
		if (vect.at(0) == "stats") {
			try
			{
				Stats(regs);
			}
			catch (const std::exception& ex)
			{
				cout << ex.what() << endl;
			}
			catch (MyException& exx) {
				cout << "ERROR: " << exx.MSG() << endl;
			}
			
		}
		//----- Загрузка данных из файла
		if (vect.at(0) == "load") {
			try
			{
				if (vect.size() < 2) throw MyException(6);
				else if (vect.size() > 2) throw MyException(5);
				else if (vect.at(1).find(".txt") == -1) throw MyException("Wrong format");
				string fstr = "";
				ifstream f1;
				f1.open(vect.at(1));
				vector<string> tv;
				string treg;
				while (fstr != "--end") {
					while (fstr != "--eofregs") {
						getline(f1, fstr);
						if (fstr == "--eofregs") break;
						regs.push_back(new Region(fstr));
						treg = fstr;
						while (fstr != "--eofreg") {
							getline(f1, fstr);
							if (fstr == "--eofreg") break;
							tv = split(fstr, " ");
							FindReg(treg, regs)->addPerson(tv.at(0), tv.at(1));
						}
					}
					getline(f1, fstr);
				}
				f1.close();
			}
			catch (const std::exception& ex)
			{
				cout << ex.what() << endl;
			}
			catch (MyException& exx) {
				cout << "ERROR: " << exx.MSG() << endl;
			}
		}
		//----- Сохранение данных в текстовый файл
		if (vect.at(0) == "save") {
			try
			{
				if (vect.size() < 2) throw MyException(6);
				else if (vect.size() > 2) throw MyException(5);
				else if (vect.at(1).find(".txt") == -1) throw MyException("Wrong format");
				Save(regs, vect.at(1));
			}
			catch (const std::exception& ex)
			{
				cout << ex.what() << endl;
			}
			catch (MyException& exx) {
				cout << "ERROR: " << exx.MSG() << endl;
			}
			
		}
		if (vect.at(0) == "ca") {
			try
			{
				if (regs.size() == 0) throw MyException("Data already clear");
				for (int i(0); i < regs.size(); i++) {
					delete regs.at(i);
				}
				regs.clear();
				cout << "all data cleared" << endl;
			}
			catch (const std::exception& ex)
			{
				cout << ex.what() << endl;
			}
			catch (MyException& exx) {
				cout << "ERROR: " << exx.MSG() << endl;
			}

		}
		//----- вызов справки
		if (vect.at(0) == "man") {
			try
			{
				string fstr = "";
				ifstream f1;
				f1.open("man.txt");
				while (fstr != "-end") {
					getline(f1, fstr);
					if (fstr == "-end") break;
					cout << fstr << endl;
				}
				f1.close();
			}
			catch (const std::exception& ex)
			{
				cout << ex.what() << endl;
			}

		}

	}
	return 0;
}