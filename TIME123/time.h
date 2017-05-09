#pragma once
#include <iostream>
#include <ostream>
using namespace std;


class cTime
{
	int hour, minute, second;
public:
	cTime();
	cTime(int h, int m, int s);
	~cTime();

	int get_hour();
	int get_minute();
	int get_second();

	const int get_hour() const;

	const int get_minute() const;

	const int get_second() const;


	void set_hour(int hour_);
	void set_minute(int minute_);
	void set_second(int second_);
	
	void display_time();
	
	cTime operator+(const cTime& t);
	cTime operator-(const cTime& t);
	cTime operator*(const int &i);
	friend ostream& operator<<(ostream& os, const cTime& dt);
	friend istream& operator>> (istream& is, cTime& dt);
};

