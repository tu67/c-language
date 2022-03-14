/*
扫雷测试
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
	char mine[ROWS][COLS];//存放布置好的雷信息
	char show[ROWS][COLS];//存放排查出的雷的信息
	//初始化棋盘,1，存放布置好雷的信息 为字符0，存放排查出雷的信息为*
	InitBoard(mine,ROWS,COLS,'0');
	InitBoard(show,ROWS,COLS,'*');

	//打印棋盘
	//DisplayBoard(mine, ROW, COL);//不需要打印外围的那一圈
	DisplayBoard(show,ROW,COL);

	//布置雷
	SetMine(mine,ROW,COL);//随机布置
	//DisplayBoard(mine, ROW, COL);
	//排查雷
	FindMine(mine, show, ROW, COL);//mine 中信息放入show中
}
int main()
{
	srand((unsigned int )time(NULL));//unsigned强制转换
	int input = 0;
	do//多次重复
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			//printf("扫雷\n");
			break;
		case 0:
			printf("退出\n");
			break;
		default:
			printf("选择错误，重新选择\n");
			break;

		}
	} while (input);
	return 0;
}

