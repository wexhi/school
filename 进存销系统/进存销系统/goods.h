#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Goods
{
public:

	//构造函数
	Goods(int id, string name, string unit, double price, int num);

	//构造函数
	Goods();

	//设置商品编号
	void setID(int id);

	//设置商品名称
	void setName(string name);

	//设置商品单位
	void setUnit(string unit);

	//设置商品价格
	void setPrice(double price);

	//设置商品库存数量
	void setNum(int num);

	//保存商品信息
	void save();

	//展示商品信息
	void show();

	//获取商品编号
	int getID();

	//获取商品名称
	string getName();

	//获取商品单位
	string getUnit();

	//获取商品价格
	double getPrice();

	//获取商品库存数量
	int getNum();

	//增加商品库存数量
	void addNum(int num);

	//减少商品库存数量
	void subNum(int num);

private:
	//商品编号
	int m_ID;
	//商品名称
	string m_name;
	//商品单位
	string m_unit;
	//商品价格
	double m_price;
	//商品数量
	int m_num;

};