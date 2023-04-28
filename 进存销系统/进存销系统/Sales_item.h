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

class SalesSystem
{
public:
	//构造函数
	SalesSystem();

	//初始化商品
	void initGoods();

	//展示选择菜单
	void showMenu();

	//新增商品
	void createGoods(User& u);

	//获取商品种类数量
	int getGoodsNums();
	
	//删除商品
	void deleteGoods(User& u);

	//商品进货
	void addGoods(User& u);

	//商品销售
	void saleGoods(User& u);

	//盘点商品
	void checkGoods(User& u);

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
	//void recordHistory(string str);

	//显示操作历史
	void showHistory();

	void History(int id, string opeeration, int num, string Username);

private:
	//商品种类数量
	int m_allGoodsNums = 0;

	//将商品按种类写入
	vector<Goods> goods_arr;
};






