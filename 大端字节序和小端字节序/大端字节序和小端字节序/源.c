#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int check_sys()
{
	//�жϵ�ǰ�ֽ��ֽ���,00 00 00 01
	int a = 1;
	char* p = (char*)&a;//ǿ��ת��
	return *p;//1С�ˣ�0���
}

int main()
{
	check_sys();

}