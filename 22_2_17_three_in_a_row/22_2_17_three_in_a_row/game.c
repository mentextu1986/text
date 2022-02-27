#include"game.h"
//存储输入的坐标
int ro = 0;
int co = 0;

int main ()
{
	int sgn = 0;
	char board[row][col] = { 0 };
	srand((unsigned int)time(NULL));
	while (1)
	{

		char jud = 0;
		//开始界面及选择
		sgn = cover();
		if (sgn == 1)
			printf("\n单人游戏开始\n");
		else if (sgn == 2)
			printf("\n双人游戏开始\n");
		else if (sgn == 0)
		{
			printf("\n游戏结束\n");
			break;
		}
		else
		{
			printf("\n输入错误\n");
			continue;
		}
		//棋盘初始化
		clean(board);
		//棋盘打印
		print_board(board);
		while (1)
		{
			int vol = 1;
			//p1玩家手动下棋
			printf("p1下棋，（输入100，100认输）\n");
			vol=p_hand(board,p1sign);
			//判断是否认输
			if (vol == 0)
			{
				printf("p1认输，p2获胜\n");
				break;
			}
			//棋盘打印
			print_board(board);
			//判断p1是否胜出
			jud = judge(board);
			if (jud == p1sign)
			{
				printf("p1获胜\n");
				break;
			}
			//p2玩家下棋
			{
			printf("p2下棋，（输入100，100认输）\n");
			//if双人
			if (sgn == 2)
			{
				vol=p_hand(board,p2sign);
				if (vol == 0)
				{
					printf("p2认输,p1获胜\n");
					break;
				}
			}
			//else单人
			else
				comp(board, p2sign);
			//棋盘打印
			print_board(board);
			//判断p2是否胜出
			jud = judge(board);
			if (jud == p2sign)
			{
				printf("p2获胜\n");
				break;
			}
			}
		}
	}
	return 0;
}