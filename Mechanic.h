#pragma once
#include "Person.h"
class Mechanic:public Person
{
private:
	int count; /*every object of class mechanic has the member values count in order to know how many customers they have, and an 
	array that has their appointments for the day. Plus index that is set to zer. In addition, it inhertis the member varibales in class person*/
	appointment* arr;
	int index = 0;


public:
	Mechanic(); /*default constructor*/
	Mechanic(int num); /*initizalizes count with num and uses count as the size of the appointments array*/
	Mechanic(int count, int lifeID, int agee, string surname); /* similar to the line above but in addition initializes id, age, and name*/
	bool isavailabe(appointment u); /*checks if there is clash with apppointments 20 mins before and after*/
	void setCount(int o); /*sets count to integer o*/
	int getCount(); /*returns count*/
	void setindex(int i);	/*sets index to integer i*/
	int getindex(); /*returns index*/
	void incrementCount(); /*increments count by 1*/
	void setappoint(appointment r);	/*inserts and appointment r in the array of appointments*/
	
	appointment* getarray(); /*returns the pointer to the array*/


};

