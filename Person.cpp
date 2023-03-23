#include "Person.h"

	Person::Person()
	{
		ID = 0;
		age = 0;
		name = "";
	}
	Person::Person(int z, int x, string j)
	{
		ID =z ;
		age = x;
		name = j;

	}
	void Person::print()
	{
		cout << "The name is " << name << " and his/her ID is " << ID << " and his/her age is " << age;
	}
	int Person::getID()
	{
		return ID;
	}
	int Person::getAge()
	{
		return age;
	}
	string Person::getName()
	{
		return name;
	}
	void Person:: setID(int i)
	{
		ID = i;
	}
	void Person:: setAge(int g)
	{
		age = g;
	}
	void Person::setName(string y)
	{
		name = y;
	}
