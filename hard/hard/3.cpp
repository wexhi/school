#include<iostream>
using namespace std;








int main()
{

	int a[10][10];
	for (int i = 0; i < 9; i++)
	{
		a[9][i] = i;
	}
	//Êä³öa
	for (int i = 0; i < 9; i++)
	{
		cout << a[9][i] << " ";
	}


	system("pause");
	return 0;
}