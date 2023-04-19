#include<iostream>
using namespace std;

void reserve(int n)
{
	cout << n % 10;
	if (n > 10)
	{
		reserve(n/10);
	}
}


int main()
{
	int n;
	cin >> n;
	reserve(n);



	system("pause");
	return 0;
}