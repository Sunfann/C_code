#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <windows.h>

int CompInt(const void *_xp, const void *_yp)
{
	int *xp = (int*)_xp; //�β���void*���ͣ��������Ͳ�ͬ����Ҫ��������ת����
	int *yp = (int*)_yp;

	if (*xp > *yp){
		return 1;//���򣿽���
	}
	else if (*xp < *yp){
		return -1;
	}
	else{
		return 0;
	}
}

void Print(int *arr, int num)//�����������
{
	for (int i = 0; i < num; i++){
		printf("%d ", arr[i]);//��ʮ������ʽ�������
	}
	printf("\n");
}

int CompStr(const void *_xp, const void *_yp)
{
	char *s1 = *(char**)_xp;
	char *s2 = *(char**)_yp;

	return strcmp(s1, s2); //�ַ����ȽϺ��� 1 0 -1
}

void swap(char *src, char *dst, int size)//��������
{
	while (size){
		char temp = *src;
		*src = *dst;
		*dst = temp;
		size--;
		src++, dst++;
	}
}

void my_qsort(void *arr, int num, int size, int(*comp)(const void*, const void*))
{
	assert(arr != NULL);
	assert(comp != NULL);//�ж������Ƿ�Ϊ��

	char *e = (char*)arr;//������ǿתΪchar*������1�ֽڱȽ�

	for (int i = 0; i < num - 1; i++){//ð������
		int flag = 0;//�ж��Ƿ�ԭ�����Ѿ�����
		for (int j = 0; j < num - 1 - i; j++){
			if (comp(e + j*size, e + (j+1)*size) > 0){
				flag = 1;
				swap(e + j*size, e + (j + 1)*size, size);
			}
		}

		if (flag == 0){
			break;
		}
	}
}

int main()
{

	
//�������ⶼҪ���� 1 ��С�Ƚ� �� 2 ��������
//qsort�ص�������Ҫ����������������һ�����ǹ̶���



	/*char *arr[] = { "b1234", "a1234", "4321", "abcdef" };
	int num = sizeof(arr) / sizeof(arr[0]);*/
	int arr[] = { 24, 345, 13, 45, 5, 23, 35, 856, 234, 21, 3, 45, 34, 234, 1, 4, 6 };
	int num = sizeof(arr) / sizeof(arr[0]);

	print(arr, num);
	my_qsort(arr, num, sizeof(int), compint);//���н���������
	print(arr, num);


       // int a[4] = { 1, 2, 3, 4 };
	//int *ptr1 = (int *)(&a + 1);
	//int *ptr2 = (int *)((int)a + 1);//��a����ǿת����ָ������תΪ�������ͣ���a == 0
	//printf("%x,%x", ptr1[-1], *ptr2);


	//int a[3][4] = { 0 }; //a[3][4], a[0] a[1] a[2]
	//printf("%d\n", sizeof(a)); //48
	//printf("%d\n", sizeof(a[0][0])); //4
	//printf("%d\n", sizeof(a[0])); //16
	////int b[5], sizeof(b+1);
	//printf("%d\n", sizeof(a[0] + 1));//4�� b +1
	//printf("%d\n", sizeof(*(a[0] + 1)));//4
	//printf("%d\n", sizeof(a + 1)); //4
	//printf("%d\n", sizeof(*(a + 1))); //16

	//printf("%d\n", sizeof(&a[0] + 1)); //4, &a[1] , &b + 1
	//printf("%d\n", sizeof(*(&a[0] + 1))); //16
	//printf("%d\n", sizeof(*a)); //16
	//printf("%d\n", sizeof(a[3])); //16




	//size_t strlen ( const char * str );
//	char *p = "abcdef";
//	printf("%d\n", strlen(p)); //6
//	printf("%d\n", strlen(p + 1)); //5
//
////	printf("%d\n", strlen(*p)); //err
////	printf("%d\n", strlen(p[0])); //err
//
//	//��Ҫ��p��ָ�룬������û�й�ϵ
//	printf("%d\n", strlen(&p)); //waring.���
//	printf("%d\n", strlen(&p + 1)); //waring, ���
//
//
//	printf("%d\n", strlen(&p[0] + 1)); // 5,


	//printf("%d\n", sizeof(p)); //4, 
	//printf("%d\n", sizeof(p + 1)); //4, 
	//printf("%d\n", sizeof(*p)); //1, 
	//printf("%d\n", sizeof(p[0])); //1,
	//printf("%d\n", sizeof(&p)); //4, 
	//printf("%d\n", sizeof(&p + 1)); //4, 
	//printf("%d\n", sizeof(&p[0] + 1)); //4


	//size_t strlen ( const char * str );
	//char arr[] = "abcdef"; //7
	//printf("%d\n", strlen(arr)); //6
	//printf("%d\n", strlen(arr + 0)); //6,
	////printf("%d\n", strlen(*arr)); //err
	////printf("%d\n", strlen(arr[1])); //err
	//printf("%d\n", strlen(&arr)); //warning, 6
	//printf("%d\n", strlen(&arr + 1)); //warning, ���
	//printf("%d\n", strlen(&arr[0] + 1)); //5


	//printf("%d\n", sizeof(arr)); //7
	//printf("%d\n", sizeof(arr + 0));//4
	//printf("%d\n", sizeof(*arr)); //1
	//printf("%d\n", sizeof(arr[1])); //1
	//printf("%d\n", sizeof(&arr)); //4
	//printf("%d\n", sizeof(&arr + 1)); //4
	//printf("%d\n", sizeof(&arr[0] + 1)); //4



	//size_t strlen ( const char * str );
	//char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	//printf("%d\n", strlen(arr)); // ���6+
	//printf("%d\n", strlen(arr + 0)); //  ���6+
	////printf("%d\n", strlen(*arr)); //����
	////printf("%d\n", strlen(arr[1])); //����
	//printf("%d\n", strlen(&arr)); // waring�����6+
	//printf("%d\n", strlen(&arr + 1)); //warning�� ���
	//printf("%d\n", strlen(&arr[0] + 1)); //5+���


	//printf("%d\n", sizeof(arr)); //6
	//printf("%d\n", sizeof(arr + 0)); //4
	//printf("%d\n", sizeof(*arr)); //1
	//printf("%d\n", sizeof(arr[1])); //1
	//printf("%d\n", sizeof(&arr)); //4
	//printf("%d\n", sizeof(&arr + 1)); //4
	//printf("%d\n", sizeof(&arr[0] + 1)); //4

	//int a[] = { 1, 2, 3, 4 };
	//printf("%d\n", sizeof(a)); //16
	//printf("%d\n", sizeof(a + 0)); //4
	//printf("%d\n", sizeof(*a)); //4
	//printf("%d\n", sizeof(a + 1)); //4
	//printf("%d\n", sizeof(a[1])); //4
	//printf("%d\n", sizeof(&a)); //4
	//printf("%d\n", sizeof(*&a)); //16
	//printf("%d\n", sizeof(&a + 1)); //4
	//printf("%d\n", sizeof(&a[0])); //4
	//printf("%d\n", sizeof(&a[0] + 1)); //4 


	system("pause");
	return 0;
}