#include"Users.h"

void Users::showMenu()
{
	cout << "**********************************" << endl;
	cout << "*********** 1.用户登陆 *********** " << endl;
	cout << "*********** 2.用户注册 ***********  " <<endl;
	cout << "*********** 0.退出系统 ***********  " <<endl;
	cout << "********************************** " << endl;
}

void Users::userLogin()
{
	cout << "请输入用户名：" << endl;
	string userName;
	cin >> userName;
	cout << "请输入密码：" << endl;
	string userPwd;
	cin >> userPwd;
}