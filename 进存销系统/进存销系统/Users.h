#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;

//定义登陆界面
class User
{
public:

	//构造函数
	User();

	//构造函数
	User(string name, string password)
	{
		m_Name = name;
		m_Passwaord = password;
	}

	//初始化用户
	void initUser();

	//展示菜单
	void showMenu();

	//用户注册
	void signUp();

	//用户登陆
	bool signIn();

	//用户注销
	//bool logOut();

	//退出系统
	void exitSystem();

	//设置用户名
	void setName(string name);

	//设置密码
	void setPassword(string password);

	//修改密码
	bool changePassword();

	//用户设置菜单
	void showEditMenu();

	//修改用户名
	bool changeUsername();

	//删除用户
	bool deleteUser();

	//登出
	bool logOut();

	//将用户按照用户名排序
	void sortUser();

	//获取现在操作用户的用户名
	string getUserName();

private:
	string m_Name;
	string m_Passwaord;
	bool is_login = false;
	vector<User> m_User;

	string m_newPassword;

   //记录现在登陆的账号
	vector<User> m_User_Now;
};
