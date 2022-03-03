
#include"game.h"
int main()
{
	while (1)
	{
		int se = 0;
		char mine[rows][cols];
		char board[rows][cols];
		srand((unsigned int)time(NULL));
		//目录
		content();
		//选择是否开始游戏
		se = select();
		if (se == 1)
			printf("\n游戏开始\n");
		else if (se == 0)
		{
			printf("\n游戏结束\n");
			break;
		}
		else
		{
			printf("\n输入错误\n");
			continue;
		}
		//初始化
		clean(mine, '0');
		clean(board, '*');
		//布置雷
		set_mine(mine);
		//打印棋盘
		display(board);
		display(mine);
		//扫雷
		scout_mine(mine, board);
		display(mine);

	}
	return 0;
}