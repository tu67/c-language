/*
ɨ�׺�������
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
д�������飬һ����Ų��ú��׵���Ϣ��һ������Ų���׵���Ϣ
��ʵ��9*9���̣������С�����ó�11*11��������к���Ϊ�˷�ֹ����Խ�磬Ϊ�������Ӧ*/

//��ʼ������
void InitBoard(char board[ROWS][COLS],int rows,int cols,char set);
void DisplayBoard(char board[ROWS][COLS], int row, int col);//չʾ����
void SetMine(char mine[ROWS][COLS], int row, int col);//����
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col);//����