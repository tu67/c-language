#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
/*strlen����ģ��ʵ��
strlen() �����Ǵ��ַ����Ŀ�ͷλ��������������ֱ������\0��Ȼ�󷵻ؼ�ʱ����ֵ*/
/*ָ��-ָ�뷨*/
/*int my_strlen(char* str)
{
	char* p = str;
	while (*p != '\0')
	{
		p++;
	}
	return p - str;
}
int main()
{
	char arr[] = { "abcdef" };
	int len = my_strlen(arr);
	printf("�ַ�������Ϊ��%d",len);
	return 0;
}*/

/*��������*/
/*int my_strlen(char* str)
{
	int count = 0;;
	while (*str++)//�ҵ�\0�˳�
	{
		count++;
	}
	return count;
}
int main()
{
	char arr[] = { "abcdef" };
	int len = my_strlen(arr);
	printf("�ַ�������Ϊ��%d", len);
	return 0;
}*/

/*�ݹ鷨*/
int my_strlen(char* str)
{
	if (*str == '\0')
		return 0;
	else
		return 1 + my_strlen(str+1);
}
int main()
{
	char arr[] = { "abcdef" };
	int len = my_strlen(arr);
	printf("�ַ�������Ϊ��%d", len);
	return 0;
}