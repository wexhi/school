#include"operation.h"
#include"Users.h"
#include"Sales_item.h"

//������Ʒ�������
bool Sales_item(User& u)
{
	int choice = 0;
	SalesSystem sal;
	bool is_continue = true;//�ж��Ƿ����



	while (is_continue)
	{
		sal.showMenu();//չʾ�˵�
		cin >> choice;
		string confirm;//�жϣ���case 8��ʹ��

		switch (choice)
		{
		case 0:
			//�˳���¼
			is_continue = sal.logOut();
			if (is_continue == false)
			{
				return false;
			}
			break;
		
		case 1:
			//������Ʒ
			sal.createGoods(u);
			break;
		case 2:
			//ɾ����Ʒ
			sal.deleteGoods(u);
			break;
		case 3:
			//��Ʒ����
			sal.addGoods(u);
			break;
		case 4:
			//��Ʒ����
			sal.saleGoods(u);
			break;

		case 5:
			//չʾ��Ʒ��Ϣ
			sal.showGoods();
			break;

		case 6:
			//��ʾ������¼�����ԣ�
			sal.showHistory();
			break;

		case 7:
			//�̵���Ʒ
			sal.checkGoods(u);
			break;

		case 8:
			//�����û��������
			cout << "ȷ���Ƿ�����û�������棨Ϊ�˰�ȫ���ǣ��������Ҫ���µ�½��^-^" << endl;
			//bug�޲�����........
			cout << "Y / N" << endl;

			cin >> confirm;
			if (confirm == "1" || confirm == "Y" || confirm == "y" || confirm == "yes" || confirm == "YES")
			{ 
				//is_continue = false;
				return true;
			}
			else if (confirm == "2" || confirm == "N" || confirm == "n" || confirm == "NO" || confirm == "no")
			{
				break;
			}
			else
			{
				system("cls");
				cout << "�����������������" << endl;
				break;
			}
			break;
		case 9:
			//������Ʒ
			sal.sortGoods();
			break;

		default:
			break;
		}
	}
	return true;
}


void User_item()
{
	bool is_login = false; //�ж��Ƿ��¼�ɹ�
	int choice; //ѡ��˵�

	while (true)
	{
		User u;//��ѭ���ڳ�ʼ�������������Ը���ÿ�ε�½���û������޸����˳���½���¼����ʱ�û������������¼�ߵ�bug

		u.showMenu();//չʾ�û�����˵�

		cin >> choice;

		switch (choice)
		{
		case 0:
			u.exitSystem(); //�˳�ϵͳ
			break;

		case 1:
		{
			is_login = u.signIn(); //�û���¼

			//�����¼�ɹ���������Ʒ�������
			if (is_login == true)
			{
				is_login = Sales_item(u); //������Ʒ�������
				
				//�ٴ��ж��Ƿ��¼�ɹ��������¼�ɹ��������û��������
				if (is_login == true)
				{
					is_login = User_edit(u); //����༭�û����ý���
				}
				
				system("cls");
			}
			else
			{
				cout << "��¼ʧ�ܣ������µ�¼" << endl;
			}
			break;
		}
		case 2:
			u.signUp(); //�û�ע��
			break;

		case 3:
			u.sortUser(); //�û�����
			break;
		default:
			system("cls");
			break;
		}

	}
}

//����༭�û����ý���
bool User_edit(User& u)
{

	system("cls");

	int choice;
	bool is_continue = true;
	while (is_continue)
	{
		u.showEditMenu();
		cin >> choice;

		switch (choice)
		{
		case 0:
			//������Ʒ�������
			is_continue = false;
			return true;
			break;
		case 1:
			//�޸�����
			is_continue = u.changePassword();
			if (is_continue == false)
			{
				return false;
			}
			break;
		case 2:
			//�޸��û���
			is_continue = u.changeUsername();
			if (is_continue == false)
			{
				return false;
			}
			break;
		case 3:
			//ɾ���û�
			is_continue = u.deleteUser();
			if (is_continue == false)
			{
				return false;
			}
			break;
		default:
			break;
		}
	}
	return true;
}