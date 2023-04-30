#include"Sales_item.h"

//构造函数
SalesSystem::SalesSystem()
{
	cout << "请按下任意键进入进存销系统:>" << endl;
	system("pause");
	system("cls");


	this->m_allGoodsNums = getGoodsNums();

	//初始化商品
	initGoods();

	//测试
	//getGoodsNums();
}

//初始化商品
void SalesSystem::initGoods()
{
	ifstream ifs;
	ifs.open("goods.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}

	//读取商品信息
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


//展示选择菜单
void SalesSystem :: showMenu()
{

	cout << " ********************************** " << endl;
	cout << " *********** 进存销系统 *********** " << endl;
	cout << " *********** 1.新增商品 *********** " << endl;
	cout << " *********** 2.删除商品 *********** " << endl;
	cout << " *********** 3.商品进货 *********** " << endl;
	cout << " *********** 4.商品销售 *********** " << endl;
	cout << " ********* 5.展示商品信息 ********* " << endl;
	cout << " ********* 6.显示操作记录 ********* " << endl;
	cout << " *********** 7.盘点商品 *********** " << endl;
	cout << " ******* 8.进入用户管理界面 ******* " << endl;
	cout << " *********** 9.排序商品 *********** " << endl;
	cout << " *********** 0.退出登录 *********** " << endl;
	cout << " ********************************** " << endl;

}

//新增商品
void  SalesSystem::createGoods(User &u)
{

	int id;
	cout << "请输入商品编号:>" << endl;
	cin >> id;
	//判断商品编号是否重复
	for (int i = 0; i < this->goods_arr.size(); i++)
	{
		while (this->goods_arr[i].getID() == id)
		{
			cout << "商品编号重复，请重新输入" << endl;
			i = 0;//初始化i，重新查找是否有重复的，防止无法找到之前的重复
			cin >> id;
		}
	}

	string name;
	cout << "请输入商品名称:>" << endl;
	cin >> name;
	
	//判断商品名称是否重复
	for (int i = 0; i < this->goods_arr.size(); i++)
	{
		while (this->goods_arr[i].getName() == name)
		{
			cout << "商品名称重复，请重新输入" << endl;
			i = 0;//初始化i，重新查找是否有重复的，防止无法找到之前的重复
			cin >> name;
		}
	}

	string unit;
	cout << "请输入商品单位:>" << endl;
	cin >> unit;

	double price;
	cout << "请输入商品价格:>" << endl;
	cin >> price;

	int num;
	cout << "请输入商品库存数量:>" << endl;
	cin >> num;

	Goods goods(id, name, unit, price, num);

	//将商品信息写入文件
	goods.save();

	//将商品信息写入容器,方便之后的操作
	goods_arr.push_back(goods);

	//商品数量+1
	this->m_allGoodsNums++;

	//记录操作记录
	History(id, name, u.getUserName(), 1, "新增商品");

	cout << "新增商品成功" << endl;
	system("pause");
	system("cls");

}

//展示商品信息
void SalesSystem::showGoods()
{
	if (m_allGoodsNums == 0)
	{
		cout << "当前没有商品信息" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "商品编号" << "\t" << "商品名称" << "\t" << "商品单位" << "\t" << "商品价格" << "\t" << "商品库存数量" << endl;
	for (int i = 0; i < m_allGoodsNums; i++)
	{
		goods_arr[i].show();
		cout << "-----------------------------------------------------------------------------" << endl;
	}

	system("pause");
	system("cls");
}


//展示商品信息(函数内使用）
void SalesSystem::show()
{
	if (m_allGoodsNums == 0)
	{
		cout << "当前没有商品信息" << endl;
		return;
	}
	cout << "商品编号" << "\t" << "商品名称" << "\t" << "商品单位" << "\t" << "商品价格" << "\t" << "商品库存数量" << endl;
	for (int i = 0; i < this->goods_arr.size(); i++)
	{
		goods_arr[i].show();//这里调用的是Goods类内函数
	}
}


//删除商品
void SalesSystem::deleteGoods(User &u)
{
	if (m_allGoodsNums == 0)
	{
		cout << "当前没有商品信息" << endl;
		system("pause");
		system("cls");
		return;
	}

	show();//这是调用SalesSystem类的函数

	string choice;
	cout << "请选择删除方式:>" << endl;
	cout << "1.按商品编号删除" << endl;
	cout << "2.按商品名称删除" << endl;
	cin >> choice;

	if (choice ==  "1" || choice == "按商品编号删除" || choice == "1.按商品编号删除" || choice == "商品编号")
	{
		int id = 0;
		cout << "请输入要删除的商品编号:>" << endl;
		cin >> id;
		
		if (findGoodsID(id) >= 0)
		{
			//记录操作
			History(id, goods_arr[findGoodsID(id)].getName(), u.getUserName(), 1, "删除商品");

			//删除商品
			this->goods_arr.erase(this->goods_arr.begin() + findGoodsID(id));
			this->m_allGoodsNums--;//商品种类数量-1
			
			//更新文件
			update();

			cout << "删除商品成功" << endl;
		}
		else
		{
			cout << "商品编号不存在" << endl;
		}
	}
	else if (choice == "2" || choice == "按商品名称删除" || choice == "2.按商品名称删除" || choice == "商品名称")
	{
		string name;
		cout << "请输入商品名称:>" << endl;
		cin >> name;
		
		if (findGoodsName(name) >= 0)
		{
			//在删除后下标消失，因此需要提前记录
			//记录操作
			int id = this->goods_arr[findGoodsName(name)].getID();
			History(id, name, u.getUserName(), 1, "删除商品");

			//删除商品
			this->goods_arr.erase(this->goods_arr.begin() + findGoodsName(name));
			this->m_allGoodsNums--;//商品种类数量-1
			
			//更新文件
			update();
			cout << "删除商品成功" << endl;
		}
		else
		{
			cout << "商品名称不存在" << endl;
		}
	}
	else
	{
		cout << "输入有误" << endl;
	}


	system("pause");
	system("cls");
}

//获取商品种类数量
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
	
	//测试
	//cout << "商品种类数量为：" << count << endl;
	
	return count;
}

//商品进货
void SalesSystem::addGoods(User& u)
{
	if (m_allGoodsNums == 0)
	{
		cout << "当前没有商品信息" << endl;
		system("pause");
		system("cls");
		return;
	}

	show();

	string choice;
	cout << "请选择进货方式:>" << endl;
	cout << "1.按商品编号进货" << endl;
	cout << "2.按商品名称进货" << endl;
	cin >> choice;
	
	if (choice == "1" || choice == "按商品编号进货" || choice == "1.按商品编号进货" || choice == "商品编号")
	{
		int id = 0;
		cout << "请输入要进货的商品编号:>" << endl;
		cin >> id;
		if (findGoodsID(id) >= 0)
		{
			cout << "商品编号" << "\t" << "商品名称" << "\t" << "商品单位" << "\t" << "商品价格" << "\t" << "商品库存数量" << endl;
			goods_arr[findGoodsID(id)].show();
			int num = 0;
			cout << "请输入进货数量:>" << endl;
			cin >> num;
			if (num > 0)
			{
				goods_arr[findGoodsID(id)].addNum(num);
				cout << endl << "进货成功!" << endl;
				cout << "商品编号" << "\t" << "商品名称" << "\t" << "商品单位" << "\t" << "商品价格" << "\t" << "商品库存数量" << endl;
				goods_arr[findGoodsID(id)].show();
				//更新文件
				update();

				//记录操作
				History(id, goods_arr[findGoodsID(id)].getName(), u.getUserName(), num, "商品进货");

				system("pause");
				system("cls");
			}
			else
			{
				cout << "进货数量有误" << endl;
				system("pause");
				system("cls");
			}
		}
		else
		{
			cout << "商品编号不存在" << endl;
			system("pause");
			system("cls");
		}
	}
	else if (choice == "2" || choice == "按商品名称进货" || choice == "2.按商品名称进货" || choice == "商品名称")
	{
		string name;
		cout << "请输入商品名称:>" << endl;
		cin >> name;
		
		if (findGoodsName(name) >= 0)
		{
			cout << "商品编号" << "\t" << "商品名称" << "\t" << "商品单位" << "\t" << "商品价格" << "\t" << "商品库存数量" << endl;
			goods_arr[findGoodsName(name)].show();
			int num = 0;
			cout << "请输入进货数量:>" << endl;
			cin >> num;
			
			if (num > 0)
			{
				goods_arr[findGoodsName(name)].addNum(num);
				cout << endl << "进货成功!" << endl;
				cout << "商品编号" << "\t" << "商品名称" << "\t" << "商品单位" << "\t" << "商品价格" << "\t" << "商品库存数量" << endl;
				goods_arr[findGoodsName(name)].show();
				//更新文件
				update();

				//记录操作
				History(goods_arr[findGoodsName(name)].getID(), name, u.getUserName(), num, "商品进货");

				system("pause");
				system("cls");
			}
			else
			{
				cout << "进货数量有误" << endl;
				system("pause");
				system("cls");
			}
		}
		else
		{
			cout << "商品名称不存在" << endl;
			system("pause");
			system("cls");
		}
	}
	else
	{
		cout << "输入有误" << endl;
		system("pause");
		system("cls");
	}

}

//商品销售
void SalesSystem::saleGoods(User& u)
{
	if (m_allGoodsNums == 0)
	{
		cout << "当前没有商品信息" << endl;
		system("pause");
		system("cls");
		return;
	}

	show();

	string choice;
	cout << "请选择销售方式:>" << endl;
	cout << "1.按商品编号销售" << endl;
	cout << "2.按商品名称销售" << endl;
	cin >> choice;
	
	if (choice == "1" || choice == "按商品编号销售" || choice == "1.按商品编号销售" || choice == "商品编号")
	{
		int id = 0;
		cout << "请输入要销售的商品编号:>" << endl;
		cin >> id;
		
		if (findGoodsID(id) >= 0)
		{
			cout << "商品编号" << "\t" << "商品名称" << "\t" << "商品单位" << "\t" << "商品价格" << "\t" << "商品库存数量" << endl;
			goods_arr[findGoodsID(id)].show();
			int num = 0;
			cout << "请输入销售数量:>" << endl;
			cin >> num;
			
			if (num > 0 && num <= goods_arr[findGoodsID(id)].getNum())
			{
				goods_arr[findGoodsID(id)].subNum(num);
				cout << endl <<  "销售成功!" << endl;
				cout << "商品编号" << "\t" << "商品名称" << "\t" << "商品单位" << "\t" << "商品价格" << "\t" << "商品库存数量" << endl;
				goods_arr[findGoodsID(id)].show();
				//更新文件
				update();

				//记录操作
				string operation = "商品销售";
				string  user_name = u.getUserName();
				History(id, goods_arr[findGoodsID(id)].getName(), user_name, num, operation);

				system("pause");
				system("cls");
			}
			else
			{
				cout << "销售数量有误" << endl;
				system("pause");
				system("cls");
			}
		}
		else
		{
			cout << "商品编号不存在" << endl;
			system("pause");
			system("cls");
		}
	}
	else if (choice == "2" || choice == "按商品名称销售" || choice == "2.按商品名称销售" || choice == "商品名称")
	{
		string name;
		cout << "请输入商品名称:>" << endl;
		cin >> name;
		//判断商品名称是否重复
		if (findGoodsName(name) >= 0)
		{
			cout << "商品编号" << "\t" << "商品名称" << "\t" << "商品单位" << "\t" << "商品价格" << "\t" << "商品库存数量" << endl;
			goods_arr[findGoodsName(name)].show();
			int num = 0;
			cout << "请输入销售数量:>" << endl;
			cin >> num;
			if (num > 0 && num <= goods_arr[findGoodsName(name)].getNum())
			{
				goods_arr[findGoodsName(name)].subNum(num);
				cout << endl << "销售成功!" << endl;
				cout << "商品编号" << "\t" << "商品名称" << "\t" << "商品单位" << "\t" << "商品价格" << "\t" << "商品库存数量" << endl;
				goods_arr[findGoodsName(name)].show();
				//更新文件
				update();

				//记录操作
				string operation = "商品销售";
				string  user_name = u.getUserName();
				History(goods_arr[findGoodsName(name)].getID(), name, user_name, num, operation);

				system("pause");
				system("cls");
			}
			else
			{
				cout << "销售数量有误" << endl;
				system("pause");
				system("cls");
			}
		}
		else
		{
			cout << "商品名称不存在" << endl;
			system("pause");
			system("cls");
		}
	}
	else
	{
		cout << "输入有误" << endl;
		system("pause");
		system("cls");
	}

}

//盘点商品
void SalesSystem::checkGoods(User& u)
{
	if (m_allGoodsNums == 0)
	{
		cout << "当前没有商品信息" << endl;
		system("pause");
		system("cls");
		return;
	}

	show();

	cout << "是否进行平库？( Y/N ):>" << endl;
	string choice;
	cin >> choice;
	if (choice == "1" || choice == "Y" || choice == "y" || choice == "yes" || choice == "YES")
	{
		cout << "请选择平库方式" << endl;
		cout << "1.出库" << endl;
		cout << "2.入库 " << endl;
		string select;
		cin >> select;
		if (select == "1" || select == "出库" || select == "1.出库")
		{
			cout << "请输入要出库的商品编号:>" << endl;
			int id = 0;
			cin >> id;
			if (findGoodsID(id) >= 0)
			{
				cout << "商品编号" << "\t" << "商品名称" << "\t" << "商品单位" << "\t" << "商品价格" << "\t" << "商品库存数量" << endl;
				goods_arr[findGoodsID(id)].show();
				int num = 0;
				cout << "请输入出库数量:>" << endl;
				cin >> num;
				if (num > 0 && num <= goods_arr[findGoodsID(id)].getNum())
				{
					goods_arr[findGoodsID(id)].subNum(num);
					cout << endl << "出库成功!" << endl;
					cout << "商品编号" << "\t" << "商品名称" << "\t" << "商品单位" << "\t" << "商品价格" << "\t" << "商品库存数量" << endl;
					goods_arr[findGoodsID(id)].show();
					//更新文件
					update();

					//记录操作
					string operation = "商品出库";
					string  user_name = u.getUserName();
					History(id, goods_arr[findGoodsID(id)].getName(), user_name,  num, operation);

					system("pause");
					system("cls");
				}
				else
				{
					cout << "出库数量有误" << endl;
					system("pause");
					system("cls");
				}
			}
			else
			{
				cout << "商品编号不存在" << endl;
				system("pause");
				system("cls");
			}
		}
		else if (select == "2" || select == "入库" || select == "2.入库")
		{
			cout << "请输入要入库的商品编号:>" << endl;
			int id = 0;
			cin >> id;
			if (findGoodsID(id) >= 0)
			{
				cout << "商品编号" << "\t" << "商品名称" << "\t" << "商品单位" << "\t" << "商品价格" << "\t" << "商品库存数量" << endl;
				goods_arr[findGoodsID(id)].show();
				int num = 0;
				cout << "请输入入库数量:>" << endl;
				cin >> num;
				if (num > 0)
				{
					goods_arr[findGoodsID(id)].addNum(num);
					cout << endl << "入库成功!" << endl;
					cout << "商品编号" << "\t" << "商品名称" << "\t" << "商品单位" << "\t" << "商品价格" << "\t" << "商品库存数量" << endl;
					goods_arr[findGoodsID(id)].show();
					//更新文件
					update();

					//记录操作
					string operation = "商品入库";
					string  user_name = u.getUserName();
					History(id, goods_arr[findGoodsID(id)].getName(), user_name, num, operation);

					system("pause");
					system("cls");
				}
				else
				{
					cout << "入库数量有误" << endl;
					system("pause");
					system("cls");
				}
			}
			else
			{
				cout << "商品编号不存在" << endl;
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
		cout << "输入有误" << endl;
		system("pause");
		system("cls");
	}
}		




//查找商品(根据商品编号)
int SalesSystem::findGoodsID(int id)
{
	//经过循环在容器内遍历查找，若找到，返回下标，找不到，返回-1
	for (int i = 0; i < this->goods_arr.size(); i++)
	{
		if (this->goods_arr[i].getID() == id)
		{
			return i;
		}
	}
	return -1;
}

//查找商品(根据商品名称)
int SalesSystem::findGoodsName(string name)
{
	//经过循环在容器内遍历查找，若找到，返回下标，找不到，返回-1
	for (int i = 0; i < this->goods_arr.size(); i++)
	{
		if (this->goods_arr[i].getName() == name)
		{
			return i;
		}
	}
	return -1;
}

//更新删除商品后的信息
void SalesSystem::update()
{
	ofstream ofs;
	ofs.open("goods.txt", ios::out);
	
	if (!ofs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}

	for (int i = 0; i < this->goods_arr.size(); i++)
	{
		ofs << this->goods_arr[i].getID() << " " << this->goods_arr[i].getName() << " " << this->goods_arr[i].getUnit() << " " << this->goods_arr[i].getPrice() << " " << this->goods_arr[i].getNum() << endl;
	}

	ofs.close();

}


//退出登录
bool SalesSystem::logOut()
{
	cout << "是否退出登录？" << endl;
	cout << "1.Y" << endl;
	cout << "2.N" << endl;
	string choice;
	cin >> choice;
	if (choice == "1" || choice == "Y" || choice == "y" || choice == "yes" || choice == "YES")
	{
		cout << "退出登录成功！" << endl;
		system("pause");
		system("cls");
		return false; // 返回false，operation.cpp中的is_continue接收，表示不再继续，退出商品管理界面
	}
	else if(choice == "2" || choice == "N" || choice == "n" || choice == "NO" || choice == "no")
	{
		system("pause");
		system("cls");
		return true; // 返回true，operation.cpp中的is_continue接收，表示继续，不退出商品管理界面

	}
	else
	{
		cout << "选择错误，请选择：Y（同意退出）/ N（不同意退出)";
		logOut();
	}
	return true;
}

//将所有商品排序
void SalesSystem::sortGoods()
{
	if (m_allGoodsNums == 0)
	{
		cout << "当前没有商品信息" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "请选择排序方式" << endl;
	cout << "1.按商品编号排序" << endl;
	cout << "2.按商品名称排序" << endl;
	cout << "3.按商品价格排序" << endl;
	cout << "4.按商品库存数量排序" << endl;
	string select;
	cin >> select;
	if (select == "1" || select == "1.按商品编号排序" || select == "按商品编号排序" || select == "商品编号")
	{
		cout<<"1.升序"<<endl;
		cout<<"2.降序"<<endl;
		cout << "请选择排序方式:>" << endl;
		string choice;
		cin >> choice;
		if (choice == "1" || choice == "升序" || choice == "1.升序")
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
			cout << "商品编号" << "\t" << "商品名称" << "\t" << "商品单位" << "\t" << "商品价格" << "\t" << "商品库存数量" << endl;
			for (int i = 0; i < this->goods_arr.size(); i++)
			{
				this->goods_arr[i].show();
			}

			//更新文件
			update();
			system("pause");
			system("cls");
		}
		else if (choice == "2" || choice == "降序" || choice == "2.降序")
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
			cout << "商品编号" << "\t" << "商品名称" << "\t" << "商品单位" << "\t" << "商品价格" << "\t" << "商品库存数量" << endl;
			for (int i = 0; i < this->goods_arr.size(); i++)
			{
				this->goods_arr[i].show();
			}

			//更新文件
			update();
			system("pause");
			system("cls");
		}
		else
		{
			cout << "输入有误" << endl;
			system("pause");
			system("cls");
		}
	}
	else if (select == "2" || select == "2.按商品名称排序" || select == "按商品名称排序" || select == "商品名称")
	{
		cout << "1.升序" << endl;
		cout << "2.降序" << endl;
		cout << "请选择排序方式:>" << endl;
		string choice;
		cin >> choice;
		if (choice == "1" || choice == "升序" || choice == "1.升序")
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
			cout << "商品编号" << "\t" << "商品名称" << "\t" << "商品单位" << "\t" << "商品价格" << "\t" << "商品库存数量" << endl;
			for (int i = 0; i < this->goods_arr.size(); i++)
			{
				this->goods_arr[i].show();
			}

			//更新文件
			update();
			system("pause");
			system("cls");
		}
		else if (choice == "2" || choice == "降序" || choice == "2.降序")
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
			cout << "商品编号" << "\t" << "商品名称" << "\t" << "商品单位" << "\t" << "商品价格" << "\t" << "商品库存数量" << endl;
			for (int i = 0; i < this->goods_arr.size(); i++)
			{
				this->goods_arr[i].show();
			}

			//更新文件
			update();
			system("pause");
			system("cls");
		}
		else
		{
			cout << "输入有误" << endl;
			system("pause");
			system("cls");
		}
	}
	else if (select == "3" || select == "3.按商品价格排序" || select == "按商品价格排序" || select == "商品价格")
	{
		cout << "1.升序" << endl;
		cout << "2.降序" << endl;
		cout << "请选择排序方式:>" << endl;
		string choice;
		cin >> choice;
		if (choice == "1" || choice == "升序" || choice == "1.升序")
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
			cout << "商品编号" << "\t" << "商品名称" << "\t" << "商品单位" << "\t" << "商品价格" << "\t" << "商品库存数量" << endl;
			for (int i = 0; i < this->goods_arr.size(); i++)
			{
				this->goods_arr[i].show();
			}

			//更新文件
			update();
			system("pause");
			system("cls");
		}
		else if (choice == "2" || choice == "降序" || choice == "2.降序")
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
			cout << "商品编号" << "\t" << "商品名称" << "\t" << "商品单位" << "\t" << "商品价格" << "\t" << "商品库存数量" << endl;
			for (int i = 0; i < this->goods_arr.size(); i++)
			{
				this->goods_arr[i].show();
			}

			//更新文件
			update();
			system("pause");
			system("cls");
		}
		else
		{
			cout << "输入有误" << endl;
			system("pause");
			system("cls");
		}
	}
	else if (select == "4" || select == "4.按商品库存数量排序" || select == "按商品库存数量排序" || select == "商品库存数量")
	{
		cout << "1.升序" << endl;
		cout << "2.降序" << endl;
		cout << "请选择排序方式:>" << endl;
		string choice;
		cin >> choice;
		if (choice == "1" || choice == "升序" || choice == "1.升序")
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
			cout << "商品编号" << "\t" << "商品名称" << "\t" << "商品单位" << "\t" << "商品价格" << "\t" << "商品库存数量" << endl;
			for (int i = 0; i < this->goods_arr.size(); i++)
			{
				this->goods_arr[i].show();
			}

			//更新文件
			update();
			system("pause");
			system("cls");
		}
		else if (choice == "2" || choice == "降序" || choice == "2.降序")
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
			cout << "商品编号" << "\t" << "商品名称" << "\t" << "商品单位" << "\t" << "商品价格" << "\t" << "商品库存数量" << endl;
			for (int i = 0; i < this->goods_arr.size(); i++)
			{
				this->goods_arr[i].show();
			}

			//更新文件
			update();
			system("pause");
			system("cls");
		}
		else
		{
			cout << "输入有误" << endl;
			system("pause");
			system("cls");
		}
	}
	else
	{
		cout << "输入有误" << endl;
		system("pause");
		system("cls");
	}
}

//获取当前时间
static string getNowTime()
{
	string time_now;

	// 获取当前时间
	time_t now = time(0);

	// 将当前时间转换为本地时间
	std::tm local_time{};
	localtime_s(&local_time, &now);

	// 显示当前时间
	//std::cout << "当前时间为: "
	//	<< local_time.tm_year + 1900 << "-"
	//	<< local_time.tm_mon + 1 << "-"
	//	<< local_time.tm_mday << " "
	//	<< local_time.tm_hour << ":"
	//	<< local_time.tm_min << ":"
	//	<< local_time.tm_sec
	//	<< std::endl;
	
	//判断小时、分钟、秒是否为个位数，如果是则在前面加0
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
	//保存到文件中
	ofstream ofs;
	ofs.open("history.txt", ios::out | ios::app);
	if (!ofs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	ofs << id << "\t" << "\t" << goods_name <<"\t" << "\t" << Username << "\t" << opeeration << "\t" << num << "\t" << time << endl;

	ofs.close();
}



void SalesSystem::showHistory()
{
	//读取文件中的数据
	ifstream ifs;
	ifs.open("history.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败，可能原因：未对商品进行任何操作。" << endl;
		system("pause");
		system("cls");
		return;
	}
	string line;

	//展示
	cout << "商品编号" << "\t"  <<  "商品名称" << "\t" << "操作方式" << "\t" << "操作员" << "\t" << "数量" << "\t" << "时间" << endl << endl;
	while (getline(ifs, line))
	{
		cout << line << endl;
		cout <<"---------------------------------------------------------------------------------" << endl;
	}
	
	ifs.close();
	system("pause");
	system("cls");
}