#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
/*strlen函数模拟实现
strlen() 函数是从字符串的开头位置依次向后计数，直到遇见\0，然后返回计时器的值*/
/*指针-指针法*/
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
	printf("字符串长度为：%d",len);
	return 0;
}*/

/*计数器法*/
/*int my_strlen(char* str)
{
	int count = 0;;
	while (*str++)//找到\0退出
	{
		count++;
	}
	return count;
}
int main()
{
	char arr[] = { "abcdef" };
	int len = my_strlen(arr);
	printf("字符串长度为：%d", len);
	return 0;
}*/

/*递归法*/
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
	printf("字符串长度为：%d", len);
	return 0;
}