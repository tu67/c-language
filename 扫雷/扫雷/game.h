/*
扫雷函数声明
*/
#define CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2 
#define MINE 10
/*
写俩各数组，一个存放布置好雷的信息，一个存放排查出雷的信息
想实现9*9棋盘，数组大小因设置成11*11，多出的行和列为了防止产生越界，为了坐标对应*/

//初始化棋盘
void InitBoard(char board[ROWS][COLS],int rows,int cols,char set);
void DisplayBoard(char board[ROWS][COLS], int row, int col);//展示棋盘
void SetMine(char mine[ROWS][COLS], int row, int col);//埋雷
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col);//找雷