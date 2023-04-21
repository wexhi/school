#include<iostream>
#include<vector>
using namespace std;

bool isTriangle(double a, double b, double c) {
	if (a <= 0 || b <= 0 || c <= 0) {
		return false;
	}
	if (a + b <= c || a + c <= b || b + c <= a) {
		return false;
	}
	return true;
}

int main()
{

	int n;
	cin >> n;

	double* arr = new double[n];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int max = 0;
	vector<double> C;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				if (isTriangle(arr[i] , arr[j] , arr[k]))
				{
					C.push_back(arr[i] + arr[j] + arr[k]);
				}
			}
		}
	}

	for (int i = 0; i < C.size(); i++)
	{
		cout << C[i] << " ";
		if (C[i] > max)
		{
			max = C[i];
		}
	}

	cout << endl;
	cout << max;

	if (arr != NULL)
	{
		delete[] arr;
		arr = NULL;
	}
}