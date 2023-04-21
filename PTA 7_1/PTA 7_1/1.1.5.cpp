#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<vector<char>> before(n, vector<char>(n)), after(n, vector<char>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> before[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> after[i][j];
		}
	}

	vector<vector<char>> temp(n, vector<char>(n));
	//情况1，旋转90度
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			temp[i][j] = before[n - 1 - j][i];
		}
	}
	if (temp == after)
	{
		cout << "1" << endl;
		return 0;
	}

	//情况2，旋转180度
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			temp[i][j] = before[n - 1 - i][n - 1 - j];
		}
	}
	if (temp == after)
	{
		cout << "2" << endl;
		return 0;
	}

	//情况3，旋转270度
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			temp[i][j] = before[j][n - 1 - i];
		}
	}
	if (temp == after)
	{
		cout << "3" << endl;
		return 0;
	}

	//情况4，水平翻转
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			temp[i][j] = before[i][n - 1 - j];
		}
	}
	if (temp == after)
	{
		cout << "4" << endl;
		return 0;
	}

	//情况5，水平翻转后旋转90度
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			temp[i][j] = before[n - 1 - j][n - 1 - i];
		}
	}
	if (temp == after)
	{
		cout << "5" << endl;
		return 0;
	}

	//情况5，水平翻转后旋转180度
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			temp[i][j] = before[n - 1 - i][j];
		}
	}
	if (temp == after)
	{
		cout << "5" << endl;
		return 0;
	}

	//情况5，水平翻转后旋转270度
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			temp[i][j] = before[j][i];
		}
	}
	if (temp == after)
	{
		cout << "5" << endl;
		return 0;
	}

	//情况6，不变
	if (before == after)
	{
		cout << "6" << endl;
		return 0;
	}

	//情况7，无法变换
	cout << "7" << endl;
	system("pause");
	return 0;
}