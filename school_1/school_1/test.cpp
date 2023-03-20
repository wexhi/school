#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	//float a, v, length;
	//cin >> a >> v;
	//length = v * v / (2*a);
	//cout << fixed << setprecision(2) << length;

	double interest, debt, rate;
	cin >> debt >> rate;
	interest = debt * (rate / 1200);
	cout << fixed << setprecision(3) << interest;


	system("pause");
	return 0;
}