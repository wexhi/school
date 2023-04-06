#include<iostream>
#include<fstream>
using namespace std;




int main()
{
	int arr[3][4] = { 0 };
	int i = 0, j = 0;
	//将数字输入数组
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			cin >> arr[i][j];
		}
	}

	//创建输出文件流
	ofstream ofs;
	ofs.open("out.txt",ios::out);
	
	//将数组转置后输入文件中
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