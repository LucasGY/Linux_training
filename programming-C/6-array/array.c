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
	printf("---------------------------------------һά����-----------------------------------------\n");	
	printf("--------------�鿴ָ���������ֵ�����64λ����ϵͳ----------------\n");
	printf("Size of array a:%lu,size of int b:%lu\n",sizeof(a),sizeof(b));
	printf("Address of a[0]:%p\tcontent of a:%p\tcontent of &a:%p\n",&a[0],a,&a);//ȡһ���������ĵ�ַ����������һ��ָ�������ָ��
	printf("Address of b:%p\tcontent of c:%p\tcontent of &c:%p\n",&b,c,&c);//ȡһ������ָ��ĵ�ַ����������һ��ָ����ָ��ֵ��ָ��
	printf("---------------------------------------------------------------------------------\n");
	printf("Size of array d:%lu,size of int b:%lu\n",sizeof(d),sizeof(b));
	printf("Size of array *d:%lu,size of int b:%lu\n",sizeof(*d),sizeof(b));
	printf("Size of array **d:%lu,size of int b:%lu\n",sizeof(**d),sizeof(b));
	printf("---------------------------------------------------------------------------------\n");
	printf("Address of a[0]:%p\t,address of a:%p\t,address of &a:%p\n",&a[0],a,&a);
	return 0;


}
