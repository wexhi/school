#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	int n, k;
	//����һ����СΪn������
	cin >> n;
	int *p1 = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> p1[i];
	}
	//����һ����СΪk������
	cin >> k;
	int *p2 = new int[k];
	for (int i = 0; i < k; i++)
	{
		cin >> p2[i];
	}

	//������p1��p2���ϵ�һ��������
	int *p3 = new int[n + k];
	for (int i = 0; i < n; i++)
	{
		p3[i] = p1[i];
	}
	for (int i = 0; i < k; i++)
	{
		p3[n + i] = p2[i];
	}

	//�������ڵ�Ԫ�ش�С��������
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

	//������p3д���ļ�
	for (int i = 0; i < n + k; i++)
	{
		ofs.write((char*)&p3[i], sizeof(int));
	}

	ofs.close();

	system("pause");
	return 0;
}