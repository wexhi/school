#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;

//�����½����
class User
{
public:

	//���캯��
	User();

	//���캯��
	User(string name, string password)
	{
		m_Name = name;
		m_Passwaord = password;
	}

	//��ʼ���û�
	void initUser();

	//չʾ�˵�
	void showMenu();

	//�û�ע��
	void signUp();

	//�û���½
	bool signIn();

	//�û�ע��
	//bool logOut();

	//�˳�ϵͳ
	void exitSystem();

	//�����û���
	void setName(string name);

	//��������
	void setPassword(string password);

	//�޸�����
	bool changePassword();

	//�û����ò˵�
	void showEditMenu();

	//�޸��û���
	bool changeUsername();

	//ɾ���û�
	bool deleteUser();

	//�ǳ�
	bool logOut();

	//���û������û�������
	void sortUser();

	//��ȡ���ڲ����û����û���
	string getUserName();

private:
	string m_Name;
	string m_Passwaord;
	bool is_login = false;
	vector<User> m_User;

	string m_newPassword;

   //��¼���ڵ�½���˺�
	vector<User> m_User_Now;
};
