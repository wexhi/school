#include"mind_game.h"

void setMind(char board[ROW][COL], int row, int col, char c)
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			board[i][j] = '0';
		}
	}
}