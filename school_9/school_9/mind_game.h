
#include<iostream>
#include<cmath>
#include<ctime>
#include<string>
#include<cstdlib>
#include<iomanip>
using namespace std;

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2

//设置雷
void setMind(char mind[ROWS][COLS], int row, int col);

//测试输出雷区
void showMind(char mind[ROWS][COLS], int row, int col);

//初始化棋盘
void initializeBoard(char board[ROW][COL], int row, int col);

//排查雷区
void checkMind(char mind[ROWS][COLS], char board[ROW][COL], int row, int col);

//输出棋盘
void showBoard(char board[ROW][COL], int row, int col);

//
