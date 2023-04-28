#include"Users.h"

//���캯��
User::User()
{
	ifstream ifs;
	ifs.open("users.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;

		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "��ǰ�û�����Ϊ0�����Ƚ���ע�ᣡ" << endl;
		//system("pause");
		signUp();

		ifs.close();
		return;
	}

	initUser();

	ifs.close();
}

//��ʼ���û�
void User::initUser()
{
	ifstream ifs;
	ifs.open("users.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
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

//չʾ�˵�
void User::showMenu()
{
	cout << " ********************************** " << endl;
	cout << " *********** 1.�û���½ *********** " << endl;
	cout << " *********** 2.�û�ע�� *********** " << endl;
	cout << " ******** 3.�������û����� ******** " << endl;
	cout << " *********** 0.�˳�ϵͳ *********** " << endl;
	cout << " ********************************** " << endl;
}

//�û�ע��
void User::signUp()
{
	bool flag = true;

	cout << "�������û�����" << endl;
	cin >> this->m_Name;
	//����û��Ƿ��Ѵ���
	ifstream ifs;
	ifs.open("users.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		return;
	}

	string name;
	string password;

	while (ifs >> name >> password)
	{
		if (name == this->m_Name)
		{
			cout << "�û����Ѵ��ڣ���ֱ�ӵ�¼��" << endl;
			flag = false;
			signIn();

		}
	}

	if (flag == true)
	{
		cout << "���������룺" << endl;
		cin >> this->m_Passwaord;
		cout << "��ȷ�����룺" << endl;
		string Passwaord_Confirm;
		cin >> Passwaord_Confirm;
		if (this->m_Passwaord == Passwaord_Confirm)
		{
			cout << "ע��ɹ���" << endl;
			//��ע����Ϣд���ļ�
			ofstream ofs;
			ofs.open("users.txt", ios::out | ios::app);
			ofs << this->m_Name << " " << this->m_Passwaord << endl;
			ofs.close();

			//��ע����Ϣд������
			this->m_User.push_back(User(this->m_Name, this->m_Passwaord));

		}
		else
		{
			cout << "�������벻һ�£�������ע��" << endl;
			signUp();
		}
	}
	ifs.close();
}

//�û���½
bool User::signIn()
{
	cout << "�������û�����" << endl;
	cin >> this->m_Name;
	cout << "���������룺" << endl;
	cin >> this->m_Passwaord;
	
	//��ȡ�ļ��е���Ϣ
	ifstream ifs;
	ifs.open("users.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		return false;
	}
	
	string name;
	string password;
	while (ifs >> name >> password)//���ļ��ж�ȡ���ݣ��ж��Ƿ��и��û�
	{
		if (name == this->m_Name && password == this->m_Passwaord)
		{
			cout << "��½�ɹ���" << endl;
			this->is_login = true;
			
			//��¼���ڵ�½���˺�
			this->m_User_Now.push_back(User(this->m_Name, this->m_Passwaord));

			return true;
		}
	}
	
	cout << "�û������������" << endl;
	system("pause");
	system("cls");

	ifs.close();
	return false;
}


//�˳�ϵͳ
void User::exitSystem()
{
	system("pause");
	exit(0);
}

//�����û���
void User::setName(string name)
{
	this->m_Name = name;
}

//��������
void User::setPassword(string password)
{
	this->m_Passwaord = password;
}

//�޸�����
bool  User::changePassword()
{
	for (int i = 0; i < m_User.size(); i++)
	{
		//�ҵ���ǰ��½�˻�
		if (m_User_Now[0].m_Name == this->m_Name)
		{
			string oldPassword;
			cout << "����������룺" << endl;
			cin >> oldPassword;
			if (oldPassword == m_User_Now[0].m_Passwaord)
			{
				string newPassword;
				cout << "�����������룺" << endl;
				cin >> newPassword;
				cout << "��ȷ�������룺" << endl;
				string newPassword_Confirm;
				cin >> newPassword_Confirm;
				if (newPassword != newPassword_Confirm)
				{
					cout << "�������벻һ�£�" << endl;
					system("pause");
					system("cls");
					return true;
				}
				else 
				{

					m_User[i].m_Passwaord = newPassword;
					m_User_Now[0].m_Passwaord = newPassword;
					cout << "�޸ĳɹ��������µ�¼��" << endl;
					//���޸ĺ����Ϣд���ļ�
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
				cout << "���������" << endl;
				system("pause");
				system("cls");
				return true;
			}
		}
	}
	return true;
}

//�û����ò˵�
void User::showEditMenu()
{
	cout << " ********************************** " << endl;
	cout << " ********** �û����ý��� ********** " << endl;
	cout << " *********** 1.�޸����� *********** " << endl;
	cout << " ********** 2.�޸��û��� ********** " << endl;
	cout << " *********** 3.ע���˺� *********** " << endl;
	cout << " *********** 0.�˳���¼ *********** " << endl;
	cout << " ********************************** " << endl;
}

//�޸��û���
bool User:: changeUsername()
{

	for (int i = 0; i < m_User.size(); i++)
	{
		//�ҵ���ǰ��½�˻�
		if (m_User_Now[0].m_Name == m_User[i].m_Name)
		{
			string oldName;
			cout << "��������û�����" << endl;
			cin >> oldName;
			if (oldName == m_User_Now[0].m_Name)
			{
				string newName;
				cout << "�������û�����" << endl;
				cin >> newName;
				//�ж��Ƿ�����ͬ���û���
				for (int j = 0; j < m_User.size(); j++)
				{
					if (newName == m_User[j].m_Name)
					{
						cout << "�û����Ѵ��ڣ�" << endl;
						system("pause");
						system("cls");
						return true;
					}
				}
				m_User[i].m_Name = newName;
				m_User_Now[0].m_Name = newName;
				cout << "�޸ĳɹ��������µ�½!" << endl;
				//���޸ĺ����Ϣд���ļ�
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
				cout << "���û�������" << endl;
				system("pause");
				system("cls");
				return true;
			}
		}
	}
	return true;
}

//ע���˺�
bool User::deleteUser()
{
	char confirm;
	cout << "ȷ���Ƿ�ע���˻���ע���ɹ�����������棩 Y/N" << endl;
	cin >> confirm;
	if (confirm == 'Y')
	{
		for (int i = 0; i < m_User.size(); i++)
		{

			//�ҵ���ǰ��½�˻�
			if (m_User_Now[0].m_Name == m_User[i].m_Name)
			{
				string name;
				cout << "�������û�����" << endl;
				cin >> name;
				if (name == m_User_Now[0].m_Name)
				{
					string password;
					cout << "���������룺" << endl;
					cin >> password;
					if (password == m_User_Now[0].m_Passwaord)
					{
						m_User.erase(m_User.begin() + i);
						m_User_Now.erase(m_User_Now.begin());
						cout << "ע���ɹ���" << endl;
						//���޸ĺ����Ϣд���ļ�
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
						cout << "�������" << endl;
						system("pause");
						system("cls");
						return true;
					}
				}
				else
				{
					cout << "�û�������" << endl;
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
		cout << "�������" << endl;
		system("pause");
		system("cls");
		deleteUser();
		return true;
	}
	return true;
}

//�ǳ�
bool User::logOut()
{
	return false;
}

//���û������û�������
void User::sortUser()
{
	cout << "1.���� " << endl;
	cout << "2.���� " << endl;
	cout << "��ѡ������ʽ:>" << endl;
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
		cout << "�������" << endl;
		system("pause");
		system("cls");
		sortUser();
	}

	//���޸ĺ����Ϣд���ļ�
	ofstream ofs;
	ofs.open("users.txt", ios::out);
	for (int j = 0; j < m_User.size(); j++)
	{
		ofs << m_User[j].m_Name << " " << m_User[j].m_Passwaord << endl;
	}
	ofs.close();

	cout << "����ɹ���" << endl;

	system("pause");
	system("cls");
}

//��ȡ���ڲ����û����û���
string User:: getUserName()
{
	return m_User_Now[0].m_Name;
}