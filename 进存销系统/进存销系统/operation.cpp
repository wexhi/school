#include"operation.h"
#include"Users.h"
#include"Sales_item.h"

//进入商品管理界面
bool Sales_item(User& u)
{
	int choice = 0;
	SalesSystem sal;
	bool is_continue = true;//判断是否继续



	while (is_continue)
	{
		sal.showMenu();//展示菜单
		cin >> choice;
		string confirm;//判断，在case 8中使用

		switch (choice)
		{
		case 0:
			//退出登录
			is_continue = sal.logOut();
			if (is_continue == false)
			{
				return false;
			}
			break;
		
		case 1:
			//增加商品
			sal.createGoods(u);
			break;
		case 2:
			//删除商品
			sal.deleteGoods(u);
			break;
		case 3:
			//商品进货
			sal.addGoods(u);
			break;
		case 4:
			//商品销售
			sal.saleGoods(u);
			break;

		case 5:
			//展示商品信息
			sal.showGoods();
			break;

		case 6:
			//显示操作记录（测试）
			sal.showHistory();
			break;

		case 7:
			//盘点商品
			sal.checkGoods(u);
			break;

		case 8:
			//进入用户管理界面
			cout << "确认是否进入用户管理界面（为了安全考虑，进入后需要重新登陆）^-^" << endl;
			//bug修不好了........
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
				cout << "输入错误，请重新输入" << endl;
				break;
			}
			break;
		case 9:
			//排序商品
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
	bool is_login = false; //判断是否登录成功
	int choice; //选择菜单

	while (true)
	{
		User u;//在循环内初始化对象，这样可以更新每次登陆的用户名，修复了退出登陆后记录操作时用户名仍是最初登录者的bug

		u.showMenu();//展示用户界面菜单

		cin >> choice;

		switch (choice)
		{
		case 0:
			u.exitSystem(); //退出系统
			break;

		case 1:
		{
			is_login = u.signIn(); //用户登录

			//如果登录成功，进入商品管理界面
			if (is_login == true)
			{
				is_login = Sales_item(u); //进入商品管理界面
				
				//再次判断是否登录成功，如果登录成功，进入用户管理界面
				if (is_login == true)
				{
					is_login = User_edit(u); //进入编辑用户设置界面
				}
				
				system("cls");
			}
			else
			{
				cout << "登录失败，请重新登录" << endl;
			}
			break;
		}
		case 2:
			u.signUp(); //用户注册
			break;

		case 3:
			u.sortUser(); //用户排序
			break;
		default:
			system("cls");
			break;
		}

	}
}

//进入编辑用户设置界面
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
			//返回商品管理界面
			is_continue = false;
			return true;
			break;
		case 1:
			//修改密码
			is_continue = u.changePassword();
			if (is_continue == false)
			{
				return false;
			}
			break;
		case 2:
			//修改用户名
			is_continue = u.changeUsername();
			if (is_continue == false)
			{
				return false;
			}
			break;
		case 3:
			//删除用户
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