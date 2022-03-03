
#include"game.h"
int calcu_mine(char mine[rows][cols],int a,int b)
{
	return mine[a - 1][b - 1] +
		mine[a - 1][b] +
		mine[a - 1][b + 1] +
		mine[a][b - 1] +
		mine[a][b + 1] +
		mine[a + 1][b - 1] +
		mine[a + 1][b] +
		mine[a + 1][b + 1] - 8 * '0';
}

int judje(char board[rows][cols])
{
	int i = 0;
	int count = 0;
	for (i = 1; i <= row; i++)
	{
		int j = 0;
		for (j = 1; j <= col; j++)
		if (board[i][j] == '*')
			count++;
	}
	if (count == count_mine)
		return 1;
	return 0;
}

void boom_style(char mine[rows][cols], char board[rows][cols],int a,int b)
{
	int count = 0;
	count = calcu_mine(mine,a,b);
	board[a][b] = count + '0'; 
	if (board[a][b] == '0')
	{
		board[a][b] = ' ';
		if ((a - 1 >= 1) && (b - 1 >= 1) && (board[a - 1][b - 1] == '*'))
			boom_style(mine, board, a - 1, b - 1);
		if ((a - 1 >= 1) && (board[a - 1][b] == '*'))
			boom_style(mine, board, a - 1, b);
		if ((a - 1 >= 1) && (b + 1 <= 9) && (board[a - 1][b + 1] == '*'))
			boom_style(mine, board, a - 1, b + 1);
		if ((b - 1 >= 1) && (board[a][b - 1] == '*'))
			boom_style(mine, board, a, b - 1);
		if ((b + 1 <= 9) && (board[a][b + 1] == '*'))
			boom_style(mine, board, a, b + 1);
		if ((a + 1 <= 9) && (b - 1 >= 0) && (board[a + 1][b - 1] == '*'))
			boom_style(mine, board, a + 1, b - 1);
		if ((a + 1 <= 9) && (board[a + 1][b] == '*'))
			boom_style(mine, board, a + 1, b);
		if ((a + 1 <= 9) && (b + 1 <= 9) && (board[a + 1][b + 1] == '*'))
			boom_style(mine, board, a + 1, b + 1);
	}
}
