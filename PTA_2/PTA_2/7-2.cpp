#include<iostream>
using namespace std;

//ì³²¨ÄÇÆõÊýÁÐ
int Fibonacci(int arr[], int n)
{
	if (arr[n] != 0)
	{
		return arr[n];
	}
	else
	{
		arr[n] = Fibonacci(arr, n - 1) + Fibonacci(arr, n - 2);
		return arr[n];
	}
}

int main()
{
	int arr[40] = { 0 };
	arr[0] = 1; arr[1] = 1;
	int n;
	cin >> n;
	n -= 1;

	cout << Fibonacci(arr, n) << endl;

	system("pause");
	return 0;
}