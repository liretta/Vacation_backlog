#include "includes.h"
#include "Date.h"
#include "Employee.h"
#include "External_functions.h"
using namespace std;

//TODO: add move-constructor and change copy in strtok-bloks to move-semantic

void Mem();

int main(int argc, char ** argv[])
{
	{
		setlocale(LC_ALL, "Russian");
		const char* SEPARATORS = { "\n" };
		const char* SEPARATORS_EMPLOYEE = { "-" };

		char * cFileName = nullptr;
		int fileNameLen = 0, fileLen = 0, buffLen = 0;

		if (argc < 2)
		{
			cout << "Pls, enter file name in commond line and restart program" << endl;
			system("pause");

			return 0;
		}
		else
		{
			fileNameLen = strlen((char *)argv[1]);
			cFileName = new char[fileNameLen + 1]{};
			memcpy(cFileName, argv[1], fileNameLen);
		}

		FILE *f;
		errno_t err = fopen_s(&f, cFileName, "rb");

		if (f == NULL)
		{
			cout << "Error open file. Pls check name and restart program" << endl;

			system("pause");
			return 0;
		}

		fseek(f, 0, SEEK_END);

		fileLen = ftell(f);
		buffLen = fileLen;
		char  *cBuffText = nullptr;
		int totalLen = 0; //readed and added data
		bool isBuffSizeOk = false;
		while (isBuffSizeOk != true) //looking for optimal size for our buffer 
		{
			try
			{
				isBuffSizeOk = true;
				cBuffText = new char[buffLen];
			}
			catch (std::bad_alloc&)
			{
				if (cBuffText != nullptr)
				{
					delete[] cBuffText;
					cBuffText = nullptr;
				}
				isBuffSizeOk = false;
				buffLen /= 2;
			}
		}

	//TODO: read info and write it to vector Employees
	//	map<string, int> mapDictionary;
		vector <Employee> vcEmployees;
		vcEmployees.reserve(250);

		char *pTocken, *pBuffForTocken, *pContext;
		char *pEmployeeTocken, *pEmployeeContext;
		string strTemp, strEmployeeDataTemp;
		Employee tempEmpl;

		fseek(f, 0, SEEK_SET);
		int nReadedBytes = fread(cBuffText, sizeof(char), buffLen, f);
		pTocken = strtok_s(cBuffText, SEPARATORS, &pContext);

		cout << "Start to read file. Wait pls..." << endl;
		while (totalLen < fileLen)
		{
			while (pTocken != NULL)
			{
				//strTemp = pTocken;
				{
					pEmployeeTocken = strtok_s(pTocken, SEPARATORS_EMPLOYEE, &pEmployeeContext);
					tempEmpl.mNumber = atoi(pEmployeeTocken);
					pEmployeeTocken = strtok_s(NULL, SEPARATORS_EMPLOYEE, &pEmployeeContext);
					string strTempData = pEmployeeTocken;
					Data tempData(strTempData);
					tempEmpl.mHiringData = tempData;
					vcEmployees.push_back(move(tempEmpl));

				}
				pTocken = strtok_s(NULL, SEPARATORS, &pContext);
			}

			totalLen += nReadedBytes;
			if (totalLen += buffLen > fileLen)
				buffLen = fileLen - totalLen;
			fseek(f, totalLen, SEEK_CUR);
			nReadedBytes = fread(cBuffText, sizeof(char), buffLen, f);
		}
		//
		//cout << "Enter date to re-calculate vacation balance ";
		string date;
		cin >> date;
		Data calculateDate(date);

		int n = vcEmployees.size();
		for (int i = 0; i < n; ++i)
		{
			vcEmployees[i].SetStartPeriod(calculateDate);
		}

		NewBalanceCalculation(vcEmployees, calculateDate);

		//Open file to write
		ofstream out;
		out.open("result.txt");
		//TODO: mb need Prit function for Date?
				
		//Write to file
		out << "Empl. # -" << "Hiring date -" << "Last working period-" << "Vacational balance-" << endl;
		for (auto it = vcEmployees.begin(); it != vcEmployees.end();it++)
		{
			out << (*it).mNumber << "-" << (*it).mHiringData.day <<
				"." << (*it).mHiringData.month << "." << (*it).mHiringData.year << "-" << 
				(*it).mStartLastPeriod.day<<"."<<(*it).mStartLastPeriod.month<<"."<< (*it).mStartLastPeriod.year<<"-"<< (*it).mVacationBalance << endl;;
		}

		if (cFileName != 0)
		{
			delete[] cFileName;
			cFileName = nullptr;
		}
		if (cBuffText != nullptr)
		{
			delete[] cBuffText;
			cBuffText = nullptr;
		}
	}

	//Mem(); //chering mem leaks
	system("pause");
	return 0;
}
