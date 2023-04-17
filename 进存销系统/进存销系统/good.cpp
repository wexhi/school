#include"goods.h"

//���캯��
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


//������Ʒ���
void Goods::setID(int id)
{
	this->m_ID = id;
}

//������Ʒ����
void Goods::setName(string name)
{
	this->m_name = name;
}

//������Ʒ��λ
void Goods::setUnit(string unit)
{
	this->m_unit = unit;
}

//������Ʒ�۸�
void Goods::setPrice(double price)
{
	this->m_price = price;
}

//������Ʒ����
void Goods::setNum(int num)
{
	this->m_num = num;
}

//������Ʒ��Ϣ
void Goods::save()
{
	ofstream ofs;
	ofs.open("goods.txt", ios::out | ios::app);
	ofs << this->m_ID << " " << this->m_name << " " << this->m_unit << " " << this->m_price << " " << this->m_num << endl;
	ofs.close();
}


//չʾ��Ʒ��Ϣ
void Goods::show()
{
	
	cout << this->m_ID << "\t" << "\t" << this->m_name << "\t" << "\t" << this->m_unit << "\t" << "\t" << this->m_price << "\t" << "\t" << this->m_num << endl;
}

//��ȡ��Ʒ���
int Goods::getID()
{
	return this->m_ID;
}

//��ȡ��Ʒ����
string Goods::getName()
{
	return this->m_name;
}

//��ȡ��Ʒ��λ
string Goods::getUnit()
{
	return this->m_unit;
}

//��ȡ��Ʒ�۸�
double Goods::getPrice()
{
	return this->m_price;
}

//��ȡ��Ʒ�������
int Goods::getNum()
{
	return this->m_num;
}

//������Ʒ�������
void Goods::addNum(int num)
{
	this->m_num += num;
}

//������Ʒ�������
void Goods::subNum(int num)
{
	this->m_num -= num;
}