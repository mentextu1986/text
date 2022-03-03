#include"game.h"
extern int ro;
extern int co;
//��ʼ���漰ѡ��
int cover()
{
	int a = 0;
	printf("***** 1 single play *******\n");
	printf("***** 2 double play *******\n");
	printf("***** 0 over **************\n");
	printf("�����룺\n");
	scanf("%d", &a);
	return a;
}
//���̳�ʼ��
void clean(char board[row][col])
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
//���̴�ӡ
void print_board(char board[row][col])
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j <col ; j++)
		{
			if (j <col- 1)
				printf(" %c |",board[i][j]);
			else
				printf(" %c \n",board[i][j]);
		}
		if (i == row - 1)
			break;
		for (j = 0; j < col; j++)
		{
			if (j < col - 1)
				printf("---|");
			else
				printf("---\n");
		}
	}
}
//p1����ֶ�����,����-1��-1����
int p_hand(char board[row][col],char a)
{
	while (1)
	{
		scanf("%d%d", &ro, &co);
		ro--;
		co--;
		if ((ro < row) && (0 <= ro) && (co < col) && (0 <= co))
		{
			if (board[ro][co] == ' ')
			{
				board[ro][co] = a;
				break;
			}
			else
				printf("�˴��������ӣ�������ѡ��\n");
		}
		else if ((ro == 99) && (co == 99))
			return 0;
		else
			printf("��Χ�������̣�������ѡ�񣬲��ɳ���%d��%d��\n", row, col);
		
	}
	return 1;

}
char judge(char board[row][col])
{
	int a = 1;
	int roo;
	int coo;
	//�ж����Ƿ��ʤ
	{
		for (roo = ro - 1; 0 <= roo; roo--)
		{
			if (board[roo][co] == board[ro][co])
				a++;
			else
				break;
		}
		for (roo = ro +1; roo < row; roo++)
		{
			if (board[roo][co] == board[ro][co])
				a++;
			else
				break;
		}
		if (a == num)
			return board[ro][co];

	}
	//�ж����Ƿ��ʤ
	{
		a = 1;
		for (coo = co - 1; 0<=coo; coo--)
		{
			if (board[ro][coo] == board[ro][co])
				a++;
			else break;
		}
		for (coo = co + 1; coo < col; coo++)
		{
			if (board[ro][coo] == board[ro][co])
				a++;
			else
				break;
		}

		if (a == num)
			return board[ro][co];
	}
	//�жϨL�Ƿ�ʤ��
	{
		a = 1;
		for (roo = ro - 1, coo = co + 1; (0<= roo) && (coo <col); roo--, coo++)
		{
			if (board[roo][coo] == board[ro][co])
				a++;
			else 
				break;
		}
		for (roo = ro + 1, coo = co - 1; (roo < row) && (0 <= coo); roo++, coo--)
		{
			if (board[roo][coo] == board[ro][co])
				a++;
			else
				break;
		}
		if (a == num)
			return board[ro][co];
	}
	//�жϨK�Ƿ�ʤ��
	{
		a = 1;
		for (roo = ro - 1, coo = co - 1; (0 <= roo) && (0 <= coo); roo--, coo--)
		{
			if (board[roo][coo] == board[ro][co])
				a++;
			else
				break;
		}
		for (roo = ro + 1, coo = co + 1; (roo <row) && (coo < col);roo++,coo++)
		{
			if (board[roo][coo] == board[ro][co])
				a++;
			else
				break;
		}
		if (a == num)
			return board[ro][co];
	}
	//�ж��Ƿ�ƽ��
	return isfull(board);
}

void comp(char board[row][col], char a)
{
	while (1)
	{
	ro = rand() % (row + 1);
	co = rand() % (row + 1);
	if ((ro <row) && (0 <= ro) && (co < col) && (0 <= co))
	{
		if (board[ro][co] == ' ')
		{
			board[ro][co] = a;
			break;
		}
		//else
		//	printf("�˴��������ӣ�������ѡ��\n");
	}
	//else
	//		printf("��Χ�������̣�������ѡ�񣬲��ɳ���%d��%d��\n", row, col);
	}

}
