#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"

void menu() // �ṩ�˵�ҳ��
{
    printf("***************************\n");
    printf("** 1.play - ��ʼ������Ϸ **\n");
    printf("** 2.play - ��ʼ˫����Ϸ **\n");
    printf("** 0.exit - �˳����� ******\n");
    printf("***************************\n");
}
void game()
{
    int ret = 0;
    char Board[ROW][COL] = { 0 };
    //��ʼ������
    InitBoard(Board, ROW, COL);
    //��ӡ����
   DisplayBoard(Board, ROW, COL);
    while (1)
    {
        //�������
		printf("���(*)����\n");
        PlayerMove(Board, ROW, COL);
        //�ж���Ӯ
        ret = IsWin(Board, ROW, COL);
        if (ret != 'C')
        {
            break;
        }
        //��ӡ����
       DisplayBoard(Board, ROW, COL);
        //��������
       printf("����(#)����:>\n");
        ComputerMove(Board, ROW, COL);
        //�ж���Ӯ
        ret = IsWin(Board, ROW, COL);
        if (ret != 'C')
        {
            break;
        }
        //��ӡ����
        DisplayBoard(Board, ROW, COL);
    }
    if (ret == '*')
    {
        printf("���Ӯ\n");
    }
    else if (ret == '#')
        printf("����Ӯ\n");
    else
        printf("ƽ��\n");
    DisplayBoard(Board, ROW, COL);
}

void game_two_player()
{
    int ret = 0;
    char Board[ROW][COL] = { 0 };
    //��ʼ������
    InitBoard(Board, ROW, COL);
    //��ӡ����
    DisplayBoard(Board, ROW, COL);
    while (1)
    {
        //���1����
		printf("���1(*)����\n");
        PlayerMove(Board, ROW, COL);
        //�ж���Ӯ
        ret = IsWin(Board, ROW, COL);
        if (ret != 'C')
        {
            break;
        }
        //��ӡ����
        DisplayBoard(Board, ROW, COL);
		printf("���2(#)����\n");
        //���2����
        Player2Move(Board, ROW, COL);
        //�ж���Ӯ
        ret = IsWin(Board, ROW, COL);
        if (ret != 'C')
        {
            break;
        }
        //��ӡ����
        DisplayBoard(Board, ROW, COL);
    }
    if (ret == '*')
    {
        printf("���1Ӯ\n");
    }
    else if (ret == '#')
        printf("���2Ӯ\n");
    else
        printf("ƽ��\n");
    DisplayBoard(Board, ROW, COL);
}
int main()
{
    srand((unsigned)time(NULL));//ʹ��ʱ�����ʹ�������ͷ���
    int input = 0;
    do
    {
        menu();
        printf("��ѡ��:>");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            //��ʼ������Ϸ
            printf("������\n");
            game();
            break;
		case 2:
			//��ʼ˫����Ϸ
			printf("������\n");
			game_two_player();
			break;
        case 0:
            //�˳�����
            printf("���س����˳�����\n");
            getchar();
            getchar();
            exit(0);
            break;
        default:
            //������
            printf("�����������������:>\n");
            break;
        }
    } while (input);
    return 0;
}