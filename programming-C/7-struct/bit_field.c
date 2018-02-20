#include<stdio.h>
struct DISK{
	unsigned a :7;
	unsigned b :6;
	unsigned c :19;
};
struct DISK *gy;
int a = 0;
int main()
{
	gy = (struct DISK *)&a;
	gy->a = 1;
	gy->b = 2;
	gy->c = 3;
	printf("a = %d\n",a);
}
