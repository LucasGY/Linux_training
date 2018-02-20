#include<stdio.h>
int a[10] = {1,1,1,1,1,1,1,1};
int *e[10];
int b;
int *const c = &b;
int d[3][10];
int main()
{
	//int a[10] = {1,1,1,1,1,1,1,1};
	//int b;
	//int c[9];
	printf("--------------------------------------------------------------------------------\n");//只有在两种场合下，数组名并不用指针常量来表示：sizeof和&	
	printf("Size of array a:%lu,size of int b:%lu\n",sizeof(a),sizeof(b));
	printf("Address of a[0]:%p\tcontent of a:%p\tcontent of &a:%p\n",&a[0],a,&a);//取一个数组名的地址所产生的是一个指向数组的指针
	printf("Address of b:%p\tcontent of c:%p\tcontent of &c:%p\n",&b,c,&c);//取一个常量指针的地址所产生的是一个指向常量指针值的指针
	*e = a;//数组名在其他表达式中表示指向第一个元素的常量指针
	printf("e[0] = %d\n",**e);
	printf("Size of *e:%lu\n",sizeof(*e));
	printf("---------------------------------------------------------------------------------\n");
	printf("Size of array d:%lu,size of int b:%lu\n",sizeof(d),sizeof(b));
	printf("Size of array *d:%lu,size of int b:%lu\n",sizeof(*d),sizeof(b));
	printf("Size of array **d:%lu,size of int b:%lu\n",sizeof(**d),sizeof(b));
	printf("Address of d[0][0]: %p\tcontent of d: %p\nAddress of d[1][0]: %p\tcontent of d+1: %p\tcontent of *(d+1): %p\n",&d[0][0],d,&d[1][0],d+1,*(d+1));
	printf("---------------------------------------------------------------------------------\n");
	printf("Address of a[0]:%p\t,address of a:%p\t,address of &a:%p\n",&a[0],a,&a);
	return 0;


}
