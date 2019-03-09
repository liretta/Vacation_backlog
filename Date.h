#pragma once
#include "includes.h"
#include "Constants.h"

struct Data
{
	int day;
	int month;
	int year;
	Data();
	Data(string str);
	bool operator<=(const Data &d2) const;
	friend int& operator-(const Data &d1, const Data& d2);
	friend int& operator-(const Data &data, int a);
	friend int& operator-(int a, const Data &data);
};