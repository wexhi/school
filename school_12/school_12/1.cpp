#include<iostream>
#include<fstream>
using namespace std;




int main()
{
	int arr[3][4] = { 0 };
	int i = 0, j = 0;
	//��������������
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			cin >> arr[i][j];
		}
	}

	//��������ļ���
	ofstream ofs;
	ofs.open("out.txt",ios::out);
	
	//������ת�ú������ļ���
	for (j = 0; j < 4; j++)
	{
		for (i= 0; i < 3; i++)
		{
			ofs <<arr[i][j] << " ";
		}
		ofs << endl;
	}
	ofs.close();

	system("pause");
	return 0;
}