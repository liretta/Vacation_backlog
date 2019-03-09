#pragma once
#include "includes.h"
#include "Date.h"

struct Employee
{
	int mNumber;
	int mVacationBalance;
	Data mHiringData;
	Data mStartLastPeriod;
	Data mEndLastPeriod;

	Employee();
	Employee(Data data, int numb = 0, int vacBalance = 24);
	void SetStartPeriod(const Data& date); //get date for calculate and finds last working period
};
