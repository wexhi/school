#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	int	n;
	cin >> n;
	//����һ�����ж�Ϊn�Ķ�ά����
	int **a = new int *[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[n];
	}

	//��������
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}

	//�ҳ���Сֵ�����ֵ
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

	//��������ÿ��Ԫ��֮��
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			sum  += a[i][j];
		}
	}

	//������������ļ�out.dat
	int** b = new int* [n];
	for (int i = 0; i < n; i++)
	{
		b[i] = new int[n];
	}

	//1��������ȫ��дΪ��Сֵ
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			b[i][j] = min;
		}
	}

	//2�����ڶ��е������ڶ��е�����ȫ��дΪ��
	for (int i = 1; i < n - 1; i++)
	{
		for (int j = 1; j < n - 1; j++)
		{
			b[i][j] = sum;
		}
	}

	//3���������м��Ԫ��дΪ���ֵ
	b[n / 2][n / 2] = max;

	//int i = 0;
	//while(i < n)
	//{
	//	//����һ�к����һ��ȫ��д����Сֵ
	//	if (i == 0 || i == n - 1)
	//	{
	//		for (int j = 0; j < n; j++)
	//		{
	//			a[i][j] = min;
	//		}
	//	}
	//	//��������ȫ��ֵΪ��
	//	else
	//	{
	//		for (int j = 0; j < n; j++)
	//		{
	//			a[i][j] = sum;
	//		}
	//	}

	//	//����һ�к����һ��ȫ��д����Сֵ
	//	

	//	//�����м��Ԫ��дΪ���ֵ
	//	if (i == n / 2)
	//	{
	//		a[i][i] = max;
	//	}

	//	i++;
	//	//int j = 0;
	//	////����һ��ȫ��д����Сֵ
	//	//while (i == 0 && j < n)
	//	//{
	//	//	a[i][j] = min;
	//	//	j++;
	//	//}

	//	////�����һ��ȫ��д����Сֵ
	//	//while (i == n - 1 && j == 0)
	//	//{
	//	//	a[i][j]  = min;
	//	//	j++;
	//	//}

	//	////����һ��ȫ��д����Сֵ
	//	//while (i < n && j == 0)
	//	//{
	//	//	a[i][j]  = min;
	//	//	i++;
	//	//}

	//	////�����һ��ȫ��д����Сֵ
	//	//while (i < n && j == n - 1)
	//	//{
	//	//	a[i][j]  =min;
	//	//	i++;
	//	//}

	//	////���м��ȫ��д�ɺ�
	//	//for (int k = 1; k < n - 1; k++)
	//	//{
	//	//	for (int l = 1; l < n - 1; l++)
	//	//	{
	//	//		a[k][l]  =sum;
	//	//	}
	//	//}


	//	////�����м��Ԫ��дΪ���ֵ
	//	//if (i == (n + 1) / 2 && j == n / 2)
	//	//{
	//	//	a[i][j]  =max;
	//	//}
	//}

	//�������b
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << b[i][j] << " ";
		}
		cout << endl;
	}

	//������д���ļ�,�Կո�Ϊ�ָ���
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