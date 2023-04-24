#include"mind_game.h"
#include<iostream>

using namespace std;

void setMind(char mind[ROWS][COLS], int row, int col)
{
	//初始化雷区
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			mind[i][j] = '0';
		}
	}
	//设置雷
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			cin >> mind[i][j];
		}
	}
}

//测试输出雷区
void showMind(char mind[ROWS][COLS], int row, int col)
{
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			cout << setw(3) << mind[i][j] << " ";
		}
		cout << endl;
	}
}

//初始化棋盘
void initializeBoard(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] = '-';
			//cout << setw(3) << board[i][j] << " ";
		}
		//cout << endl;
	}
}

//遍历雷区查找，如果周围没有雷，继续排查
int find(char mind[ROWS][COLS], int i, int j)
{
	int count = 0;
	if (mind[i][j] == '9')
	{
		return -1;
	}
	else
	{
		for (int x = i - 1; x <= i + 1; x++)
		{
			for (int y = j - 1; y <= j + 1; y++)
			{
				if (mind[x][y] == '9')
				{
					count++;
				}
			}
		}
		return count;
	}
	
	
}

//排查雷区
void checkMind(char mind[ROWS][COLS], char board[ROW][COL], int row, int col)
{
	if (find(mind,row,col) > 0)
	{
		board[row - 1][col - 1] = find(mind, row, col) + '0';
	}
	else if (find(mind, row, col) == -1)
	{
		board[row - 1][col - 1] = '*';
		//退出系统
		//输出棋盘
		showBoard(board, ROW, COL);
		system("pause");
		exit(0);
	}
	else if (find(mind, row, col) == 0)
	{
		board[row - 1][col - 1] =  '0';
		for (int i = row - 1; i <= row + 1; i++)
		{
			for (int j = col - 1; j <= col + 1; j++)
			{
				if (i > 0 && i < ROW && j > 0 && j < COL && board[i - 1][j - 1] == '-')
				{
					checkMind(mind, board, i, j);
				}
			}
		}
	}
}





//输出棋盘
void showBoard(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << setw(2) << board[i][j] << " ";
		}
		cout << endl;
	}
}