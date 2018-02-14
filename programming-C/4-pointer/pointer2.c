#include<stdio.h>
#define TRUE 1
#define FALSE 0
char *gy;//打印找到‘a’的字符串
int find_char(char **strings,int value)
{
	char *string; /*当前正在查找的字符串*/
	while((string = *strings++) != NULL)
	{
		gy = string;
		for(;*string != '\0';string++)
		{
			if(*string == value)
			{
				return TRUE;
			}
		}
	}
	return FALSE;
}
