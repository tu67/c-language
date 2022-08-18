#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>

char* Strstr(const char* str1, const char* str2)
{
	//�ж��Ƿ�ŶΪ��
	assert(str1 != NULL);
	assert(str2 != NULL);
	char* s1;
	char* s2;//ָ��
	char* cur = (char*)str1;
	//s1 = cur;//------------------------------------------
	//s2 = (char*)str2;//---------------------------------
	while (*cur)
	{
		s1 = cur;//��¼��ʼ��ַ-----------------------------------
		s2 = (char*)str2;//��¼ĸ����ʼ��ַ--------------------------------
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
		printf("������\n");
	}
	else
	{
		printf("%s\n", ret);
	}
	return 0;
}

