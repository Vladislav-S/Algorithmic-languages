#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

std::vector<std::string>  split(std::string str, std::string splt);


class Person{ //класс гражданина
	string name;
	string sname;
	bool voted;
	bool cand;
	int votes;
	string cname;
public:
	Person();
	Person(string n, string sn);
<<<<<<< HEAD
=======
	// Зачем такой нужен?
	//Person(Person *);
>>>>>>> origin/master
	Person(const Person&);
	

	string getName();
	string getSname();
	string getCname();
	int getVotes(); //Если кандидат - вернет количество собраных голосов
	void SetCand(bool); //сделать кандидатом
	void Vote(Person *); //если не кандидат - проголосовать
	int IncVote(); //если кандидат - увеличить кол-во голосов на 1
};

class Region { //класс региона
	string name;
	vector<Person *> electorate; //вектор, содержащий указатели на граждан
	bool elections; //проверка состояния выборов
	
public:
	Region();
	Region(string name);
	Region(string name, vector<Person *> p);
<<<<<<< HEAD
=======
	// Зачем такой нужен?
	//Region(Region *);
>>>>>>> origin/master
	Region(const Region&);
	~Region();
	string getName();
	
	Person * addPerson(string n, string sn);
	void removePerson(string n);
	void Merge(Region *); //для слияния
	void Print();
	void StartEl(); //начать выборы
	void StopEl(); //закончить выборы

	friend Person * FindPers(string, vector<Region*>& r); //найти человека, вернуть его указатель
	friend void Stats(vector<Region *> &r); //вывести статистику голосования
	friend void Save(vector<Region *> &reg, string name); //сохранить регион в текстовый файл
};

class MyException { //класс для обработчика ошибок
	string msg;

public:
	MyException();
	MyException(string);
	MyException(int);

	string MSG();
};


Region * FindReg(string, vector<Region *> &r); //функция посика региона
<<<<<<< HEAD
Person * FindPers(string, vector<Region *> &r); //функция поиска избирателя
=======
Person * FindPers(string, vector<Region *> &r); //throw(MyException); //функция поиска избирателя
>>>>>>> origin/master
Person * FindCand(string, vector<Person *> &v); //функция посика кандидата
void rmReg(Region * reg, vector<Region *> &v); //ф-я удаления региона
void rmReg(string name, vector<Region *> &v); //ф-я удаления региона (перегрузка)
void rmCand(string name, vector<Person *> &v); //ф-я удаления кандидата
void StartElections(vector<Region *> &v); //начало выборов
void StopElections(vector<Region *> &v); //конец выборов
void Stats(vector<Region *> &r); //вывод статистики
void Save(vector<Region *> &reg, string name); //сохранение в файл