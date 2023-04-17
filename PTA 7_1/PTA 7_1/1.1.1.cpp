#include<iostream>
#include<string>
using namespace std;

int main()
{
	string star_name;
	string team_name;

	cin >> star_name >> team_name;

	int star_num = 1;
	for (int i = 0; i < star_name.length(); i++)
	{
		star_num *= star_name[i] - 64;
	}
	star_num %= 47;

	int team_num = 1;
	for (int i = 0; i < team_name.length(); i++)
	{
		team_num *= team_name[i] - 64;
	}
	team_num %= 47;

	if (star_num == team_num)
	{
		cout << "GO" << endl;
	}
	else
	{
		cout << "STAY" << endl;
	}

	system("pause");
	return 0;
}