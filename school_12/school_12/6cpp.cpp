#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	int	n;
	cin >> n;
	//创建一个行列都为n的二维数组
	int **a = new int *[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[n];
	}

	//输入数组
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}

	//找出最小值和最大值
	int max = -1001, min = 1001;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] < min)
			{
				min = a[i][j];
			}
			if (a[i][j] > max)
			{
				max  = a[i][j];
			}
		}
	}

	//求出数组的每个元素之和
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			sum  += a[i][j];
		}
	}

	//输出到二进制文件out.dat
	int** b = new int* [n];
	for (int i = 0; i < n; i++)
	{
		b[i] = new int[n];
	}

	//1、将数组全部写为最小值
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			b[i][j] = min;
		}
	}

	//2、将第二行到倒数第二行的数组全部写为和
	for (int i = 1; i < n - 1; i++)
	{
		for (int j = 1; j < n - 1; j++)
		{
			b[i][j] = sum;
		}
	}

	//3、将数组中间的元素写为最大值
	b[n / 2][n / 2] = max;

	//int i = 0;
	//while(i < n)
	//{
	//	//将第一行和最后一行全部写成最小值
	//	if (i == 0 || i == n - 1)
	//	{
	//		for (int j = 0; j < n; j++)
	//		{
	//			a[i][j] = min;
	//		}
	//	}
	//	//将其他行全赋值为和
	//	else
	//	{
	//		for (int j = 0; j < n; j++)
	//		{
	//			a[i][j] = sum;
	//		}
	//	}

	//	//将第一列和最后一列全部写成最小值
	//	

	//	//将最中间的元素写为最大值
	//	if (i == n / 2)
	//	{
	//		a[i][i] = max;
	//	}

	//	i++;
	//	//int j = 0;
	//	////将第一行全部写成最小值
	//	//while (i == 0 && j < n)
	//	//{
	//	//	a[i][j] = min;
	//	//	j++;
	//	//}

	//	////将最后一行全部写成最小值
	//	//while (i == n - 1 && j == 0)
	//	//{
	//	//	a[i][j]  = min;
	//	//	j++;
	//	//}

	//	////将第一列全部写成最小值
	//	//while (i < n && j == 0)
	//	//{
	//	//	a[i][j]  = min;
	//	//	i++;
	//	//}

	//	////将最后一列全部写成最小值
	//	//while (i < n && j == n - 1)
	//	//{
	//	//	a[i][j]  =min;
	//	//	i++;
	//	//}

	//	////将中间的全部写成和
	//	//for (int k = 1; k < n - 1; k++)
	//	//{
	//	//	for (int l = 1; l < n - 1; l++)
	//	//	{
	//	//		a[k][l]  =sum;
	//	//	}
	//	//}


	//	////将最中间的元素写为最大值
	//	//if (i == (n + 1) / 2 && j == n / 2)
	//	//{
	//	//	a[i][j]  =max;
	//	//}
	//}

	//输出数组b
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << b[i][j] << " ";
		}
		cout << endl;
	}

	//将数组写入文件,以空格为分隔符
	ofstream ofs("out.dat", ios::out | ios::binary);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ofs.write((char*)&b[i][j], sizeof(int));
		}
	}

	ofs.close();
	delete []b;
	delete[]a;

	system("pause");
	return 0;
}