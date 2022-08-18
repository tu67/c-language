#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>

char* Strstr(const char* str1, const char* str2)
{
	//判断是否哦为空
	assert(str1 != NULL);
	assert(str2 != NULL);
	char* s1;
	char* s2;//指针
	char* cur = (char*)str1;
	//s1 = cur;//------------------------------------------
	//s2 = (char*)str2;//---------------------------------
	while (*cur)
	{
		s1 = cur;//记录起始地址-----------------------------------
		s2 = (char*)str2;//记录母串起始地址--------------------------------
		while (*s1 && *s2 && (*s1 == *s2))
		{
			s1++;
			s2++;
		}
		 if (*s2 == '\0')
		{
			return cur;
		}
		cur++;
	}
	return NULL;
}
int main()
{
	char* str1 = "an apple";
	char* str2 = "app";
	char* ret = Strstr(str1, str2);
	if (ret == NULL)
	{
		printf("不存在\n");
	}
	else
	{
		printf("%s\n", ret);
	}
	return 0;
}

