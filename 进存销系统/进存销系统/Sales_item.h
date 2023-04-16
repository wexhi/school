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
	//���캯��
	SalesSystem();

	//��ʼ����Ʒ
	void initGoods();

	//չʾѡ��˵�
	void showMenu();

	//������Ʒ
	void createGoods();

	//��ȡ��Ʒ��������
	int getGoodsNums();
	
	//ɾ����Ʒ
	void deleteGoods();

	//��Ʒ����
	void addGoods();

	//��Ʒ����
	void saleGoods();

	//�̵���Ʒ
	void checkGoods();

	//������Ʒ(������Ʒ���)
	int findGoodsID(int id);

	//������Ʒ(������Ʒ����)
	int findGoodsName(string name);

	//����ɾ����Ʒ�����Ϣ
	void update();

	//չʾ��Ʒ��Ϣ
	void showGoods();

	//չʾ��Ʒ��Ϣ(������ʹ�ã�
	void show();

	//�˳���¼
	bool logOut();

	//��������Ʒ����
	void sortGoods();

	//��¼������ʷ
	void recordHistory(string str);


private:
	//��Ʒ��������
	int m_allGoodsNums = 0;

	//����Ʒ������д��
	vector<Goods> goods_arr;

};

//��ȡ��ǰʱ��ĺ���
string getNowTime();

class History
{
public:
	History(int id, string opeeration, int num, string Username);


	History();

	void show();

	~History();

private:
	int m_ID;//��Ʒ���
	string m_Username;//�û���
	string m_Operation;//����
	int m_Num;//�ı���Ʒ����
	string m_Time;//����ʱ��

	vector<History>history_arr;

};


