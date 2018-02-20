#include<stdio.h>
int a[10] = {1,1,1,1,1,1,1,1};
int b;
int *const c = &b;
int d[10][10];
int main()
{
	//int a[10] = {1,1,1,1,1,1,1,1};
	//int b;
	//int c[9];
	printf("---------------------------------------一维数组-----------------------------------------\n");	
	printf("--------------查看指针变量的右值：针对64位操作系统----------------\n");
	printf("Size of array a:%lu,size of int b:%lu\n",sizeof(a),sizeof(b));
	printf("Address of a[0]:%p\tcontent of a:%p\tcontent of &a:%p\n",&a[0],a,&a);//取一个数组名的地址所产生的是一个指向数组的指针
	printf("Address of b:%p\tcontent of c:%p\tcontent of &c:%p\n",&b,c,&c);//取一个常量指针的地址所产生的是一个指向常量指针值的指针
	printf("---------------------------------------------------------------------------------\n");
	printf("Size of array d:%lu,size of int b:%lu\n",sizeof(d),sizeof(b));
	printf("Size of array *d:%lu,size of int b:%lu\n",sizeof(*d),sizeof(b));
	printf("Size of array **d:%lu,size of int b:%lu\n",sizeof(**d),sizeof(b));
	printf("---------------------------------------------------------------------------------\n");
	printf("Address of a[0]:%p\t,address of a:%p\t,address of &a:%p\n",&a[0],a,&a);
	return 0;


}
