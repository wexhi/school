#include"mind_game.h"
#include<iostream>
using namespace std;

int main()
{
	char mind[ROWS][COLS] = { 0 };
	char board[ROW][COL] = { 0 };
	int a = 1, b = 1, round = 0;
	//������
	setMind(mind, ROW, COL);

	//��ʼ������
	initializeBoard(board, ROW, COL);
	cin >> round;
	while (round--) 
	{
		cin >> a >> b;
		//�Ų�����
		checkMind(mind, board, a, b);

		//�������
		showBoard(board, ROW, COL);

		//�������
		//showMind(mind, ROW, COL);
	}

	system("pause");
	return 0;
}