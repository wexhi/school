#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include "Users.h"
#include "goods.h"

using namespace std;

class SalesSystem:public User
{
public:
	//构造函数
	SalesSystem();

	//初始化商品
	void initGoods();

	//展示选择菜单
	void showMenu();

	//新增商品
	void createGoods();

	//获取商品种类数量
	int getGoodsNums();
	
	//删除商品
	void deleteGoods();

	//商品进货
	void addGoods();

	//商品销售
	void saleGoods();

	//盘点商品
	void checkGoods();

	//查找商品(根据商品编号)
	int findGoodsID(int id);

	//查找商品(根据商品名称)
	int findGoodsName(string name);

	//更新删除商品后的信息
	void update();

	//展示商品信息
	void showGoods();

	//展示商品信息(函数内使用）
	void show();

	//退出登录
	bool logOut();

	//将所有商品排序
	void sortGoods();

	//记录操作历史
	void recordHistory(string str);


private:
	//商品种类数量
	int m_allGoodsNums = 0;

	//将商品按种类写入
	vector<Goods> goods_arr;

};

//获取当前时间的函数
string getNowTime();

class History
{
public:
	History(int id, string opeeration, int num, string Username);


	History();

	void show();

	~History();

private:
	int m_ID;//商品编号
	string m_Username;//用户名
	string m_Operation;//操作
	int m_Num;//改变商品数量
	string m_Time;//操作时间

	vector<History>history_arr;

};


