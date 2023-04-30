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
	//���캯��
	SalesSystem();

	//��ʼ����Ʒ
	void initGoods();

	//չʾѡ��˵�
	void showMenu();

	//������Ʒ
	void createGoods(User& u);

	//��ȡ��Ʒ��������
	int getGoodsNums();
	
	//ɾ����Ʒ
	void deleteGoods(User& u);

	//��Ʒ����
	void addGoods(User& u);

	//��Ʒ����
	void saleGoods(User& u);

	//�̵���Ʒ
	void checkGoods(User& u);

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
	//void recordHistory(string str);

	//��ʾ������ʷ
	void showHistory();

	void History(int id, string opeeration, int num, string Username);

private:
	//��Ʒ��������
	int m_allGoodsNums = 0;

	//����Ʒ������д��
	vector<Goods> goods_arr;
};






