#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "game.h"

void InitBoard(char board[ROW][COL], int row, int col)//��ʼ������
{
	int i;
	int j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col)//��ӡ����
{
	int i;
	int j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if(j < col - 1)
				printf(" %c |", board[i][j]);
			else
				printf(" %c \n", board[i][j]);
		}
		if(i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				if (j < col - 1)
					printf("---|");
				else
					printf("---\n");
			}
		}
	}
}

//'*'�������(1)
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("����������(��ʽ:x y):>");
	while(1)
	{
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row  && y >= 1 && y <= col)//�ж����������Ƿ�Ϸ�
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else if (board[x - 1][y - 1] == '#')//�ж������Ƿ�ռ����һ����Ѿ��¹��ĵط�
			{
				printf("ռ����һ��ҿո�����Ƿ�������������:>");
			}
			else if (board[x - 1][y - 1] == '*')//�ж�����Ƿ�ռ���Լ��Ѿ��¹��ĵط�
			{
				printf("ռ���Լ��¹��ĵط�������������:>");
			}
		}
		else
			printf("���곬����Χ������������:>");
	}
}

//˫�˶�սʱ��'*'�������2
void Player2Move(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("����������(��ʽ:x y):>");
	while (1)
	{
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)//�ж����������Ƿ�Ϸ�
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '#';
				break;
			}
			else if (board[x - 1][y - 1] == '*')//�ж������Ƿ�ռ����һ����Ѿ��¹��ĵط�
			{
				printf("ռ����һ��ҿո�����Ƿ�������������:>");
			}
			else if (board[x - 1][y - 1] == '#')//�ж�����Ƿ�ռ���Լ��Ѿ��¹��ĵط�
			{
				printf("ռ���Լ��¹��ĵط�������������:>");
			}
		}
		else
			printf("���곬����Χ������������:>");
	}
}

//���˶�սʱ��'#'�������
//���˻�������λ�����
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x;
	int y;
	while (1)
	{
		x = rand() % row;//0~2
		y = rand() % col;//0~2
        if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

//��������1
//δ��������0
int IsFull(char board[ROW][COL], int row, int col)
{
	int i;
	int j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}
//�ж���Ӯ
//���(1)Ӯ - '*'
//����(���2)Ӯ - '#'
//ƽ�� - 'Q'
//���� - 'C'
char IsWin(char board[ROW][COL], int row, int col)
{
	//��
	int i;
	int j;
	int count;
	for (i = 0; i < row; i++)
	{
		count = 0;
		for (j = 0; j < col - 1; j++)
		{
			if (board[i][j] == board[i][j + 1] && board[i][j] != ' ')
			{
				count++;
				if (count == PIECE - 1)
					return board[i][j];
			}
		}
	}
	//��
	for (i = 0; i < row; i++)
	{
		count = 0;
		for (j = 0; j < col - 1; j++)
		{
			if (board[j][i] == board[j + 1][i] && board[j][i] != ' ')
			{
				count++;
				if (count == PIECE - 1)
					return board[j][i];
			}
		}
	}
	//�Խ���1: �����ϵ�����
	count = 0;
	for (i = 0; i < row - 1; i++)
	{
		if(board[i][i] == board[i + 1][i + 1] && board[i][i] != ' ')
		{ 
			count++;
			if(count == PIECE - 1)
				return board[i][i];
		}
	}
	//�Խ���2: �����ϵ�����
	count = 0;
	for (i = 0; i < row - 1; i++)
	{
		if (board[i][row - 1 - i] == board[i + 1][row -2 - i] && board[i][row - 1 - i] != ' ')
		{
			count++;
			if (count == PIECE - 1)
                return board[i][row - 1 - i];
		}
	}
	//�ж��Ƿ�ƽ��
	if (IsFull(board, row, col))
		return 'Q';

	return 'C';
}