#include "time.h"


cTime::cTime()
{
	hour = 1;
	minute = 1;
	second = 1;
}

cTime::cTime(int h, int m, int s)
{
	hour = h;
	minute = m;
	second = s;
}

cTime::~cTime()
{
}

int cTime::get_hour()
{
	return this->hour;
}

int cTime::get_minute()
{
	return this->minute;
}

int cTime::get_second()
{
	return this->second;
}

const int cTime::get_hour() const
{
	return this->hour;
}

const int cTime::get_minute() const
{
	return this->minute;
}

const int cTime::get_second() const
{
	return this->second;
}

void cTime::set_hour(int hour_)
{
	hour = hour_;
}

void cTime::set_minute(int minute_)
{
	if (minute_ > 59) {
		hour = hour + 1;
		minute = minute_ - 60;
	}
	else {
		minute = minute_;
	}
}

void cTime::set_second(int second_)
{
	if (second_ > 59) {
		minute = minute + 1;
		second = second_ - 60;
	}
	else {
		second = second_;
	}
}

void cTime::display_time()
{
	/*if (second > 59) {
		minute = minute + 1;
		second = second - 60;
	}
	if (minute > 59) {
		hour = hour + 1;
		minute = minute - 60;
	}*/

	cout << "  "<< hour << ":" << minute << ":" << second << endl;
}

cTime cTime::operator+(const cTime & t)
{
	cTime  temp;
	temp.hour = this->hour + t.hour;
	temp.minute = this->minute + t.minute;
	temp.second = this->second + t.second;

	if (temp.second > 59) {
		temp.minute = temp.minute + 1;
		temp.second = temp.second - 60;
	}
	if (temp.minute > 59) {
		temp.hour = temp.hour + 1;
		temp.minute = temp.minute - 60;
	}

	return temp;
}

cTime cTime::operator-(const cTime & t)
{
	int  temp1 = this->hour * 3600 + this->minute * 60 + this->second;
	int  temp2 = t.hour * 3600 + t.minute * 60 + t.second;
	int result = temp1 - temp2;
	int m = result / 60;
	int h= m / 60;
	int s = result % 60;
	cTime temp(h,m%60,s);
	return temp;
}

cTime cTime::operator*(const int & i)
{
	cTime temp;
	if (i == -1) {
		temp.hour = -hour;
		temp.minute = -minute;
		temp.second = -second;
	}
	else {
		temp.hour = hour;
		temp.minute = minute;
		temp.second = second;
	}

	return temp;
}

//ostream & operator<<(ostream & os, const cTime & dt)
ostream& operator<<(ostream& os, const cTime & dt)
{
	cTime temp = dt;
	if (temp.second > 59) {
		temp.minute = temp.minute + 1;
		temp.second = temp.second - 60;
	}
	if (temp.minute > 59) {
		temp.hour = temp.hour + 1;
		temp.minute = temp.minute - 60;
	}
	os <<"\t"<< temp.hour << ":" << temp.minute << ":" << temp.second << endl;
	return os;
}

istream & operator >> (istream & in, cTime & dt)
{
	char r;
	in >> dt.hour >> r;
	in >> dt.minute >> r;
	in >> dt.second;
	return in;
}
