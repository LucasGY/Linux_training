#include<stdio.h>
#include<stddef.h>
#pragma pack()
struct S{
	char a;
	int b;
	char c;
}s1;
#pragma pack(1)
struct{
	char a;
	int b;
	char c;
}s2;
#pragma pack(2)
struct{
	char a;
	int b;
	char c;
}s3;
extern char *gy;
extern int find_char(char **strings,int value);//检查第53行的函数调用的参数类型和返回值类型是否正确，通常将这类函数原型放在.h文件中，然后include进来！！！！
int IsLittleEndian()
{
    unsigned short i=1;
    return (1 == *((char *)&i));
}
int main(int argc, char* argv[])
{
	//printf("offset of b in struct s1: %u\n,(unsigned int)(offsetof(struct s1,b))");
	printf("--------------查看指针变量的右值：针对64位操作系统----------------\n");
	int a = 120;
	int *b = &a;
	printf("Address of a: %p\nContent of b: 0x%lx\n",&a,(long unsigned int)b);
	printf("----------------------------测试内存对齐--------------------------\n");
	printf("Size of struct s1: %lu\n",sizeof(s1));
	printf("Size of struct s2: %lu\n",sizeof(s2));
	printf("Size of struct s3: %lu\n",sizeof(s3));
	printf("---------------------------测试CPU字节序--------------------------\n");
	if(IsLittleEndian())
    	{
        	printf("Little Endian.\n");
    	}
    	else
    	{	
        	printf("Big Endian.\n");
    	}
	printf("---------------------------------测试字符串-----------------------\n");
	if( 1 == argc )
   	{
      		printf("参数太少，请输入正确的操作\n");
   	}
	else
	{
		if(find_char(argv,97) == 1)//是否找到字符‘a’
		{
			printf("Find the first 'a' in %s\n ",gy);
		}
		else
			printf("Cannot find 'a'\n");  	
	}
	return 0;	
}
