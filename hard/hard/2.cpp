#include<iostream>
#include<iomanip>
#include<cmath>
#include<ctime>
#include<stdlib.h>
using namespace std;

#define ROW 8
#define COL 8

//初始化棋盘
void initializeBoard(char arr[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			arr[i][j] = '.';
			//cout << setw(2) << arr[i][j];
		}
		//cout << endl;
	}
}

//打印棋盘
void printBoard(const char arr[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << setw(2) << arr[i][j];
		}
		cout << endl;
	}
	cout << "+-+-+-+-+-+-+-+" << endl;
}

//检测周围是否有皇后
bool testQueen(const char arr[ROW][COL], int row, int col)
{
	//检测一行
	for (int i = 0; i < COL; i++)
	{
		if (arr[row][i] == '#')
		{
			return false;
		}
	}
	//检测一行
	for (int i = 0; i < ROW; i++)
	{
		if (arr[i][col] == '#')
		{
			return false;
		}
	}
	//检测周围
	if (arr[row - 1][col - 1] == '#' ||
		arr[row + 1][col - 1] == '#' ||
		arr[row - 1][col + 1] == '#' ||
		arr[row + 1][col + 1] == '#')
	{
		return false;
	}
	else
	{
		return true;
	}
	return true;
}

//设置皇后
void setQueen(char arr[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		while (1)
		{
			int j = rand() % col;
			if (testQueen(arr, i, j))
			{
				arr[i][j] = '#';
				break;
			}
		}
	}
}



int main()
{
	int n = 2;
	cin >> n;
	int times = n;
	srand((unsigned int)time(0));
	while (n--) 
	{
		char arr[ROW][COL] = { 0 };
		//初始化棋盘
		initializeBoard(arr, ROW, COL);
		//设置皇后
		setQueen(arr, ROW, COL);
		//打印棋盘
		printBoard(arr, ROW, COL);
	}
	cout << "Time:" << times << endl;;
	system("pause");
	return 0;
}