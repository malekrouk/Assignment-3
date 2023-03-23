#pragma once
#include <iostream>
#include "Person.h"
using namespace std;
class customer :public Person
{
private:
	int mechanicid;   /*every object of class customer has the member values mechanic ID in order to match with their mechanic and their preffered appointment time, 
		plus the vairables inherited from class person*/
	appointment t;

public:
	customer(); /*default constructor*/
	customer( appointment w, int agee, int lifeID, string surname); /*initializes the appointment,age,ID, and name*/
	void setMechanicID(int l); /*stores integer l in member variable mechanic ID of the customer*/
	int getMechanicid(); /*returns the mechanic id member variable saved in the object customer*/
	void setT(int h, int m); /*sets appointment in the customer using integeres of hours and minutes*/
	appointment getT(); /*returns appointment */
	bool operator <(const customer& c1);	/*overloading operators that helpwhen sorting the array of appointments*/
	bool operator >(const customer& c1);
	bool operator ==(const customer& c1);
	void sethour(int ho);/* set the hour of the appointment*/ 
	void setmin(int minu); /*sets the minute of the appointment*/
	int gethour(); /*returns the hour of the appointment*/
	int getmin(); /*returns the minute of the appointment*/

};

