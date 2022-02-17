#define  _CRT_SECURE_NO_WARNINGS 1//提供实现
#include "game.h"
void menu()
{
	printf("********************\n");
	printf("****1,play 0,exit***\n");
	printf("********************\n");
}
//游戏的整个算法表现
void game()
{
	char ret = 0;//接受返回值
	char board[ROW][COL] = {0};//全部空格
	//初始化棋盘
	InitBoard(board,ROW,COL);
	//打印棋盘
	DisplayBoard(board, ROW, COL);
	//下棋
	while (1)
	{
		//玩家下棋函数
		PlayerMove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
		//判断输赢
		ret = isWin(board,ROW,COL);
		if (ret != 'C')
		{
			break;
		}
		//电脑下棋函数
		ComputerMove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
		//判断输赢
		ret = isWin(board,ROW,COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢!\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢!\n");
	}
	else
	{
		printf("平局!\n");
	}
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出\n");
			break;
		default:
			printf("选择错误,重新选择\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}