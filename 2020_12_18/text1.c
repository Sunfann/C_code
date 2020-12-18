#include <stdio.h>
#include <windows.h>
#pragma warning(disable:4996)
int main()
{
	int arr[] = { 73, 32, 99, 97, 110, 32, 100, 111, 32, 105, 116, 33 };
	for (int i = 0; i < 12; i++)
	{
		printf("%c",arr[i]);
	}
	printf("\n");
//	printf("%c%c%c%c%c%c%c%c%c%c%c%c", 73, 32, 99, 97, 110, 32, 100, 111, 32, 105, 116, 33);
	/*int num = 0;
	float a = 0;
	float b = 0;
	float c = 0;
	scanf("%d;%f,%f,%f", &num, &a, &b, &c);
	printf("the each subject score of  no. %d is %2.2f, %.3f, %.2f.", num, a, b, c);*/
//	int len = printf("hello world!\n");
//	printf("%d\n", len);
	system("pause");
	return 0;
}