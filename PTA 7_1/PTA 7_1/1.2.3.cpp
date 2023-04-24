#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int main()
{
	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int p = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] != arr[p])
		{
			p++;
			arr[p] = arr[i];
		}
	}


	cout << p + 1 << endl;


	system("pause");
	return 0;
}