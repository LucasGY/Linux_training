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
	printf("--------------------------------------------------------------------------------\n");//ֻ�������ֳ����£�������������ָ�볣������ʾ��sizeof��&	
	printf("Size of array a:%lu,size of int b:%lu\n",sizeof(a),sizeof(b));
	printf("Address of a[0]:%p\tcontent of a:%p\tcontent of &a:%p\n",&a[0],a,&a);//ȡһ���������ĵ�ַ����������һ��ָ�������ָ��
	printf("Address of b:%p\tcontent of c:%p\tcontent of &c:%p\n",&b,c,&c);//ȡһ������ָ��ĵ�ַ����������һ��ָ����ָ��ֵ��ָ��
	*e = a;//���������������ʽ�б�ʾָ���һ��Ԫ�صĳ���ָ��
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
