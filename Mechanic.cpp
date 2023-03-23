#include "Mechanic.h"

Mechanic::Mechanic()
{
	count = 0;
    index = 0;
}
Mechanic::Mechanic(int num) {
	count = 0;
	arr = new appointment[num];
    index = 0;
}
Mechanic::Mechanic(int num, int lifeID, int agee, string surname) : Person(lifeID, agee, surname)
{
    count = 0;
    arr = new appointment[num];
    index = 0;
}
bool Mechanic::isavailabe(appointment u)
{
    int f = 0, k = 0, y = 0, j = 0;
    if (u.minutes < 20)
    {
        y = u.hours - 1;
        int rem = 20 - u.minutes;
        f = 60 - rem;
        j = u.minutes + 40;
        k = u.hours;
        j = u.minutes;
    }
    else if (u.minutes)
    {
        k = u.hours + 1;
        int rem = 60 - u.minutes;
        j = 20 - rem;
        f = u.minutes - 40;
        y = u.hours;
        f = u.minutes;
    }
    else if (u.minutes >= 20 && u.minutes <= 40)
    {
        y = u.hours;
        k = u.hours;
        f = u.minutes - 20;
        j = u.minutes + 20;
    }

    for (int i = 0; i < 4; i++)
    {
        if (arr[i].hours >= y && arr[i].hours <= k)
        {
            if (arr[i].hours > y && f - arr[i].minutes <= 40)
            {
                return false;
            }
            if (arr[i].hours < k && arr[i].minutes - j <= 40)
            {
                return false;
            }
            if (y == arr[i].hours && arr[i].minutes - f <= 20)
            {
                return false;
            }
            if (k == arr[i].hours && j - arr[i].minutes <= 20)
            {
                return false;
            }
        }
    }
    return true;
}
void Mechanic:: setCount(int o)
{
    count = o;
}

void Mechanic::incrementCount()
{
    count++;
}
int Mechanic::getCount()
{
    return count;
}

void Mechanic::setindex(int i)
{
    index = i;
}

int Mechanic::getindex()
{
    return index;
}
void Mechanic::setappoint(appointment r)
{
    
        arr[index] = r;
        index++;
    
}

//void Mechanic::setarray(appointment array[], int s)
//{
//   for(int arr)
//}
appointment* Mechanic::getarray()
{
    return arr;
}