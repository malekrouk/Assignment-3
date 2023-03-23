#include "customer.h"
customer::customer(appointment w,  int lifeID, int agee, string surname): Person(lifeID,agee,surname)
{
    mechanicid = 0;
    t = w;
}
customer::customer()
{
    
}

void customer:: setMechanicID(int l)
{
	mechanicid = l;
}
int customer::getMechanicid()
{
	return mechanicid;
}
void customer:: setT(int h, int m)
{
    t.hours = h;
    t.minutes = m;
}
appointment customer::getT()
{
    return t;
}

bool customer::operator <( const customer& c1)
{
    bool boolean;
    if (this->t.hours<c1.t.hours) 
        return boolean = true;
    else if (this->t.hours == c1.t.hours)
    {
        if (this->t.minutes < c1.t.minutes)
            return true;
        else 
            return false;
    }
    else
        return boolean = false;
}
bool customer:: operator >(const customer& c1)
{
    bool boolean;
    if (this->t.hours > c1.t.hours)
        return boolean = true;
    else if (this->t.hours == c1.t.hours)
    {
        if (this->t.minutes > c1.t.minutes)
            return true;
        else
            return false;
    }
    else
        return boolean = false;
}
bool customer:: operator ==(const customer& c1)
{
    bool boolean;
    if (this->t.hours == c1.t.hours && this->t.minutes == c1.t.minutes)
        return boolean = true;
    else
        return boolean = false;
}

int customer::gethour()
{
    return t.hours;
}

int customer::getmin()
{
    return t.minutes;
}

void customer::sethour(int ho)
{
    t.hours = ho;
}

void customer::setmin(int minu)
{
    t.minutes = minu;
}