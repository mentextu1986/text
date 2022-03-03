
#include"game.h"
void content()
{
	printf("***********************\n");
	printf("******** 1 play *******\n");
	printf("******** 0 over *******\n");
}

int select()
{
	int a = 0;
	printf("请输入：\n");
	scanf("%d", &a);
	return a;
}

void clean(char board[rows][cols],char a)
{
	int i = 0;
	for (i = 0; i < rows; i++)
	{
		int j = 0;
		for (j = 0; j < cols; j++)
		{
			board[i][j] = a;
		}
	}
}

void display(char board[rows][cols])
{
	int i = 0;
	for (i = 0; i <= row; i++)
		printf("%d  ", i);
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		int j = 0;
		printf("%d  ", i);
		for (j = 1; j <=col; j++)
		{
				printf("%c  ", board[i][j]);
		}
		printf("\n");
	}
}

void set_mine(char board[rows][cols])
{
	int count = 0;
	while (count <count_mine)
	{
		int a = rand() % (row)+ 1;
		int b = rand() % (col) + 1;
		if (board[a][b] == '0')
		{
			board[a][b] = '1';
			count++;
		}
	}
}

void scout_mine(char mine[rows][cols], char board[rows][cols])
{
	int a = 0;
	int b = 0;
	int count = 0;
	while (1)
	{
		printf("请输入排雷坐标\n");
		scanf("%d %d", &a, &b);
		printf("\n");
		if (a<1 ||a>col||b<1||b>col)
		{
			printf("范围超出棋盘，请重新选择，不可超过%d行%d列\n", row, col);
			continue;
		}
		if (board[a][b] != '*')
		{
			printf("此处已探查过，请重新选择\n");
			continue;
		}	
		if (mine[a][b] == '1')
		{
			printf("你被炸死了\n");
			display(mine);
			break;
		}
		boom_style(mine, board,a,b);
		/*count = calcu_mine(mine,a,b);
		board[a][b] = count + '0';*/
		display(board);
		if (judje(board))
		{
			printf("恭喜你排雷成功\n");
			break;
		}

	}
		
}