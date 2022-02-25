#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int check_sys()
{
	//判断当前字节字节序,00 00 00 01
	int a = 1;
	char* p = (char*)&a;//强制转化
	return *p;//1小端，0大端
}

int main()
{
	check_sys();

}