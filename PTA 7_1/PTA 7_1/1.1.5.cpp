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
	//���1����ת90��
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

	//���2����ת180��
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

	//���3����ת270��
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

	//���4��ˮƽ��ת
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

	//���5��ˮƽ��ת����ת90��
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

	//���5��ˮƽ��ת����ת180��
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

	//���5��ˮƽ��ת����ת270��
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

	//���6������
	if (before == after)
	{
		cout << "6" << endl;
		return 0;
	}

	//���7���޷��任
	cout << "7" << endl;
	system("pause");
	return 0;
}