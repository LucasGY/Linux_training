#include<stdio.h>
void main()
{
	short int a = -9;
	int b = 1;
	printf("b = %hd\n",b|1<<15);
	printf("a = 0x%hx,\tsize of a: %lubyte,\tAddress of a: %p\n",a,sizeof(a),&a);	
	short int i;
	i = a>>1;
	printf("i = 0x%hx\tsize of i: %lubyte,\tAddress od i: %p\n",i,sizeof(i),&i);
	if(i == (short)0x7ffb)                   //字面值要进行转换
	{
		printf("logic shift: a>>1 = 0x%hx\n",i);//判断是逻辑移位（0x7ffffffb)			
	}
	else if(i == (short)0xfffb)
	{		
		printf("arithmetic shift: a>>1 = 0x%hx\n",i);//还是算术移位（oxfffffffb）			
	}
	else
		printf("something mistake!!\n");	
	//printf("a>>1 = %\n");	
	//printf("a>>1 = %\n");	
	//printf("a>>1 = %\n");	
}
