#include<iostream>

using namespace std;



int main()
{

	int n;
	cin >> n;
	
	int* arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int max = arr[0];
	int i = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}

	cout << max << " " << i << endl;;

	system("pause");
	return 0;
}