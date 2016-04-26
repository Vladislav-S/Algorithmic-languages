#include "Header.h"

Person::Person() {
	name = "unnamed";
	sname = "unnamed";
	voted = false;
	cand = false;
	votes = 0;
}

Person::Person(string n, string sn)
{
	name = n;
	sname = sn;
	voted = false;
	cand = false;
	votes = 0;
}

Person::Person(const Person & p)
{
	name = p.name;
	sname = p.sname;
	voted = p.voted;
	cand = false;
	votes = 0;
}


string Person::getName()
{
	return name;
}

string Person::getSname()
{
	return sname;
}

string Person::getCname()
{
	return cname;
}

int Person::getVotes()
{
	return votes;
}

void Person::SetCand(bool b)
{
	cand = b;
}

void Person::Vote(Person * p)
{
	voted = true;
	p->IncVote();
	cname = p->getName();
}

int Person::IncVote()
{
	votes++;
	return votes;
}

