#include "Header.h"

Region * FindReg(string str, vector<Region *> &r)
{
	for (int i(0); i < r.size(); i++) {
		if (r.at(i)->getName() == str) return r.at(i);
	}
	return nullptr;
}

Person * FindPers(string str, vector<Region*>& r) throw(MyException)
{
	if (str == "") throw MyException("wrong first arg");
	else if(r.size() == 0) throw MyException("secoind arg is empty");
	for (int i(0); i < r.size(); i++) {
		for (int j(0); j < r.at(i)->electorate.size(); j++) {
			if (str == r.at(i)->electorate.at(j)->getName()) {
				return r.at(i)->electorate.at(j);
			}
		}
	}
	return nullptr;
}

Person * FindCand(string str, vector<Person*>& v)
{
	for (int i(0); i < v.size(); i++) {
		if (str == v.at(i)->getName()) { return v.at(i); }
	}
	return nullptr;
}

void rmReg(Region * reg, vector<Region *>& v)
{
	for (int i(0); i < v.size(); i++) {
		if (reg->getName() == v.at(i)->getName()) {
			delete reg;
			v.erase(find(v.begin(), v.end(), reg));
			cout << "success" << endl;
		}
	}
}

void rmReg(string name, vector<Region *>& v)
{
	for (int i(0); i < v.size(); i++) {
		if (name == v.at(i)->getName()) {
			delete v.at(i);
			v.erase(find(v.begin(), v.end(), v.at(i)));
		}
	}
}

void rmCand(string name, vector<Person*>& v)
{
	for (int i(0); i < v.size(); i++) {
		if (name == v.at(i)->getName()) {
			v.erase(find(v.begin(), v.end(), v.at(i)));
		}
	}
}

void StartElections(vector<Region*>& v)
{
	for (int i(0); i < v.size(); i++) {
		v.at(i)->StartEl();
	}
}

void StopElections(vector<Region*>& v)
{
	for (int i(0); i < v.size(); i++) {
		v.at(i)->StopEl();
	}
}

void Stats(vector<Region*>& r)
{
	for (int i(0); i < r.size(); i++) {
		cout << "region " << r.at(i)->getName()<<endl;
		for (int j(0); j < r.at(i)->electorate.size(); j++) {
			cout << r.at(i)->electorate.at(j)->getName()
				<<" "<< r.at(i)->electorate.at(j)->getSname()<<" "
				<<" voted for: "<<
				r.at(i)->electorate.at(j)->getCname()<<endl;
		}
	}
}

void Save(vector<Region*>& reg, string name)
{
	string fstr = "";
	ofstream f1(name);
	for (int i(0); i < reg.size(); i++) {
		f1 << reg.at(i)->getName()<<endl;
		for (int j(0); j < reg.at(i)->electorate.size(); j++) {
			f1 << reg.at(i)->electorate.at(j)->getName()
				<< " "
				<< reg.at(i)->electorate.at(j)->getSname()
				<< endl;
		}
		f1 << "--eofreg" << endl;
	}
	f1 << "--eofregs" << endl;
	f1 << "--end" << endl;
	f1.close();
}
