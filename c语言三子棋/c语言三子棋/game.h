#define  _CRT_SECURE_NO_WARNINGS 1//�ṩ�ӿ�
#define ROW 3
#define COL 3
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void InitBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL],int row,int col);
void ComputerMove(char board[ROW][COL], int row,int col);


/*
* player is win  '*'
* computer is win '#'
* tie 'T'
* continue 'C'

*/
char isWin(char board[ROW][COL],int row,int col);