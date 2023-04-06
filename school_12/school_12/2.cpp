#include<iostream>
#include<fstream>
using namespace std;


typedef struct studentMessage

{

	char name[20];

	char address[30];

	char phone[12];

}stuMsg;

int main()
{
	stuMsg stu[3];
	//输入信息
	for (int i = 0; i < 3; i++)
	{
		cin >> stu[i].name;
		cin >> stu[i].address;
		cin >> stu[i].phone;
	}

	//用fwrite函数将结构体数组写入二进制文件class.dat中
	ofstream out("class.dat", ios::binary);
	out.write((char*)stu, sizeof(stuMsg) * 3);
	out.close();

	system("pause");
	return 0;
}