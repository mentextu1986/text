
#include"game.h"
int main()
{
	while (1)
	{
		int se = 0;
		char mine[rows][cols];
		char board[rows][cols];
		srand((unsigned int)time(NULL));
		//Ŀ¼
		content();
		//ѡ���Ƿ�ʼ��Ϸ
		se = select();
		if (se == 1)
			printf("\n��Ϸ��ʼ\n");
		else if (se == 0)
		{
			printf("\n��Ϸ����\n");
			break;
		}
		else
		{
			printf("\n�������\n");
			continue;
		}
		//��ʼ��
		clean(mine, '0');
		clean(board, '*');
		//������
		set_mine(mine);
		//��ӡ����
		display(board);
		display(mine);
		//ɨ��
		scout_mine(mine, board);
		display(mine);

	}
	return 0;
}