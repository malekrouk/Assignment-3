#pragma once
#include <iostream>
using namespace std;
struct appointment
{
	int hours;
	int minutes;

};


class Person
{
private:
	int ID;
	int age;
	string name;
protected:
	
public:

	Person();
	Person(int z,int x, string j);
	void print();
	int getID();
	int getAge();
	string getName();
	void setID(int i);
	void setAge(int g);
	void setName(string y);
};


