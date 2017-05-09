// TIME123.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "stdafx.h"
#include "time.h"
using namespace std;

int main()
{
	cout << "Time calculator vol 2 kupa"<<endl;
	cout << "Enter data in format hh:mm:ss"<<endl;
	char sign = 'a';
	int one = 1;
	cTime comp;
	cTime sum(0, 0, 0);
	while (sign != 'n') {
		
		cout << "Enter time:" << endl;
		cin >> comp;
		if (sign == '+') one = 1;
		if (sign == '-') one = -1;
		sum = sum + comp *one;
		cout << sum << endl;
		cout << "+ / -? Or end 'n'" << endl;
		cin >> sign;
	}

    return 0;
}

