#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	int n, k;
	//创建一个大小为n的数组
	cin >> n;
	int *p1 = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> p1[i];
	}
	//创建一个大小为k的数组
	cin >> k;
	int *p2 = new int[k];
	for (int i = 0; i < k; i++)
	{
		cin >> p2[i];
	}

	//将数组p1和p2整合到一个数组内
	int *p3 = new int[n + k];
	for (int i = 0; i < n; i++)
	{
		p3[i] = p1[i];
	}
	for (int i = 0; i < k; i++)
	{
		p3[n + i] = p2[i];
	}

	//将数组内的元素从小到大排序
	for (int i = 0; i < n + k; i++)
	{
		for (int j = 0; j < n + k - i - 1; j++)
		{
			if (p3[j] > p3[j + 1])
			{
				int temp = p3[j];
				p3[j] = p3[j + 1];
				p3[j + 1] = temp;
			}
		}
	}
	
	ofstream ofs("out.dat", ios::out | ios::binary);

	if (!ofs)
	{
		cout << "open file error!" << endl;
		return 0;
	}

	//将数组p3写入文件
	for (int i = 0; i < n + k; i++)
	{
		ofs.write((char*)&p3[i], sizeof(int));
	}

	ofs.close();

	system("pause");
	return 0;
}