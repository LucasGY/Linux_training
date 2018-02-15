#include<stdio.h>
void binary_to_ascii(unsigned int value)
{
	unsigned int quotient;
	quotient = value/10;
	printf("---------------------------------------\n");
	printf("value = %u\tquotient = %u\n",value,quotient);
	printf("Address of value:%p\tAddress of quotient:%p\n",&value,&quotient);
	printf("---------------------------------------\n");
	if (quotient != 0)
		binary_to_ascii(quotient);
	putchar(value%10 + '0');
}
void main()
{
	unsigned int m;
	scanf("%u",&m);
	binary_to_ascii(4267);
}
