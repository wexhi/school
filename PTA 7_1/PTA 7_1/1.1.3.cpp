#include<iostream>
#include<string>
#include<map>
using namespace std;

//判断是否是闰年
bool isLeapYear(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return true;
	else
		return false;
}

//判断每月13号是周几
int getDay(int year, int month)
{
	int day = 0;
	for (int i = 1900; i < year; i++)
	{
		if (isLeapYear(i))
			day += 366;
		else
			day += 365;
	}
	for (int i = 1; i < month; i++)
	{
		if (i == 2)
		{
			if (isLeapYear(year))
				day += 29;
			else
				day += 28;
		}
		else if (i == 4 || i == 6 || i == 9 || i == 11)
			day += 30;
		else
			day += 31;
	}
	day += 13;
	return day % 7;
}

int main()
{
	map <int, int> week;
	for (int i = 0; i < 7; i++)
	{
		week[i] = 0;
	}

	int n = 0, passed_days = 0;
	cin >> n;
	for (int i = 1900; i < n + 1900; i++)
	{
		for (int j = 1; j <= 12; j++)
		{
			week[getDay(i, j)]++;
		}
	}

	cout << week[6] << " ";
	cout << week[0] << " ";
	for (int i = 1; i < 6; i++)
	{
		cout << week[i] << " ";
	}

	//cout << getDay(1901, 1) << endl;
	//cout << passed_days << endl;

	system("pause");
	return 0;
}