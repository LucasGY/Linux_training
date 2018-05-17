#include<stdio.h>
#include<stdlib.h>
//#include"auxiliary.c"
int bss_var;  //�ļ�������extern�������ԣ���̬������bss��
int data_var0 = 1;//�ļ�������extern�������ԣ���̬������data��
extern int a;//�ļ�������extern�������ԣ���̬������data��
extern int b;//�ļ�������extern�������ԣ���̬������data��
static int c;//�ļ�������internal�������ԣ���̬������bss��
void main()//�ļ�������extern�������ԣ�text��
{
	printf("a = %d\n",a);
	printf("b = %d\n",b);
	printf("_____________________________________\n");
	int stack_var0 = 2;//�����������none�������ԣ�auto������stack��
	printf("Stack location:\n");
	printf("\tInitial end of stack:%p\n",&stack_var0);
	int stack_var1 = 3;
	printf("\tNew end of stack:%p\n",&stack_var1);
	printf("_____________________________________\n");
	printf("Heap location:\n");
	char *p = (char *)malloc(10);
	printf("\tAddress of head_var:%p\n",p);
	printf("_____________________________________\n");
	printf("BSS location:\n");
	printf("\tAddress of static c:%p, c = %d\n",&c,c);
	printf("\tAddress of bss_var:%p, bss_var = %d\n",&bss_var,bss_var);
	printf("_____________________________________\n");
	printf("Data location:\n");
	static int data_var2;//�ļ�������none�������ԣ���̬������bss��
	static int data_var1 = 4;//�ļ�������none�������ԣ���̬������data��
	printf("\tNew end of data_var(Data Segment):%p\n",&data_var1);
	printf("\tNew end of data_var(Data Segment):%p,a = %d\n",&a,a);
	printf("\tAddress of data_var(Data Segment):%p\n",&data_var0);
	printf("_____________________________________\n");
	printf("Text location:\n");
	printf("\tAddress of main(Code Segment):%p\n",main);
	printf("_____________________________________\n");
}
/*
**shell:
**gcc data2.c auxiliary.c -o gy
*/
