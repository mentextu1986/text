#include"game.h"

char isfull(char board[row][col])
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return '0';
		}
	}
	return '1';
}