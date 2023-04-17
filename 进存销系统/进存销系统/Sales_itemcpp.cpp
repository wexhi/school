#include"Sales_item.h"

//���캯��
SalesSystem::SalesSystem()
{
	cout << "�밴����������������ϵͳ:>" << endl;
	system("pause");
	system("cls");


	this->m_allGoodsNums = getGoodsNums();

	//��ʼ����Ʒ
	initGoods();

	//����
	//getGoodsNums();
}

//��ʼ����Ʒ
void SalesSystem::initGoods()
{
	ifstream ifs;
	ifs.open("goods.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}

	//��ȡ��Ʒ��Ϣ
	int id;
	string name;
	string unit;
	double price;
	int num;

	while (ifs >> id && ifs >> name && ifs >> unit && ifs >> price && ifs >> num)
	{
		Goods goods(id, name, unit, price, num);
		this->goods_arr.push_back(goods);
	}

	int index = 0;
	ifs.close();
}


//չʾѡ��˵�
void SalesSystem :: showMenu()
{

	cout << " ********************************** " << endl;
	cout << " *********** ������ϵͳ *********** " << endl;
	cout << " *********** 1.������Ʒ *********** " << endl;
	cout << " *********** 2.ɾ����Ʒ *********** " << endl;
	cout << " *********** 3.��Ʒ���� *********** " << endl;
	cout << " *********** 4.��Ʒ���� *********** " << endl;
	cout << " ********* 5.չʾ��Ʒ��Ϣ ********* " << endl;
	cout << " ********* 6.��ʾ������¼ ********* " << endl;
	cout << " *********** 7.�̵���Ʒ *********** " << endl;
	cout << " ******* 8.�����û�������� ******* " << endl;
	cout << " *********** 9.������Ʒ *********** " << endl;
	cout << " *********** 0.�˳���¼ *********** " << endl;
	cout << " ********************************** " << endl;

}

//������Ʒ
void  SalesSystem::createGoods(User &u)
{

	int id;
	cout << "��������Ʒ���:>" << endl;
	cin >> id;
	//�ж���Ʒ����Ƿ��ظ�
	for (int i = 0; i < this->goods_arr.size(); i++)
	{
		while (this->goods_arr[i].getID() == id)
		{
			cout << "��Ʒ����ظ�������������" << endl;
			cin >> id;
		}
	}

	string name;
	cout << "��������Ʒ����:>" << endl;
	cin >> name;
	//�ж���Ʒ�����Ƿ��ظ�
	for (int i = 0; i < this->goods_arr.size(); i++)
	{
		while (this->goods_arr[i].getName() == name)
		{
			cout << "��Ʒ�����ظ�������������" << endl;
			cin >> name;
		}
	}

	string unit;
	cout << "��������Ʒ��λ:>" << endl;
	cin >> unit;

	double price;
	cout << "��������Ʒ�۸�:>" << endl;
	cin >> price;

	int num;
	cout << "��������Ʒ�������:>" << endl;
	cin >> num;

	Goods goods(id, name, unit, price, num);

	//����Ʒ��Ϣд���ļ�
	goods.save();

	goods_arr.push_back(goods);
	this->m_allGoodsNums++;

	//��¼������¼
	string operation = "������Ʒ";
	string  user_name = u.getUserName();
	History h1(id, user_name, 1, operation);

	cout << "������Ʒ�ɹ�" << endl;
	system("pause");
	system("cls");

}

//չʾ��Ʒ��Ϣ
void SalesSystem::showGoods()
{
	if (m_allGoodsNums == 0)
	{
		cout << "��ǰû����Ʒ��Ϣ" << endl;
		return;
	}
	cout << "��Ʒ���" << "\t" << "��Ʒ����" << "\t" << "��Ʒ��λ" << "\t" << "��Ʒ�۸�" << "\t" << "��Ʒ�������" << endl;
	for (int i = 0; i < m_allGoodsNums; i++)
	{
		goods_arr[i].show();
		cout << "-----------------------------------------------------------------------------" << endl;
	}

	system("pause");
	system("cls");
}


//չʾ��Ʒ��Ϣ(������ʹ�ã�
void SalesSystem::show()
{
	if (m_allGoodsNums == 0)
	{
		cout << "��ǰû����Ʒ��Ϣ" << endl;
		return;
	}
	cout << "��Ʒ���" << "\t" << "��Ʒ����" << "\t" << "��Ʒ��λ" << "\t" << "��Ʒ�۸�" << "\t" << "��Ʒ�������" << endl;
	for (int i = 0; i < this->goods_arr.size(); i++)
	{
		goods_arr[i].show();
	}
}


//ɾ����Ʒ
void SalesSystem::deleteGoods(User &u)
{

	show();


	int choice = 0;
	cout << "��ѡ��ɾ����ʽ:>" << endl;
	cout << "1.����Ʒ���ɾ��" << endl;
	cout << "2.����Ʒ����ɾ��" << endl;
	cin >> choice;

	if (choice == 1)
	{
		int id = 0;
		cout << "������Ҫɾ������Ʒ���:>" << endl;
		cin >> id;
		if (findGoodsID(id) >= 0)
		{
			//ɾ����Ʒ
			this->goods_arr.erase(this->goods_arr.begin() + findGoodsID(id));
			this->m_allGoodsNums--;
			//�����ļ�
			update();

			//��¼����
			string operation = "ɾ����Ʒ";
			string  user_name = u.getUserName();
			History h1(id, user_name, 1, operation);

			cout << "ɾ����Ʒ�ɹ�" << endl;
		}
		else
		{
			cout << "��Ʒ��Ų�����" << endl;
		}
	}
	else if(choice == 2)
	{
		string name;
		cout << "��������Ʒ����:>" << endl;
		cin >> name;
		//�ж���Ʒ�����Ƿ��ظ�
		if (findGoodsName(name) >= 0)
		{
			//��ɾ�����±���ʧ�������Ҫ��ǰ��¼
			//��¼����
			int id = this->goods_arr[findGoodsName(name)].getID();
			string operation = "ɾ����Ʒ";
			string  user_name = u.getUserName();
			History h1(id, user_name, 1, operation);

			//ɾ����Ʒ
			this->goods_arr.erase(this->goods_arr.begin() + findGoodsName(name));
			this->m_allGoodsNums--;
			
			//�����ļ�
			update();
			cout << "ɾ����Ʒ�ɹ�" << endl;
		}
		else
		{
			cout << "��Ʒ���Ʋ�����" << endl;
		}
	}
	else
	{
		cout << "��������" << endl;
	}


	system("pause");
	system("cls");
}

//��ȡ��Ʒ��������
int   SalesSystem::getGoodsNums()
{
	ifstream ifs;
	ifs.open("goods.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return 0;
	}
	
	int count = 0;
	int id;
	string name;
	string unit;
	double price;
	int num;

	while (ifs >> id && ifs >> name && ifs >> unit && ifs >> price && ifs >> num)
	{
		count++;
	}
	ifs.close();
	
	//����
	//cout << "��Ʒ��������Ϊ��" << count << endl;
	
	return count;
}

//��Ʒ����
void SalesSystem::addGoods(User& u)
{
	show();

	int choice = 0;
	cout << "��ѡ�������ʽ:>" << endl;
	cout << "1.����Ʒ��Ž���" << endl;
	cout << "2.����Ʒ���ƽ���" << endl;
	cin >> choice;
	if (choice == 1)
	{
		int id = 0;
		cout << "������Ҫ��������Ʒ���:>" << endl;
		cin >> id;
		if (findGoodsID(id) >= 0)
		{
			cout << "��Ʒ���" << "\t" << "��Ʒ����" << "\t" << "��Ʒ��λ" << "\t" << "��Ʒ�۸�" << "\t" << "��Ʒ�������" << endl;
			goods_arr[findGoodsID(id)].show();
			int num = 0;
			cout << "�������������:>" << endl;
			cin >> num;
			if (num > 0)
			{
				goods_arr[findGoodsID(id)].addNum(num);
				cout << "�����ɹ�" << endl;
				//�����ļ�
				update();

				//��¼����
				string operation = "��Ʒ����";
				string  user_name = u.getUserName();
				History h1(id, user_name, num, operation);


				system("pause");
				system("cls");
			}
			else
			{
				cout << "������������" << endl;
				system("pause");
				system("cls");
			}
		}
		else
		{
			cout << "��Ʒ��Ų�����" << endl;
			system("pause");
			system("cls");
		}
	}
	else if (choice == 2)
	{
		string name;
		cout << "��������Ʒ����:>" << endl;
		cin >> name;
		//�ж���Ʒ�����Ƿ��ظ�
		if (findGoodsName(name) >= 0)
		{
			cout << "��Ʒ���" << "\t" << "��Ʒ����" << "\t" << "��Ʒ��λ" << "\t" << "��Ʒ�۸�" << "\t" << "��Ʒ�������" << endl;
			goods_arr[findGoodsName(name)].show();
			int num = 0;
			cout << "�������������:>" << endl;
			cin >> num;
			if (num > 0)
			{
				goods_arr[findGoodsName(name)].addNum(num);
				cout << "�����ɹ�" << endl;
				//�����ļ�
				update();

				//��¼����
				string operation = "��Ʒ����";
				string  user_name = u.getUserName();
				History h1(goods_arr[findGoodsName(name)].getID(), user_name, num, operation);

				system("pause");
				system("cls");
			}
			else
			{
				cout << "������������" << endl;
				system("pause");
				system("cls");
			}
		}
		else
		{
			cout << "��Ʒ���Ʋ�����" << endl;
			system("pause");
			system("cls");
		}
	}
	else
	{
		cout << "��������" << endl;
		system("pause");
		system("cls");
	}

}

//��Ʒ����
void SalesSystem::saleGoods(User& u)
{

	show();

	int choice = 0;
	cout << "��ѡ�����۷�ʽ:>" << endl;
	cout << "1.����Ʒ�������" << endl;
	cout << "2.����Ʒ��������" << endl;
	cin >> choice;
	if (choice == 1)
	{
		int id = 0;
		cout << "������Ҫ���۵���Ʒ���:>" << endl;
		cin >> id;
		if (findGoodsID(id) >= 0)
		{
			cout << "��Ʒ���" << "\t" << "��Ʒ����" << "\t" << "��Ʒ��λ" << "\t" << "��Ʒ�۸�" << "\t" << "��Ʒ�������" << endl;
			goods_arr[findGoodsID(id)].show();
			int num = 0;
			cout << "��������������:>" << endl;
			cin >> num;
			if (num > 0 && num <= goods_arr[findGoodsID(id)].getNum())
			{
				goods_arr[findGoodsID(id)].subNum(num);
				cout << "���۳ɹ�" << endl;
				//�����ļ�
				update();

				//��¼����
				string operation = "��Ʒ����";
				string  user_name = u.getUserName();
				History h1(id, user_name, num, operation);

				system("pause");
				system("cls");
			}
			else
			{
				cout << "������������" << endl;
				system("pause");
				system("cls");
			}
		}
		else
		{
			cout << "��Ʒ��Ų�����" << endl;
			system("pause");
			system("cls");
		}
	}
	else if (choice == 2)
	{
		string name;
		cout << "��������Ʒ����:>" << endl;
		cin >> name;
		//�ж���Ʒ�����Ƿ��ظ�
		if (findGoodsName(name) >= 0)
		{
			cout << "��Ʒ���" << "\t" << "��Ʒ����" << "\t" << "��Ʒ��λ" << "\t" << "��Ʒ�۸�" << "\t" << "��Ʒ�������" << endl;
			goods_arr[findGoodsName(name)].show();
			int num = 0;
			cout << "��������������:>" << endl;
			cin >> num;
			if (num > 0 && num <= goods_arr[findGoodsName(name)].getNum())
			{
				goods_arr[findGoodsName(name)].subNum(num);
				cout << "���۳ɹ�" << endl;
				//�����ļ�
				update();

				//��¼����
				string operation = "��Ʒ����";
				string  user_name = u.getUserName();
				History h1(goods_arr[findGoodsName(name)].getID(), user_name, num, operation);

				system("pause");
				system("cls");
			}
			else
			{
				cout << "������������" << endl;
				system("pause");
				system("cls");
			}
		}
		else
		{
			cout << "��Ʒ���Ʋ�����" << endl;
			system("pause");
			system("cls");
		}
	}
	else
	{
		cout << "��������" << endl;
		system("pause");
		system("cls");
	}

}

//�̵���Ʒ
void SalesSystem::checkGoods(User& u)
{

	show();

	cout << "�Ƿ����ƽ�⣿( Y/N ):>" << endl;
	string choice;
	cin >> choice;
	if (choice == "1" || choice == "Y" || choice == "y" || choice == "yes" || choice == "YES")
	{
		cout << "��ѡ��ƽ�ⷽʽ" << endl;
		cout << "1.����" << endl;
		cout << "2.��� " << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			cout << "������Ҫ�������Ʒ���:>" << endl;
			int id = 0;
			cin >> id;
			if (findGoodsID(id) >= 0)
			{
				cout << "��Ʒ���" << "\t" << "��Ʒ����" << "\t" << "��Ʒ��λ" << "\t" << "��Ʒ�۸�" << "\t" << "��Ʒ�������" << endl;
				goods_arr[findGoodsID(id)].show();
				int num = 0;
				cout << "�������������:>" << endl;
				cin >> num;
				if (num > 0 && num <= goods_arr[findGoodsID(id)].getNum())
				{
					goods_arr[findGoodsID(id)].subNum(num);
					cout << "����ɹ�" << endl;
					//�����ļ�
					update();

					//��¼����
					string operation = "��Ʒ����";
					string  user_name = u.getUserName();
					History h1(id, user_name, num, operation);

					system("pause");
					system("cls");
				}
				else
				{
					cout << "������������" << endl;
					system("pause");
					system("cls");
				}
			}
			else
			{
				cout << "��Ʒ��Ų�����" << endl;
				system("pause");
				system("cls");
			}
		}
		else if (select == 2)
		{
			cout << "������Ҫ������Ʒ���:>" << endl;
			int id = 0;
			cin >> id;
			if (findGoodsID(id) >= 0)
			{
				cout << "��Ʒ���" << "\t" << "��Ʒ����" << "\t" << "��Ʒ��λ" << "\t" << "��Ʒ�۸�" << "\t" << "��Ʒ�������" << endl;
				goods_arr[findGoodsID(id)].show();
				int num = 0;
				cout << "�������������:>" << endl;
				cin >> num;
				if (num > 0)
				{
					goods_arr[findGoodsID(id)].addNum(num);
					cout << "���ɹ�" << endl;
					//�����ļ�
					update();

					//��¼����
					string operation = "��Ʒ���";
					string  user_name = u.getUserName();
					History h1(id, user_name, num, operation);

					system("pause");
					system("cls");
				}
				else
				{
					cout << "�����������" << endl;
					system("pause");
					system("cls");
				}
			}
			else
			{
				cout << "��Ʒ��Ų�����" << endl;
				system("pause");
				system("cls");
			}
		}
	}
	else if (choice == "2" || choice == "N" || choice == "n" || choice == "NO" || choice == "no")
	{
		system("pause");
		system("cls");
		return;
	}
	else
	{
		cout << "��������" << endl;
		system("pause");
		system("cls");
	}
}		




//������Ʒ(������Ʒ���)
int SalesSystem::findGoodsID(int id)
{
	for (int i = 0; i < this->goods_arr.size(); i++)
	{
		if (this->goods_arr[i].getID() == id)
		{
			return i;
		}
	}
	return -1;
}

//������Ʒ(������Ʒ����)
int SalesSystem::findGoodsName(string name)
{
	for (int i = 0; i < this->goods_arr.size(); i++)
	{
		if (this->goods_arr[i].getName() == name)
		{
			return i;
		}
	}
	return -1;
}

//����ɾ����Ʒ�����Ϣ
void SalesSystem::update()
{
	ofstream ofs;
	ofs.open("goods.txt", ios::out);
	
	if (!ofs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}

	for (int i = 0; i < this->goods_arr.size(); i++)
	{
		ofs << this->goods_arr[i].getID() << " " << this->goods_arr[i].getName() << " " << this->goods_arr[i].getUnit() << " " << this->goods_arr[i].getPrice() << " " << this->goods_arr[i].getNum() << endl;
	}

	ofs.close();

}


//�˳���¼
bool SalesSystem::logOut()
{
	cout << "�Ƿ��˳���¼��" << endl;
	cout << "1.Y" << endl;
	cout << "2.N" << endl;
	string choice;
	cin >> choice;
	if (choice == "1" || choice == "Y" || choice == "y" || choice == "yes" || choice == "YES")
	{
		cout << "�˳���¼�ɹ���" << endl;
		system("pause");
		system("cls");
		return false; // ����false��operation.cpp�е�is_continue���գ���ʾ���ټ������˳���Ʒ�������
	}
	else if(choice == "2" || choice == "N" || choice == "n" || choice == "NO" || choice == "no")
	{
		system("pause");
		system("cls");
		return true; // ����true��operation.cpp�е�is_continue���գ���ʾ���������˳���Ʒ�������

	}
	else
	{
		cout << "ѡ�������ѡ��Y��ͬ���˳���/ N����ͬ���˳�)";
		logOut();
	}
	return true;
}

//��������Ʒ����
void SalesSystem::sortGoods()
{
	cout << "��ѡ������ʽ" << endl;
	cout << "1.����Ʒ�������" << endl;
	cout << "2.����Ʒ��������" << endl;
	cout << "3.����Ʒ�۸�����" << endl;
	cout << "4.����Ʒ�����������" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		cout<<"1.����"<<endl;
		cout<<"2.����"<<endl;
		cout << "��ѡ������ʽ:>" << endl;
		int choice = 0;
		cin >> choice;
		if (choice == 1)
		{
			for (int i = 0; i < this->goods_arr.size(); i++)
			{
				for (int j = 0; j < this->goods_arr.size() - i - 1; j++)
				{
					if (this->goods_arr[j].getID() > this->goods_arr[j + 1].getID())
					{
						Goods temp = this->goods_arr[j];
						this->goods_arr[j] = this->goods_arr[j + 1];
						this->goods_arr[j + 1] = temp;
					}
				}
			}
			cout << "��Ʒ���" << "\t" << "��Ʒ����" << "\t" << "��Ʒ��λ" << "\t" << "��Ʒ�۸�" << "\t" << "��Ʒ�������" << endl;
			for (int i = 0; i < this->goods_arr.size(); i++)
			{
				this->goods_arr[i].show();
			}
			system("pause");
			system("cls");
		}
		else if (choice == 2)
		{
			for (int i = 0; i < this->goods_arr.size(); i++)
			{
				for (int j = 0; j < this->goods_arr.size() - i - 1; j++)
				{
					if (this->goods_arr[j].getID() < this->goods_arr[j + 1].getID())
					{
						Goods temp = this->goods_arr[j];
						this->goods_arr[j] = this->goods_arr[j + 1];
						this->goods_arr[j + 1] = temp;
					}
				}
			}
			cout << "��Ʒ���" << "\t" << "��Ʒ����" << "\t" << "��Ʒ��λ" << "\t" << "��Ʒ�۸�" << "\t" << "��Ʒ�������" << endl;
			for (int i = 0; i < this->goods_arr.size(); i++)
			{
				this->goods_arr[i].show();
			}
			system("pause");
			system("cls");
		}
		else
		{
			cout << "��������" << endl;
			sortGoods();
			system("pause");
			system("cls");
		}
	}
	else if (select == 2)
	{
		cout << "1.����" << endl;
		cout << "2.����" << endl;
		cout << "��ѡ������ʽ:>" << endl;
		int choice = 0;
		cin >> choice;
		if (choice == 1)
		{
			for (int i = 0; i < this->goods_arr.size(); i++)
			{
				for (int j = 0; j < this->goods_arr.size() - i - 1; j++)
				{
					if (this->goods_arr[j].getName() > this->goods_arr[j + 1].getName())
					{
						Goods temp = this->goods_arr[j];
						this->goods_arr[j] = this->goods_arr[j + 1];
						this->goods_arr[j + 1] = temp;
					}
				}
			}
			cout << "��Ʒ���" << "\t" << "��Ʒ����" << "\t" << "��Ʒ��λ" << "\t" << "��Ʒ�۸�" << "\t" << "��Ʒ�������" << endl;
			for (int i = 0; i < this->goods_arr.size(); i++)
			{
				this->goods_arr[i].show();
			}
			system("pause");
			system("cls");
		}
		else if (choice == 2)
		{
			for (int i = 0; i < this->goods_arr.size(); i++)
			{
				for (int j = 0; j < this->goods_arr.size() - i - 1; j++)
				{
					if (this->goods_arr[j].getName() < this->goods_arr[j + 1].getName())
					{
						Goods temp = this->goods_arr[j];
						this->goods_arr[j] = this->goods_arr[j + 1];
						this->goods_arr[j + 1] = temp;
					}
				}
			}
			cout << "��Ʒ���" << "\t" << "��Ʒ����" << "\t" << "��Ʒ��λ" << "\t" << "��Ʒ�۸�" << "\t" << "��Ʒ�������" << endl;
			for (int i = 0; i < this->goods_arr.size(); i++)
			{
				this->goods_arr[i].show();
			}
			system("pause");
			system("cls");
		}
		else
		{
			cout << "��������" << endl;
			sortGoods();
			system("pause");
			system("cls");
		}
	}
	else if (select == 3)
	{
		cout << "1.����" << endl;
		cout << "2.����" << endl;
		cout << "��ѡ������ʽ:>" << endl;
		int choice = 0;
		cin >> choice;
		if (choice == 1)
		{
			for (int i = 0; i < this->goods_arr.size(); i++)
			{
				for (int j = 0; j < this->goods_arr.size() - i - 1; j++)
				{
					if (this->goods_arr[j].getPrice() > this->goods_arr[j + 1].getPrice())
					{
						Goods temp = this->goods_arr[j];
						this->goods_arr[j] = this->goods_arr[j + 1];
						this->goods_arr[j + 1] = temp;
					}
				}
			}
			cout << "��Ʒ���" << "\t" << "��Ʒ����" << "\t" << "��Ʒ��λ" << "\t" << "��Ʒ�۸�" << "\t" << "��Ʒ�������" << endl;
			for (int i = 0; i < this->goods_arr.size(); i++)
			{
				this->goods_arr[i].show();
			}
			system("pause");
			system("cls");
		}
		else if (choice == 2)
		{
			for (int i = 0; i < this->goods_arr.size(); i++)
			{
				for (int j = 0; j < this->goods_arr.size() - i - 1; j++)
				{
					if (this->goods_arr[j].getPrice() < this->goods_arr[j + 1].getPrice())
					{
						Goods temp = this->goods_arr[j];
						this->goods_arr[j] = this->goods_arr[j + 1];
						this->goods_arr[j + 1] = temp;
					}
				}
			}
			cout << "��Ʒ���" << "\t" << "��Ʒ����" << "\t" << "��Ʒ��λ" << "\t" << "��Ʒ�۸�" << "\t" << "��Ʒ�������" << endl;
			for (int i = 0; i < this->goods_arr.size(); i++)
			{
				this->goods_arr[i].show();
			}
			system("pause");
			system("cls");
		}
		else
		{
			cout << "��������" << endl;
			sortGoods();
			system("pause");
			system("cls");
		}
	}
	else if (select == 4)
	{
		cout << "1.����" << endl;
		cout << "2.����" << endl;
		cout << "��ѡ������ʽ:>" << endl;
		int choice = 0;
		cin >> choice;
		if (choice == 1)
		{
			for (int i = 0; i < this->goods_arr.size(); i++)
			{
				for (int j = 0; j < this->goods_arr.size() - i - 1; j++)
				{
					if (this->goods_arr[j].getNum() > this->goods_arr[j + 1].getNum())
					{
						Goods temp = this->goods_arr[j];
						this->goods_arr[j] = this->goods_arr[j + 1];
						this->goods_arr[j + 1] = temp;
					}
				}
			}
			cout << "��Ʒ���" << "\t" << "��Ʒ����" << "\t" << "��Ʒ��λ" << "\t" << "��Ʒ�۸�" << "\t" << "��Ʒ�������" << endl;
			for (int i = 0; i < this->goods_arr.size(); i++)
			{
				this->goods_arr[i].show();
			}
			system("pause");
			system("cls");
		}
		else if (choice == 2)
		{
			for (int i = 0; i < this->goods_arr.size(); i++)
			{
				for (int j = 0; j < this->goods_arr.size() - i - 1; j++)
				{
					if (this->goods_arr[j].getNum() < this->goods_arr[j + 1].getNum())
					{
						Goods temp = this->goods_arr[j];
						this->goods_arr[j] = this->goods_arr[j + 1];
						this->goods_arr[j + 1] = temp;
					}
				}
			}
			cout << "��Ʒ���" << "\t" << "��Ʒ����" << "\t" << "��Ʒ��λ" << "\t" << "��Ʒ�۸�" << "\t" << "��Ʒ�������" << endl;
			for (int i = 0; i < this->goods_arr.size(); i++)
			{
				this->goods_arr[i].show();
			}
			system("pause");
			system("cls");
		}
		else
		{
			cout << "��������" << endl;
			sortGoods();
			system("pause");
			system("cls");
		}
	}
	else
	{
		cout << "��������" << endl;
		sortGoods();
		system("pause");
		system("cls");
	}
}

//��ȡ��ǰʱ��
string getNowTime()
{
	string time_now;

	// ��ȡ��ǰʱ��
	time_t now = time(0);

	// ����ǰʱ��ת��Ϊ����ʱ��
	std::tm local_time{};
	localtime_s(&local_time, &now);

	// ��ʾ��ǰʱ��
	//std::cout << "��ǰʱ��Ϊ: "
	//	<< local_time.tm_year + 1900 << "-"
	//	<< local_time.tm_mon + 1 << "-"
	//	<< local_time.tm_mday << " "
	//	<< local_time.tm_hour << ":"
	//	<< local_time.tm_min << ":"
	//	<< local_time.tm_sec
	//	<< std::endl;
	
	time_now = to_string(local_time.tm_year + 1900) + "-" + to_string(local_time.tm_mon + 1) + "-" + to_string(local_time.tm_mday) + " " + to_string(local_time.tm_hour) + ":" + to_string(local_time.tm_min) + ":" + to_string(local_time.tm_sec);
	
	return time_now;
}


History::History(int id, string opeeration, int num, string Username )
{
	m_ID = id;
	m_Username = Username;
	m_Operation = opeeration;
	m_Num = num;
	m_Time = getNowTime();
	//���浽�ļ���
	ofstream ofs;
	ofs.open("history.txt", ios::out | ios::app);
	if (!ofs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	ofs << m_ID << "\t" << "\t" << m_Username << "\t" << m_Operation << "\t" << m_Num << "\t" << m_Time << endl;

	ofs.close();
}



void SalesSystem::showHistory()
{
	//��ȡ�ļ��е�����
	ifstream ifs;
	ifs.open("history.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	string line;

	//չʾ
	cout << "��Ʒ���" << "\t"  << "������ʽ" << "\t"  << "����Ա" << "\t"  << "����" << "\t" << "ʱ��" << endl;
	while (getline(ifs, line))
	{
		cout << line << endl;
	}
	ifs.close();
	system("pause");
	system("cls");

}
