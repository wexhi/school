#include <iostream>
#include"Users.h"
#include"Sales_item.h"
#include"operation.h"
#include"goods.h"
using namespace std;

int main()
{
	//检测文件是否完全，如没有文件，则创建空文件
	checkFile();

	User_item();

	system("pause");
	return 0;
}
