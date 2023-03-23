#include "Person.h"
#include "customer.h"
#include "Mechanic.h"
#include "Queue.h"
#include <iostream>
#include <fstream>


using namespace std;

void sort(customer c[], int size) /*sorting the array of appointments using selection sort and the overloading operator functions in class customer*/
{
	
	for (int i = 0;i < size - 1;i++)
	{
		int minimumI = i;
		customer min = c[i];
		for (int j = i + 1;j < size;j++)
		{
			if (c[j] < min)
			{
				minimumI = j;
				min = c[minimumI];
			}
		}
		customer temp = c[minimumI];
		c[minimumI] = c[i];
		c[i] = temp;


	}
	
}
int h, mm;
appointment w;
void showAppointments(Queue<customer> k, int size1,int size2, Mechanic M[])/* display which customer is assigned with which mechanic and at what time*/
{
	customer p;
	for (int i = 0;i < size1;i++)
	{
		if (k.Dequeue(p))
		{
			for (int j = 0;j < size2;j++)
			{
				if (p.getMechanicid() == M[j].getID())
				{
					w = p.getT();
					h = w.hours;
					mm = w.minutes;
					
					cout << "Customer " << p.getName() << " has an appointment with " << M[j].getName() << " at a" << h << ":" << mm << endl;
				}
			}
		}
	}
}


int main(int argc, char* argv[])
{
	
	ifstream sz_file("size.txt"); /*add the files that serve as the input and data*/
	ifstream mech_file("Mechanic.txt");
	ifstream cust_file("customer.txt");

	int sizeM;
	cout << "Enter number of mechanics" << endl;
	sz_file >> sizeM; /*using size file to insert the data regarding the size*/
	cout << "Number of mechanics chosen " << sizeM << endl;;
	Mechanic* m;
	m = new Mechanic[sizeM];
	int sizeC;
	cout << "Enter number of customers" << endl;
	sz_file >> sizeC; /*using size file to insert the data regarding the size*/
	cout << "Number of cutomers chosen " << sizeC << endl;;
	customer* c;;
	c = new customer[sizeC];


	int nationid, age;
	string username;
	int hour = 0;
	int min = 0;
	appointment q;
	for (int i = 0;i < sizeC; i++)		/*use data in customers file to create customers objects*/
	{

		cout << "Please insert the customer's preffered appointment in hours and minutes" << endl;
		cout << " Also please insert the age, national ID, and surname" << endl;
		cust_file >> hour;
		cout << ":";
		cust_file >> min;
		cust_file >> age >> nationid >> username;
		q.hours = hour;
		q.minutes = min;
		c[i] = customer(q, age, nationid, username);
		
	}
	

	for (int i = 0;i < sizeM ; i++) /*use data in mechanics file to create mechanics objects*/
	{
		cout << "Enter national ID, age, and username for mechanic number" <<i<< endl;
		mech_file >> nationid >> age >> username;
		m[i] =Mechanic(sizeC,nationid,age,username);
	}


	bool check;
	for (int i = 0;i < sizeC; i++) /*set appointments of customers with the best fit mechanics*/
	{
		check = false;
		for (int j = 0;j < sizeM;j++)
		{
			if (m[j].isavailabe(c[i].getT()))
			{
			
				check = true;
				m[j].setappoint(c[i].getT());
				c[i].setMechanicID(m[j].getID());
					
				cout << "Customer number " << i + 1 << " has been assigned with mechanic number " << j + 1 << endl;
				break;
			}
			/*if (check = true)
				break;*/
		}
		if (!check)
		{
			cout << "No apppointment found for customer number " << i + 1 << "it will be canceled " << endl;

		}
		

	}

	for (int i = 0; i < sizeM;i++) /*updates how many customers each mechanic has*/
	{
		m[i].setCount(m[i].getindex()+1);
	}

	for (int i = 0;i < sizeC; i++) 
	{
		sort(c, sizeC);
	}

	Queue<customer> q2(sizeC); /*create queue */

	for (int i = 0;i < sizeC;i++)
		if(q2.Enqueue(c[i])); /*enqueue the sorted array of appointments using the class queue */

	showAppointments(q2, sizeC, sizeM, m); /*call function above*/
}
