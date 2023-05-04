#include<iostream>
using namespace std;

//阶乘
int factorial(int n)
{
	if (n < 0)
	{
		cout<< "给定的数 < 0，no value!no value!" << endl;
		return 0;
	}

	if (n == 1 || n == 0)
	{
		return 1;
	}
	else
	{
		return n * factorial(n - 1);
	}
}

int main()
{
	int n;
	cin >> n;
	if (n > 0)
	{
		cout << n << "!=" << factorial(n) << endl;
	}

	system("pause");
	return 0;
}