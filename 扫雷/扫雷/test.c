/*
ɨ�ײ���
*/
#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void menu()
{
	printf("********************\n");
	printf("****1,play 0,exit***\n");
	printf("********************\n");
}
void game()
{
	char mine[ROWS][COLS];//��Ų��úõ�����Ϣ
	char show[ROWS][COLS];//����Ų�����׵���Ϣ
	//��ʼ������,1����Ų��ú��׵���Ϣ Ϊ�ַ�0������Ų���׵���ϢΪ*
	InitBoard(mine,ROWS,COLS,'0');
	InitBoard(show,ROWS,COLS,'*');

	//��ӡ����
	//DisplayBoard(mine, ROW, COL);//����Ҫ��ӡ��Χ����һȦ
	DisplayBoard(show,ROW,COL);

	//������
	SetMine(mine,ROW,COL);//�������
	//DisplayBoard(mine, ROW, COL);
	//�Ų���
	FindMine(mine, show, ROW, COL);//mine ����Ϣ����show��
}
int main()
{
	srand((unsigned int )time(NULL));//unsignedǿ��ת��
	int input = 0;
	do//����ظ�
	{
		menu();
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			//printf("ɨ��\n");
			break;
		case 0:
			printf("�˳�\n");
			break;
		default:
			printf("ѡ���������ѡ��\n");
			break;

		}
	} while (input);
	return 0;
}

