#include<stdio.h>
#define TRUE 1
#define FALSE 0
char *gy;//��ӡ�ҵ���a�����ַ���
int find_char(char **strings,int value)
{
	char *string; /*��ǰ���ڲ��ҵ��ַ���*/
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
