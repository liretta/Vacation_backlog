#include "Employee.h"

Employee::Employee()
{
	mNumber = 0;
	mVacationBalance = 24;
	mHiringData.day = 1;
	mHiringData.month = 1;
	mHiringData.year = 2000;
	mStartLastPeriod = mHiringData;
	mEndLastPeriod = mHiringData;
	mEndLastPeriod.year++;
}

Employee::Employee(Data data, int numb, int vacBalance)
	: mNumber(numb), mHiringData(data), mVacationBalance(vacBalance), mStartLastPeriod(data)
{
	mEndLastPeriod.day = mStartLastPeriod.day;
	mEndLastPeriod.month = mStartLastPeriod.month;
	mEndLastPeriod.year = mStartLastPeriod.year + 1;
}

void Employee::SetStartPeriod(const Data& date)
{
	mStartLastPeriod.day = mHiringData.day;
	mStartLastPeriod.month = mHiringData.month;
	if (mHiringData.month < date.month)
	{
		if (mHiringData.year <= date.year)
			mStartLastPeriod.year = date.year;
		else
			mStartLastPeriod.year = date.year - 1;
	}
	else
		if (mHiringData.month == date.month)
		{
			if (mHiringData.day <= date.day)
				mStartLastPeriod.year = date.year;
			else
				mStartLastPeriod.year = date.year - 1;
		}
		else
		{
			if (mHiringData.year <= date.year)
				mStartLastPeriod.year = date.year;
			else
				mStartLastPeriod.year = date.year - 1;
		}

	mEndLastPeriod = mStartLastPeriod;
	mEndLastPeriod.year = mStartLastPeriod.year + 1;
}