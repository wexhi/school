#include"Users.h"

//构造函数
User::User()
{
	ifstream ifs;
	ifs.open("users.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;

		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "当前用户数量为0，请先进行注册！" << endl;
		//system("pause");
		signUp();

		ifs.close();
		return;
	}

	initUser();

	ifs.close();
}

//初始化用户
void User::initUser()
{
	ifstream ifs;
	ifs.open("users.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		return;
	}
	string name;
	string password;
	while (ifs >> name >> password)
	{
		
		this->m_User.push_back(User(name, password));
	}
	ifs.close();
	return;
}

//展示菜单
void User::showMenu()
{
	cout << " ********************************** " << endl;
	cout << " *********** 1.用户登陆 *********** " << endl;
	cout << " *********** 2.用户注册 *********** " << endl;
	cout << " ******** 3.将所有用户排序 ******** " << endl;
	cout << " *********** 0.退出系统 *********** " << endl;
	cout << " ********************************** " << endl;
}

//用户注册
void User::signUp()
{
	bool flag = true;

	cout << "请输入用户名：" << endl;
	cin >> this->m_Name;
	//检测用户是否已存在
	ifstream ifs;
	ifs.open("users.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		return;
	}

	string name;
	string password;

	while (ifs >> name >> password)
	{
		if (name == this->m_Name)
		{
			cout << "用户名已存在！请直接登录！" << endl;
			flag = false;
			signIn();

		}
	}

	if (flag == true)
	{
		cout << "请输入密码：" << endl;
		cin >> this->m_Passwaord;
		cout << "请确认密码：" << endl;
		string Passwaord_Confirm;
		cin >> Passwaord_Confirm;
		if (this->m_Passwaord == Passwaord_Confirm)
		{
			cout << "注册成功！" << endl;
			//将注册信息写入文件
			ofstream ofs;
			ofs.open("users.txt", ios::out | ios::app);
			ofs << this->m_Name << " " << this->m_Passwaord << endl;
			ofs.close();

			//将注册信息写入容器
			this->m_User.push_back(User(this->m_Name, this->m_Passwaord));

		}
		else
		{
			cout << "两次密码不一致！请重新注册" << endl;
			signUp();
		}
	}
	ifs.close();
}

//用户登陆
bool User::signIn()
{
	cout << "请输入用户名：" << endl;
	cin >> this->m_Name;
	cout << "请输入密码：" << endl;
	cin >> this->m_Passwaord;
	
	//读取文件中的信息
	ifstream ifs;
	ifs.open("users.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		return false;
	}
	
	string name;
	string password;
	while (ifs >> name >> password)//从文件中读取数据，判断是否有该用户
	{
		if (name == this->m_Name && password == this->m_Passwaord)
		{
			cout << "登陆成功！" << endl;
			this->is_login = true;
			
			//记录现在登陆的账号
			this->m_User_Now.push_back(User(this->m_Name, this->m_Passwaord));

			return true;
		}
	}
	
	cout << "用户名或密码错误！" << endl;
	system("pause");
	system("cls");

	ifs.close();
	return false;
}


//退出系统
void User::exitSystem()
{
	system("pause");
	exit(0);
}

//设置用户名
void User::setName(string name)
{
	this->m_Name = name;
}

//设置密码
void User::setPassword(string password)
{
	this->m_Passwaord = password;
}

//修改密码
bool  User::changePassword()
{
	for (int i = 0; i < m_User.size(); i++)
	{
		//找到当前登陆账户
		if (m_User_Now[0].m_Name == this->m_Name)
		{
			string oldPassword;
			cout << "请输入旧密码：" << endl;
			cin >> oldPassword;
			if (oldPassword == m_User_Now[0].m_Passwaord)
			{
				string newPassword;
				cout << "请输入新密码：" << endl;
				cin >> newPassword;
				cout << "请确认新密码：" << endl;
				string newPassword_Confirm;
				cin >> newPassword_Confirm;
				if (newPassword != newPassword_Confirm)
				{
					cout << "两次密码不一致！" << endl;
					system("pause");
					system("cls");
					return true;
				}
				else 
				{

					m_User[i].m_Passwaord = newPassword;
					m_User_Now[0].m_Passwaord = newPassword;
					cout << "修改成功！请重新登录！" << endl;
					//将修改后的信息写入文件
					ofstream ofs;
					ofs.open("users.txt", ios::out);
					for (int j = 0; j < m_User.size(); j++)
					{
						ofs << m_User[j].m_Name << " " << m_User[j].m_Passwaord << endl;
					}
					ofs.close();

					system("pause");
					system("cls");
					return false;
				}
				return true;
			}
			else
			{
				cout << "旧密码错误！" << endl;
				system("pause");
				system("cls");
				return true;
			}
		}
	}
	return true;
}

//用户设置菜单
void User::showEditMenu()
{
	cout << " ********************************** " << endl;
	cout << " ********** 用户设置界面 ********** " << endl;
	cout << " *********** 1.修改密码 *********** " << endl;
	cout << " ********** 2.修改用户名 ********** " << endl;
	cout << " *********** 3.注销账号 *********** " << endl;
	cout << " *********** 0.退出登录 *********** " << endl;
	cout << " ********************************** " << endl;
}

//修改用户名
bool User:: changeUsername()
{

	for (int i = 0; i < m_User.size(); i++)
	{
		//找到当前登陆账户
		if (m_User_Now[0].m_Name == m_User[i].m_Name)
		{
			string oldName;
			cout << "请输入旧用户名：" << endl;
			cin >> oldName;
			if (oldName == m_User_Now[0].m_Name)
			{
				string newName;
				cout << "请输入用户名：" << endl;
				cin >> newName;
				//判断是否有相同的用户名
				for (int j = 0; j < m_User.size(); j++)
				{
					if (newName == m_User[j].m_Name)
					{
						cout << "用户名已存在！" << endl;
						system("pause");
						system("cls");
						return true;
					}
				}
				m_User[i].m_Name = newName;
				m_User_Now[0].m_Name = newName;
				cout << "修改成功！请重新登陆!" << endl;
				//将修改后的信息写入文件
				ofstream ofs;
				ofs.open("users.txt", ios::out);
				for (int j = 0; j < m_User.size(); j++)
				{
					ofs << m_User[j].m_Name << " " << m_User[j].m_Passwaord << endl;
				}
				ofs.close();
				system("pause");
				system("cls");
				return false;
			}
			else
			{
				cout << "旧用户名错误！" << endl;
				system("pause");
				system("cls");
				return true;
			}
		}
	}
	return true;
}

//注销账号
bool User::deleteUser()
{
	char confirm;
	cout << "确认是否注销账户（注销成功后操作不可逆） Y/N" << endl;
	cin >> confirm;
	if (confirm == 'Y')
	{
		for (int i = 0; i < m_User.size(); i++)
		{

			//找到当前登陆账户
			if (m_User_Now[0].m_Name == m_User[i].m_Name)
			{
				string name;
				cout << "请输入用户名：" << endl;
				cin >> name;
				if (name == m_User_Now[0].m_Name)
				{
					string password;
					cout << "请输入密码：" << endl;
					cin >> password;
					if (password == m_User_Now[0].m_Passwaord)
					{
						m_User.erase(m_User.begin() + i);
						m_User_Now.erase(m_User_Now.begin());
						cout << "注销成功！" << endl;
						//将修改后的信息写入文件
						ofstream ofs;
						ofs.open("users.txt", ios::out);
						for (int j = 0; j < m_User.size(); j++)
						{
							ofs << m_User[j].m_Name << " " << m_User[j].m_Passwaord << endl;
						}
						ofs.close();
						system("pause");
						system("cls");
						return false;
					}
					else
					{
						cout << "密码错误！" << endl;
						system("pause");
						system("cls");
						return true;
					}
				}
				else
				{
					cout << "用户名错误！" << endl;
					system("pause");
					system("cls");
					return true;
				}
			}
		}
	}
	else if (confirm == 'N')
	{
		system("pause");
		system("cls");
		return true;
	}
	else
	{
		cout << "输入错误！" << endl;
		system("pause");
		system("cls");
		deleteUser();
		return true;
	}
	return true;
}

//登出
bool User::logOut()
{
	return false;
}

//将用户按照用户名排序
void User::sortUser()
{
	cout << "1.升序 " << endl;
	cout << "2.降序 " << endl;
	cout << "请选择排序方式:>" << endl;
	int select = 0;
	cin >> select;

	if (select == 1)
	{
		for (int i = 0; i < m_User.size() - 1; i++)
		{
			for (int j = 0; j < m_User.size() - i - 1; j++)
			{
				if (m_User[j].m_Name > m_User[j + 1].m_Name)
				{
					User temp = m_User[j];
					m_User[j] = m_User[j + 1];
					m_User[j + 1] = temp;
				}
			}
		}
	}
	else if (select == 2)
	{
		for (int i = 0; i < m_User.size() - 1; i++)
		{
			for (int j = 0; j < m_User.size() - i - 1; j++)
			{
				if (m_User[j].m_Name < m_User[j + 1].m_Name)
				{
					User temp = m_User[j];
					m_User[j] = m_User[j + 1];
					m_User[j + 1] = temp;
				}
			}
		}
	}
	else
	{
		cout << "输入错误！" << endl;
		system("pause");
		system("cls");
		sortUser();
	}

	//将修改后的信息写入文件
	ofstream ofs;
	ofs.open("users.txt", ios::out);
	for (int j = 0; j < m_User.size(); j++)
	{
		ofs << m_User[j].m_Name << " " << m_User[j].m_Passwaord << endl;
	}
	ofs.close();

	cout << "排序成功！" << endl;

	system("pause");
	system("cls");
}

//获取现在操作用户的用户名
string User:: getUserName()
{
	return m_User_Now[0].m_Name;
}