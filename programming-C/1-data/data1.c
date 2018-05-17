#include <stdio.h>
//#include <math.h>
#include <limits.h>
#include <float.h>
void main()
{
	int a ;
	short int b;
	long int c;
	unsigned int d; 
	unsigned short int e;
	unsigned long int f;
	unsigned long int x = -1UL;
	unsigned int y = -1U;
	printf("-1UL = %lu\n",x);
	printf("-1U = %u\n",y);
	printf("size of int = %lu, INT_MIN = %d, INT_MAX = %d\n",sizeof(a),INT_MIN,INT_MAX);//sizeof计算数据（包括数组、变量、类型、结构体等）所占内存空间，用字节数表示。
	printf("size of short int = %lu, SHORT_INT_MIN = %d, SHORT_INT_MAX = %d\n",sizeof(b),SHRT_MIN,SHRT_MAX);
	printf("size of long int = %lu, LONG_INT_MIN = %ld, LONG_INT_MAX = %ld\n",sizeof(c),LONG_MIN,LONG_MAX);
	printf("size of unsigned int = %lu, UINT_MAX = %u\n",sizeof(d),UINT_MAX);
	printf("size of unsigned short int = %lu, SHRT_MAX = %u\n",sizeof(e),SHRT_MAX);
	printf("size of unsigned long int = %lu, ULONG_MAX = %lu\n",sizeof(f),ULONG_MAX);
	float m;
	double n;
	long double o;
	printf("size of float = %lu, FLT_MIN = %.10e, FLT_MAX = %.10e\n",sizeof(m),FLT_MIN,FLT_MAX);
	printf("size of double = %lu, DBL_MIN = %.10e, DBL_MAX = %.10e\n",sizeof(n),DBL_MIN,DBL_MAX);
	printf("size of long double = %lu, LDBL_MIN = %.10Le, LDBL_MAX = %.10Le\n",sizeof(o),LDBL_MIN,LDBL_MAX);

	char g;
	signed char h;
	unsigned char i;
	printf("size of char = %lu, CHAR_MIN = %d, CHAR_MAX = %d\n",sizeof(g),CHAR_MIN,CHAR_MAX);
	printf("size of signed char = %lu, SCHAR_MIN = %d, SCHAR_MAX = %d\n",sizeof(h),SCHAR_MIN,SCHAR_MAX);
	printf("size of unsigned char = %lu, UCHAR_MAX = %u\n",sizeof(i),UCHAR_MAX);
	void *j;
	char *k;
	int *l;
	float *p;
	double *q;
	printf("size of void* = %lu\n",sizeof(j));
	printf("size of char* = %lu\n",sizeof(k));
	printf("size of int* = %lu\n",sizeof(l));
	printf("size of float* = %lu\n",sizeof(p));
	printf("size of double* = %lu\n",sizeof(q));
	//int o = 10-012;
	//printf("0 = %d\n",o);	
}
