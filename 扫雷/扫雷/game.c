/*
ɨ�׺���ʵ��
*/
#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void InitBoard(char board[ROWS][COLS], int rows, int cols,char set)//��ʼ������
{
	int i = 0, j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;//�����ʼ����ͬ����
		}
	}
}
void DisplayBoard(char board[ROWS][COLS], int row, int col)//չʾ����
{
	int i = 0, j = 0;
	printf("������ɨ����Ϸ������\n");
	//��ӡ�к�
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");//����
	for (i = 1; i <= row; i++)
	{
		printf("%d ",i);//��ӡ�к�
		for (j = 1; j <= col; j++)
		{
			printf("%c ",board[i][j]);
		}
		printf("\n");
	}
	printf("������ɨ����Ϸ������\n");
}
void SetMine(char mine[ROWS][COLS], int row, int col)//����
{
	int count = MINE;//�����׸���
	while (count)
	{
		//�������
		int x = rand()%row+1;
		int y = rand()%col+1;//��Χ
		//�ж��Ƿ�����
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}
static int get_mine_count(char mine[ROWS][COLS],int x,int y)
{
	//����������Χ�׵ĸ���
	/*����
	*    x-1,y-1  x-1,y  x-1,y+1
	*    x ,y-1    x ,y  x  ,y+1
	     x+1,y-1  x+1,y  x+1,y+1
		 ��x,y������Χ���ҵ�
	     
	*/
	return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';//��Ϊ�׸���Ҫ��ӡ�������ϣ�����Ҫת�����ַ�
	/*
	* ����д��ѭ��
	* for(i = -1;i<=1;i++)
	*   {
	*      for(j = -1;j<=1;j++)
	*        {
	*            mine[x+1][y+1] 
	          }
	     }
	*/

}
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)//ɨ��
{
	//��������
	//����Ƿ�Ϊ��
	//1�������ף���ͳ��������Χ�м����ס��洢�Ų��׵���Ϣ��show����  2�����ף���ը�����˳���Ϸ
	int x = 0, y = 0;
	int win = 0;//ȫ���ҳ�ʱ�˳�ѭ��
	while (win<row*col-MINE)
	{
		printf("����������:");
		scanf("%d%d", &x, &y);//��Χ��1-9��
		//�ж������Ƿ�Ϸ�
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("��Ǹ������ը����!\n");
				DisplayBoard(mine,row,col);
				break;
			}
			else
			{
				//�����ף�ͳ�Ƹ�������Χ�׵ĸ���
				int count = get_mine_count(mine,x,y);
				show[x][y] = count + '0'; //Ϊ�˽��׵ĸ����洢�������У���Ҫʹ���ַ�0��ASCII��48
				//��ʾ�Ų���Ϣ
				DisplayBoard(show,row,col);
				win++;
			}
		}
		else
		{
			printf("���겻�Ϸ�����������:");
		}
	}
	if (win == row * col - MINE)//��ֹ��ը����������׳ɹ�
	{
		printf("��ϲ�㣬���׳ɹ�!");
		DisplayBoard(mine, row, col);
	}
}