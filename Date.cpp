#include "Date.h"



Data::Data(string str)
{
	//TODO: add checking to correct format
	//and checking by day's quontity in current month, and month number
	const char *tempChar = str.c_str();
	vector<int> numbers;
	numbers.reserve(DATALENGHT);
	int n = DATALENGHT; //str has numbers and end-line symbol, exmpl: "21.01.2015\r". We need only numbers
	for (int i = 0; i < n; ++i)
	{
		if (tempChar[i] != '.')
			numbers.push_back(int(tempChar[i] - '0'));
	}

	/*day = numbers[1] * 10 + numbers[2];
	month = numbers[3] * 10 + numbers[4];
	year = numbers[5] * 1000 + numbers[6] * 100 + numbers[7] * 10 + numbers[8];*/

	n = numbers.size();
	for (int i = 0; i < n; ++i)
	{
		switch (i)
		{
		case 0:
		{
			if (i + 1 <= n)
			{
				day = numbers[i] * 10 + numbers[i + 1];
				i++;
			}
		}
		break;
		case 2:
		{
			if (i + 1 <= n)
			{
				month = numbers[i] * 10 + numbers[i + 1];
				i++;
			}
		}
		break;
		case 4:
		{
			if (i + 3 <= n)
			{
				year = numbers[i] * 1000 + numbers[i + 1] * 100 + numbers[i + 2] * 10 + numbers[i + 3];
			}
		}
		default:
			break;
		}
	}

}

Data::Data() : day(01), month(01), year(2001) {};

bool Data::operator<=(const Data &d2) const
{
	if (d2.year == year && d2.month == month && d2.day == day)
		return true;

	if (d2.year > year)
		return true;

	if (d2.year == year)
		if (d2.month > month)
			return true;
		else
		{
			if (d2.month == month)
				if (d2.day > day)
					return true;
		}

	return false;
}

bool Data::operator<(const Data &d2) const
{
	if (d2.year == year && d2.month == month && d2.day == day)
		return false;

	if (d2.year > year)
		return true;

	if (d2.year == year)
		if (d2.month > month)
			return true;
		else
		{
			if (d2.month == month)
				if (d2.day > day)
					return true;
		}

	return false;
}