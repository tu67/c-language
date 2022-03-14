/*
扫雷函数实现
*/
#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void InitBoard(char board[ROWS][COLS], int rows, int cols,char set)//初始化棋盘
{
	int i = 0, j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;//方便初始化不同内容
		}
	}
}
void DisplayBoard(char board[ROWS][COLS], int row, int col)//展示棋盘
{
	int i = 0, j = 0;
	printf("———扫雷游戏———\n");
	//打印列号
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");//换行
	for (i = 1; i <= row; i++)
	{
		printf("%d ",i);//打印行号
		for (j = 1; j <= col; j++)
		{
			printf("%c ",board[i][j]);
		}
		printf("\n");
	}
	printf("———扫雷游戏———\n");
}
void SetMine(char mine[ROWS][COLS], int row, int col)//埋雷
{
	int count = MINE;//布置雷个数
	while (count)
	{
		//随机坐标
		int x = rand()%row+1;
		int y = rand()%col+1;//范围
		//判断是否有雷
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}
static int get_mine_count(char mine[ROWS][COLS],int x,int y)
{
	//查找坐标周围雷的个数
	/*例如
	*    x-1,y-1  x-1,y  x-1,y+1
	*    x ,y-1    x ,y  x  ,y+1
	     x+1,y-1  x+1,y  x+1,y+1
		 将x,y坐标周围雷找到
	     
	*/
	return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';//因为雷个数要打印在棋盘上，所以要转换成字符
	/*
	* 或者写成循环
	* for(i = -1;i<=1;i++)
	*   {
	*      for(j = -1;j<=1;j++)
	*        {
	*            mine[x+1][y+1] 
	          }
	     }
	*/

}
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)//扫雷
{
	//输入坐标
	//检查是否为雷
	//1，不是雷：“统计坐标周围有几个雷”存储排查雷的信息到show数组  2，是雷，被炸死，退出游戏
	int x = 0, y = 0;
	int win = 0;//全部找出时退出循环
	while (win<row*col-MINE)
	{
		printf("请输入坐标:");
		scanf("%d%d", &x, &y);//范围（1-9）
		//判断坐标是否合法
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("抱歉，您被炸死了!\n");
				DisplayBoard(mine,row,col);
				break;
			}
			else
			{
				//不是雷，统计该坐标周围雷的个数
				int count = get_mine_count(mine,x,y);
				show[x][y] = count + '0'; //为了将雷的个数存储到棋盘中，需要使用字符0的ASCII码48
				//显示排查信息
				DisplayBoard(show,row,col);
				win++;
			}
		}
		else
		{
			printf("坐标不合法，重新输入:");
		}
	}
	if (win == row * col - MINE)//防止被炸死后输出排雷成功
	{
		printf("恭喜你，排雷成功!");
		DisplayBoard(mine, row, col);
	}
}