
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

//������
void setMind(char mind[ROWS][COLS], int row, int col);

//�����������
void showMind(char mind[ROWS][COLS], int row, int col);

//��ʼ������
void initializeBoard(char board[ROW][COL], int row, int col);

//�Ų�����
void checkMind(char mind[ROWS][COLS], char board[ROW][COL], int row, int col);

//�������
void showBoard(char board[ROW][COL], int row, int col);

//
