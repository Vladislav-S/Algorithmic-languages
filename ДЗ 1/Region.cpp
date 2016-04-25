#include "Header.h"

Region::Region() {
	name = "default";
	elections = false;
}

Region::Region(string nname)
{
	name = nname;
	elections = false;
}

Region::Region(string nname, vector<Person *> p)
{
	name = nname;
	electorate = p;
	elections = false;
}

Region::Region(Region * r)
{
	name = r->name;
	electorate = r->electorate;
	elections = r->elections;
}

Region::Region(const Region & r)
{
	name = r.name;
	electorate = r.electorate;
	elections = r.elections;
}

Region::~Region()
{
	for (int i(0); i < electorate.size(); i++) {
		delete electorate.at(i);
	}
}

string Region::getName()
{
	return name;
}

Person * Region::addPerson(string n, string sn)
{
	Person * temp = new Person(n, sn);
	electorate.push_back(temp);
	return temp;
}

void Region::removePerson(string n)
{
	for (int i(0); i < electorate.size(); i++) {
		if (electorate.at(i)->getName() == n) {
			delete electorate.at(i);
			electorate.erase(find(electorate.begin(), electorate.end(), electorate.at(i)));
		}
	}
}

void Region::Merge(Region * reg)
{
	for (int i(0); i < reg->electorate.size(); i++) {
		electorate.push_back(reg->electorate.at(i));
	}
}



void Region::Print()
{
	if (electorate.size() == 0) { cout << "Region is empty" << endl; return; }
	for (int i(0); i < electorate.size(); i++) {
		cout << electorate.at(i)->getName() <<" "<< electorate.at(i)->getSname() <<endl;
	}
	return;
}

void Region::StartEl()
{
	elections = true;
}

void Region::StopEl()
{
	elections = false;
}
