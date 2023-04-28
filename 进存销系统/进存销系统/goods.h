#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Goods
{
public:

	//���캯��
	Goods(int id, string name, string unit, double price, int num);

	//���캯��
	Goods();

	//������Ʒ���
	void setID(int id);

	//������Ʒ����
	void setName(string name);

	//������Ʒ��λ
	void setUnit(string unit);

	//������Ʒ�۸�
	void setPrice(double price);

	//������Ʒ�������
	void setNum(int num);

	//������Ʒ��Ϣ
	void save();

	//չʾ��Ʒ��Ϣ
	void show();

	//��ȡ��Ʒ���
	int getID();

	//��ȡ��Ʒ����
	string getName();

	//��ȡ��Ʒ��λ
	string getUnit();

	//��ȡ��Ʒ�۸�
	double getPrice();

	//��ȡ��Ʒ�������
	int getNum();

	//������Ʒ�������
	void addNum(int num);

	//������Ʒ�������
	void subNum(int num);

private:
	//��Ʒ���
	int m_ID;
	//��Ʒ����
	string m_name;
	//��Ʒ��λ
	string m_unit;
	//��Ʒ�۸�
	double m_price;
	//��Ʒ����
	int m_num;

};