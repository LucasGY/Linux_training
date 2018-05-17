#include<stdio.h>
#include<stdlib.h>
//#include"auxiliary.c"
int bss_var;  //文件作用域，extern链接属性，静态变量，bss段
int data_var0 = 1;//文件作用域，extern链接属性，静态变量，data段
extern int a;//文件作用域，extern链接属性，静态变量，data段
extern int b;//文件作用域，extern链接属性，静态变量，data段
static int c;//文件作用域，internal链接属性，静态变量，bss段
void main()//文件作用域，extern链接属性，text段
{
	printf("a = %d\n",a);
	printf("b = %d\n",b);
	printf("_____________________________________\n");
	int stack_var0 = 2;//代码段作用域，none链接属性，auto变量，stack段
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
	static int data_var2;//文件作用域，none链接属性，静态变量，bss段
	static int data_var1 = 4;//文件作用域，none链接属性，静态变量，data段
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
