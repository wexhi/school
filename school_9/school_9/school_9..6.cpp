#include"mind_game.h"
#include<iostream>
using namespace std;

int main()
{
	char mind[ROWS][COLS] = { 0 };
	char board[ROW][COL] = { 0 };
	int a = 1, b = 1, round = 0;
	//设置雷
	setMind(mind, ROW, COL);

	//初始化棋盘
	initializeBoard(board, ROW, COL);
	cin >> round;
	while (round--) 
	{
		cin >> a >> b;
		//排查雷区
		checkMind(mind, board, a, b);

		//输出棋盘
		showBoard(board, ROW, COL);

		//测试输出
		//showMind(mind, ROW, COL);
	}

	system("pause");
	return 0;
}