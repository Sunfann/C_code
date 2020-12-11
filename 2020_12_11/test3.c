#include <stdio.h>//1+2!+3!+4!...
#include<windows.h>
#pragma warning(disable:4996)
int Fanc(int n)
{
	int m=1;
	for (int i = 1; i <= n; i++)
	{
		m *= i;
	}
	return m;
}
int FancSum(int start,int end)
{
	int result = 0;
	for (int i = start; i <= end; i++)
	{
		result += Fanc(i);
	}
	return result;
}
#define start 1
#define end 5//调用函数必须在宏定义之前
int main()
{
	printf("%d\n", FancSum(start,end));
	system("pause");
	return 0;
}
//	int count = 1;//99
//	for (int i = 1; i <= 100; i++)
//	{
//		if (i % 10 == 9 || i / 10 == 9)//前面等式成立则不执行后面的等式
//			count++;
//	}
//		printf("count = %d\n", count);

	/*int a = 0, b = 0;
	for (a = 1, b = 1; a <= 100; a++)
	{
		if (b >= 20) break;
		if (b % 3 == 1)
		{
			b = b + 3;
			continue;
		}
		b = b - 5;
	}
	printf("%d\n", a);*/
	/*for (int i = 1; i <= 100; i++)
	{
		if (i % 3 == 0)
		{
			printf("%d\n", i);
		}
	}*/
