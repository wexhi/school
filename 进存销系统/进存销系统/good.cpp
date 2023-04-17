#include"goods.h"

//构造函数
Goods::Goods(int id, string name, string unit, double price, int num)
{
	this->m_ID = id;
	this->m_name = name;
	this->m_unit = unit;
	this->m_price = price;
	this->m_num = num;
}

Goods::Goods()
{
	this->m_ID = 0;
	this->m_name = "";
	this->m_unit = "";
	this->m_price = 0;
	this->m_num = 0;
}


//设置商品编号
void Goods::setID(int id)
{
	this->m_ID = id;
}

//设置商品名称
void Goods::setName(string name)
{
	this->m_name = name;
}

//设置商品单位
void Goods::setUnit(string unit)
{
	this->m_unit = unit;
}

//设置商品价格
void Goods::setPrice(double price)
{
	this->m_price = price;
}

//设置商品数量
void Goods::setNum(int num)
{
	this->m_num = num;
}

//保存商品信息
void Goods::save()
{
	ofstream ofs;
	ofs.open("goods.txt", ios::out | ios::app);
	ofs << this->m_ID << " " << this->m_name << " " << this->m_unit << " " << this->m_price << " " << this->m_num << endl;
	ofs.close();
}


//展示商品信息
void Goods::show()
{
	
	cout << this->m_ID << "\t" << "\t" << this->m_name << "\t" << "\t" << this->m_unit << "\t" << "\t" << this->m_price << "\t" << "\t" << this->m_num << endl;
}

//获取商品编号
int Goods::getID()
{
	return this->m_ID;
}

//获取商品名称
string Goods::getName()
{
	return this->m_name;
}

//获取商品单位
string Goods::getUnit()
{
	return this->m_unit;
}

//获取商品价格
double Goods::getPrice()
{
	return this->m_price;
}

//获取商品库存数量
int Goods::getNum()
{
	return this->m_num;
}

//增加商品库存数量
void Goods::addNum(int num)
{
	this->m_num += num;
}

//减少商品库存数量
void Goods::subNum(int num)
{
	this->m_num -= num;
}