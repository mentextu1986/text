#include"game.h"
//�洢���������
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
		//��ʼ���漰ѡ��
		sgn = cover();
		if (sgn == 1)
			printf("\n������Ϸ��ʼ\n");
		else if (sgn == 2)
			printf("\n˫����Ϸ��ʼ\n");
		else if (sgn == 0)
		{
			printf("\n��Ϸ����\n");
			break;
		}
		else
		{
			printf("\n�������\n");
			continue;
		}
		//���̳�ʼ��
		clean(board);
		//���̴�ӡ
		print_board(board);
		while (1)
		{
			int vol = 1;
			//p1����ֶ�����
			printf("p1���壬������100��100���䣩\n");
			vol=p_hand(board,p1sign);
			//�ж��Ƿ�����
			if (vol == 0)
			{
				printf("p1���䣬p2��ʤ\n");
				break;
			}
			//���̴�ӡ
			print_board(board);
			//�ж�p1�Ƿ�ʤ��
			jud = judge(board);
			if (jud == p1sign)
			{
				printf("p1��ʤ\n");
				break;
			}
			//p2�������
			{
			printf("p2���壬������100��100���䣩\n");
			//if˫��
			if (sgn == 2)
			{
				vol=p_hand(board,p2sign);
				if (vol == 0)
				{
					printf("p2����,p1��ʤ\n");
					break;
				}
			}
			//else����
			else
				comp(board, p2sign);
			//���̴�ӡ
			print_board(board);
			//�ж�p2�Ƿ�ʤ��
			jud = judge(board);
			if (jud == p2sign)
			{
				printf("p2��ʤ\n");
				break;
			}
			}
		}
	}
	return 0;
}