#include<iostream>

using namespace std;

int main()
{
	int L, n;

	cin >> L >> n;

	int *x = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
	}

	//找到中间值
	int mid = x[0];
	int min = x[0];
	for (int i = 0; i < n; i++)
	{
		if (abs(x[i] - L / 2) < abs(mid - L / 2))
		{
			mid = x[i];
		}
		if (x[i] < min)
		{
			min = x[i];
		}
	}

	if ((L - mid) < mid)
	{
		cout << L - mid << endl;
	}
	else
	{
		cout << mid << endl;
	}
	

	cout << L - min << endl;



	if (x != NULL)
	{
		delete[] x;
		x = NULL;
	}
	system("pause");
	return 0;
}