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
			i = 0;//��ʼ��i�����²����Ƿ����ظ��ģ���ֹ�޷��ҵ�֮ǰ���ظ�
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
			i = 0;//��ʼ��i�����²����Ƿ����ظ��ģ���ֹ�޷��ҵ�֮ǰ���ظ�
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

	//����Ʒ��Ϣд������,����֮��Ĳ���
	goods_arr.push_back(goods);

	//��Ʒ����+1
	this->m_allGoodsNums++;

	//��¼������¼
	History(id, name, u.getUserName(), 1, "������Ʒ");

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
		system("pause");
		system("cls");
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
		goods_arr[i].show();//������õ���Goods���ں���
	}
}


//ɾ����Ʒ
void SalesSystem::deleteGoods(User &u)
{
	if (m_allGoodsNums == 0)
	{
		cout << "��ǰû����Ʒ��Ϣ" << endl;
		system("pause");
		system("cls");
		return;
	}

	show();//���ǵ���SalesSystem��ĺ���

	string choice;
	cout << "��ѡ��ɾ����ʽ:>" << endl;
	cout << "1.����Ʒ���ɾ��" << endl;
	cout << "2.����Ʒ����ɾ��" << endl;
	cin >> choice;

	if (choice ==  "1" || choice == "����Ʒ���ɾ��" || choice == "1.����Ʒ���ɾ��" || choice == "��Ʒ���")
	{
		int id = 0;
		cout << "������Ҫɾ������Ʒ���:>" << endl;
		cin >> id;
		
		if (findGoodsID(id) >= 0)
		{
			//��¼����
			History(id, goods_arr[findGoodsID(id)].getName(), u.getUserName(), 1, "ɾ����Ʒ");

			//ɾ����Ʒ
			this->goods_arr.erase(this->goods_arr.begin() + findGoodsID(id));
			this->m_allGoodsNums--;//��Ʒ��������-1
			
			//�����ļ�
			update();

			cout << "ɾ����Ʒ�ɹ�" << endl;
		}
		else
		{
			cout << "��Ʒ��Ų�����" << endl;
		}
	}
	else if (choice == "2" || choice == "����Ʒ����ɾ��" || choice == "2.����Ʒ����ɾ��" || choice == "��Ʒ����")
	{
		string name;
		cout << "��������Ʒ����:>" << endl;
		cin >> name;
		
		if (findGoodsName(name) >= 0)
		{
			//��ɾ�����±���ʧ�������Ҫ��ǰ��¼
			//��¼����
			int id = this->goods_arr[findGoodsName(name)].getID();
			History(id, name, u.getUserName(), 1, "ɾ����Ʒ");

			//ɾ����Ʒ
			this->goods_arr.erase(this->goods_arr.begin() + findGoodsName(name));
			this->m_allGoodsNums--;//��Ʒ��������-1
			
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
int SalesSystem::getGoodsNums()
{
	ifstream ifs;
	ifs.open("goods.txt", ios::in);
	if (!ifs.is_open())
	{
		ofstream ofs("goods.txt", ios::out);
		ofs.close();
		ifs.open("goods.txt", ios::in);
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
	if (m_allGoodsNums == 0)
	{
		cout << "��ǰû����Ʒ��Ϣ" << endl;
		system("pause");
		system("cls");
		return;
	}

	show();

	string choice;
	cout << "��ѡ�������ʽ:>" << endl;
	cout << "1.����Ʒ��Ž���" << endl;
	cout << "2.����Ʒ���ƽ���" << endl;
	cin >> choice;
	
	if (choice == "1" || choice == "����Ʒ��Ž���" || choice == "1.����Ʒ��Ž���" || choice == "��Ʒ���")
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
				cout << endl << "�����ɹ�!" << endl;
				cout << "��Ʒ���" << "\t" << "��Ʒ����" << "\t" << "��Ʒ��λ" << "\t" << "��Ʒ�۸�" << "\t" << "��Ʒ�������" << endl;
				goods_arr[findGoodsID(id)].show();
				//�����ļ�
				update();

				//��¼����
				History(id, goods_arr[findGoodsID(id)].getName(), u.getUserName(), num, "��Ʒ����");

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
	else if (choice == "2" || choice == "����Ʒ���ƽ���" || choice == "2.����Ʒ���ƽ���" || choice == "��Ʒ����")
	{
		string name;
		cout << "��������Ʒ����:>" << endl;
		cin >> name;
		
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
				cout << endl << "�����ɹ�!" << endl;
				cout << "��Ʒ���" << "\t" << "��Ʒ����" << "\t" << "��Ʒ��λ" << "\t" << "��Ʒ�۸�" << "\t" << "��Ʒ�������" << endl;
				goods_arr[findGoodsName(name)].show();
				//�����ļ�
				update();

				//��¼����
				History(goods_arr[findGoodsName(name)].getID(), name, u.getUserName(), num, "��Ʒ����");

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
	if (m_allGoodsNums == 0)
	{
		cout << "��ǰû����Ʒ��Ϣ" << endl;
		system("pause");
		system("cls");
		return;
	}

	show();

	string choice;
	cout << "��ѡ�����۷�ʽ:>" << endl;
	cout << "1.����Ʒ�������" << endl;
	cout << "2.����Ʒ��������" << endl;
	cin >> choice;
	
	if (choice == "1" || choice == "����Ʒ�������" || choice == "1.����Ʒ�������" || choice == "��Ʒ���")
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
				cout << endl <<  "���۳ɹ�!" << endl;
				cout << "��Ʒ���" << "\t" << "��Ʒ����" << "\t" << "��Ʒ��λ" << "\t" << "��Ʒ�۸�" << "\t" << "��Ʒ�������" << endl;
				goods_arr[findGoodsID(id)].show();
				//�����ļ�
				update();

				//��¼����
				string operation = "��Ʒ����";
				string  user_name = u.getUserName();
				History(id, goods_arr[findGoodsID(id)].getName(), user_name, num, operation);

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
	else if (choice == "2" || choice == "����Ʒ��������" || choice == "2.����Ʒ��������" || choice == "��Ʒ����")
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
				cout << endl << "���۳ɹ�!" << endl;
				cout << "��Ʒ���" << "\t" << "��Ʒ����" << "\t" << "��Ʒ��λ" << "\t" << "��Ʒ�۸�" << "\t" << "��Ʒ�������" << endl;
				goods_arr[findGoodsName(name)].show();
				//�����ļ�
				update();

				//��¼����
				string operation = "��Ʒ����";
				string  user_name = u.getUserName();
				History(goods_arr[findGoodsName(name)].getID(), name, user_name, num, operation);

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
	if (m_allGoodsNums == 0)
	{
		cout << "��ǰû����Ʒ��Ϣ" << endl;
		system("pause");
		system("cls");
		return;
	}

	show();

	cout << "�Ƿ����ƽ�⣿( Y/N ):>" << endl;
	string choice;
	cin >> choice;
	if (choice == "1" || choice == "Y" || choice == "y" || choice == "yes" || choice == "YES")
	{
		cout << "��ѡ��ƽ�ⷽʽ" << endl;
		cout << "1.����" << endl;
		cout << "2.��� " << endl;
		string select;
		cin >> select;
		if (select == "1" || select == "����" || select == "1.����")
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
					cout << endl << "����ɹ�!" << endl;
					cout << "��Ʒ���" << "\t" << "��Ʒ����" << "\t" << "��Ʒ��λ" << "\t" << "��Ʒ�۸�" << "\t" << "��Ʒ�������" << endl;
					goods_arr[findGoodsID(id)].show();
					//�����ļ�
					update();

					//��¼����
					string operation = "��Ʒ����";
					string  user_name = u.getUserName();
					History(id, goods_arr[findGoodsID(id)].getName(), user_name,  num, operation);

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
		else if (select == "2" || select == "���" || select == "2.���")
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
					cout << endl << "���ɹ�!" << endl;
					cout << "��Ʒ���" << "\t" << "��Ʒ����" << "\t" << "��Ʒ��λ" << "\t" << "��Ʒ�۸�" << "\t" << "��Ʒ�������" << endl;
					goods_arr[findGoodsID(id)].show();
					//�����ļ�
					update();

					//��¼����
					string operation = "��Ʒ���";
					string  user_name = u.getUserName();
					History(id, goods_arr[findGoodsID(id)].getName(), user_name, num, operation);

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
	//����ѭ���������ڱ������ң����ҵ��������±꣬�Ҳ���������-1
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
	//����ѭ���������ڱ������ң����ҵ��������±꣬�Ҳ���������-1
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
	if (m_allGoodsNums == 0)
	{
		cout << "��ǰû����Ʒ��Ϣ" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "��ѡ������ʽ" << endl;
	cout << "1.����Ʒ�������" << endl;
	cout << "2.����Ʒ��������" << endl;
	cout << "3.����Ʒ�۸�����" << endl;
	cout << "4.����Ʒ�����������" << endl;
	string select;
	cin >> select;
	if (select == "1" || select == "1.����Ʒ�������" || select == "����Ʒ�������" || select == "��Ʒ���")
	{
		cout<<"1.����"<<endl;
		cout<<"2.����"<<endl;
		cout << "��ѡ������ʽ:>" << endl;
		string choice;
		cin >> choice;
		if (choice == "1" || choice == "����" || choice == "1.����")
		{
			for (size_t i = 0; i < this->goods_arr.size(); i++)
			{
				for (size_t j = 0; j < this->goods_arr.size() - i - 1; j++)
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

			//�����ļ�
			update();
			system("pause");
			system("cls");
		}
		else if (choice == "2" || choice == "����" || choice == "2.����")
		{
			for (size_t i = 0; i < this->goods_arr.size(); i++)
			{
				for (size_t j = 0; j < this->goods_arr.size() - i - 1; j++)
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

			//�����ļ�
			update();
			system("pause");
			system("cls");
		}
		else
		{
			cout << "��������" << endl;
			system("pause");
			system("cls");
		}
	}
	else if (select == "2" || select == "2.����Ʒ��������" || select == "����Ʒ��������" || select == "��Ʒ����")
	{
		cout << "1.����" << endl;
		cout << "2.����" << endl;
		cout << "��ѡ������ʽ:>" << endl;
		string choice;
		cin >> choice;
		if (choice == "1" || choice == "����" || choice == "1.����")
		{
			for (size_t i = 0; i < this->goods_arr.size(); i++)
			{
				for (size_t j = 0; j < this->goods_arr.size() - i - 1; j++)
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

			//�����ļ�
			update();
			system("pause");
			system("cls");
		}
		else if (choice == "2" || choice == "����" || choice == "2.����")
		{
			for (size_t i = 0; i < this->goods_arr.size(); i++)
			{
				for (size_t j = 0; j < this->goods_arr.size() - i - 1; j++)
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

			//�����ļ�
			update();
			system("pause");
			system("cls");
		}
		else
		{
			cout << "��������" << endl;
			system("pause");
			system("cls");
		}
	}
	else if (select == "3" || select == "3.����Ʒ�۸�����" || select == "����Ʒ�۸�����" || select == "��Ʒ�۸�")
	{
		cout << "1.����" << endl;
		cout << "2.����" << endl;
		cout << "��ѡ������ʽ:>" << endl;
		string choice;
		cin >> choice;
		if (choice == "1" || choice == "����" || choice == "1.����")
		{
			for (size_t i = 0; i < this->goods_arr.size(); i++)
			{
				for (size_t j = 0; j < this->goods_arr.size() - i - 1; j++)
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

			//�����ļ�
			update();
			system("pause");
			system("cls");
		}
		else if (choice == "2" || choice == "����" || choice == "2.����")
		{
			for (size_t i = 0; i < this->goods_arr.size(); i++)
			{
				for (size_t j = 0; j < this->goods_arr.size() - i - 1; j++)
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

			//�����ļ�
			update();
			system("pause");
			system("cls");
		}
		else
		{
			cout << "��������" << endl;
			system("pause");
			system("cls");
		}
	}
	else if (select == "4" || select == "4.����Ʒ�����������" || select == "����Ʒ�����������" || select == "��Ʒ�������")
	{
		cout << "1.����" << endl;
		cout << "2.����" << endl;
		cout << "��ѡ������ʽ:>" << endl;
		string choice;
		cin >> choice;
		if (choice == "1" || choice == "����" || choice == "1.����")
		{
			for (size_t i = 0; i < this->goods_arr.size(); i++)
			{
				for (size_t j = 0; j < this->goods_arr.size() - i - 1; j++)
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

			//�����ļ�
			update();
			system("pause");
			system("cls");
		}
		else if (choice == "2" || choice == "����" || choice == "2.����")
		{
			for (size_t i = 0; i < this->goods_arr.size(); i++)
			{
				for (size_t j = 0; j < this->goods_arr.size() - i - 1; j++)
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

			//�����ļ�
			update();
			system("pause");
			system("cls");
		}
		else
		{
			cout << "��������" << endl;
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

//��ȡ��ǰʱ��
static string getNowTime()
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
	
	//�ж�Сʱ�����ӡ����Ƿ�Ϊ��λ�������������ǰ���0
	if (local_time.tm_hour < 10)
	{
		time_now = to_string(local_time.tm_year + 1900) + "-" + to_string(local_time.tm_mon + 1) + "-" + to_string(local_time.tm_mday) + " " + "0" + to_string(local_time.tm_hour) + ":";
	}
	else
	{
		time_now = to_string(local_time.tm_year + 1900) + "-" + to_string(local_time.tm_mon + 1) + "-" + to_string(local_time.tm_mday) + " " + to_string(local_time.tm_hour) + ":";
	}

	if (local_time.tm_min < 10)
	{
		time_now += "0" + to_string(local_time.tm_min) + ":";
	}
	else
	{
		time_now += to_string(local_time.tm_min) + ":";
	}

	if (local_time.tm_sec < 10)
	{
		time_now += "0" + to_string(local_time.tm_sec);
	}
	else
	{
		time_now += to_string(local_time.tm_sec);
	}

	
	return time_now;
}


void SalesSystem::History(int id, string goods_name,string opeeration, int num, string Username )
{

	string time = getNowTime();
	//���浽�ļ���
	ofstream ofs;
	ofs.open("history.txt", ios::out | ios::app);
	if (!ofs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	ofs << id << "\t" << "\t" << goods_name <<"\t" << "\t" << Username << "\t" << opeeration << "\t" << num << "\t" << time << endl;

	ofs.close();
}



void SalesSystem::showHistory()
{
	//��ȡ�ļ��е�����
	ifstream ifs;
	ifs.open("history.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ�ܣ�����ԭ��δ����Ʒ�����κβ�����" << endl;
		system("pause");
		system("cls");
		return;
	}
	string line;

	//չʾ
	cout << "��Ʒ���" << "\t"  <<  "��Ʒ����" << "\t" << "������ʽ" << "\t" << "����Ա" << "\t" << "����" << "\t" << "ʱ��" << endl << endl;
	while (getline(ifs, line))
	{
		cout << line << endl;
		cout <<"---------------------------------------------------------------------------------" << endl;
	}
	
	ifs.close();
	system("pause");
	system("cls");
}