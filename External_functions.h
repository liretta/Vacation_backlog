#pragma once
#include "includes.h"
#include "Constants.h"

 
void NewBalanceCalculation(vector<Employee> & empl, const Data& date)
{
	int n = empl.size();
	for (int i = 0; i < n; ++i)
	{
		if (empl[i].mStartLastPeriod < date)
			if (date <= empl[i].mEndLastPeriod)
			{
				double oldBalance = double(OLD_BALANCE) / double(DAY_ON_YEAR) * (date - 1 - empl[i].mStartLastPeriod);
				double nextBalance = double(NEW_BALANSE) / double(DAY_ON_YEAR) * (empl[i].mEndLastPeriod - date);
				double newBalance = abs(oldBalance) + abs(nextBalance);
				newBalance = floor(newBalance + 0.55555555);
				empl[i].mVacationBalance = newBalance;
			}	
	}
}

void Mem()
{
	if (_CrtDumpMemoryLeaks())
		cout << "Mem leaks!" << endl;
	else
		cout << "Mem ok :-)" << endl;
}

int dateToInt(const Data&d)
{
	int result = 0;
	for (int i = 0; i < d.month - 1; ++i)
		result += DAY_ON_MONTH[i];

	result += d.year * 365;
	result += d.day;
	return result;
}

int& operator-(const Data &d1, const Data&d2)
{
	int result = dateToInt(d1) - dateToInt(d2);
	return result;
}

int& operator-(const Data &date, int a)
{
	int result = dateToInt(date) - a;
	return result;
}

int& operator-(int a, const Data &date)
{
	return date-a;
}

bool checkDateFormat(string &date)
{
	if (date.size() != int(DATALENGHT))
		return false;

	if (find(date.begin(), date.end(), '.') == date.end())
		return false;
	return true;
}