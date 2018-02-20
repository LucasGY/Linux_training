#include<stdio.h>

typedef struct {
	int a;
	short b[2];
} Ex2;
typedef struct EX {
	int a;
	char b[3];
	Ex2 c;
	struct EX *d;
} Ex;

Ex x = {10,"Hi",{5,{-1,25}},0};
Ex *px = &x;

void main()
{
	printf("---------------------------------------------------------\n");
	printf("Content of px: %p\nAddress of struct x: %p\n",px,&x);
	printf("Address of first member a: %p\n",&x.a);
	printf("---------------------------------------------------------\n");	
	printf("Size of the struct x: %lu\nSize of *px: %lu\n",sizeof(x),sizeof(*px));
	printf("---------------------------------------------------------\n");	
	int *pi1;
	int *pi2;
	pi1 = (int*)px;//将指向结构体的指针强制转化为指向整型的指针
	pi2 = &px->a;
	printf("pi1 = %d\npi2 = %d\n",*pi1,*pi2);
	printf("---------------------------------------------------------\n");
	printf("Size of the struct c: %lu\n",sizeof(px->c));//访问嵌套的结构
	printf("x.c.b[0] = %hd\n*px->c.b = %hd\n",x.c.b[0],*px->c.b);
	printf("---------------------------------------------------------\n");
	Ex y;
	x.d = &y;
	printf("Size of the struct y: %lu\n",sizeof(*(px->d)));
	printf("px->d->c.b[1] = %hd\taddress of px->d->c.b[1] = %p\n",px->d->c.b[1],&(px->d->c.b[1]));
	printf("---------------------------------------------------------\n");	
}
