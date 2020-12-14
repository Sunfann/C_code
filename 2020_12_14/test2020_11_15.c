#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <windows.h>

int CompInt(const void *_xp, const void *_yp)
{
	int *xp = (int*)_xp; //形参是void*类型，两端类型不同所以要进行类型转换。
	int *yp = (int*)_yp;

	if (*xp > *yp){
		return 1;//升序？降序
	}
	else if (*xp < *yp){
		return -1;
	}
	else{
		return 0;
	}
}

void Print(int *arr, int num)//进行数组输出
{
	for (int i = 0; i < num; i++){
		printf("%d ", arr[i]);//以十进制形式进行输出
	}
	printf("\n");
}

int CompStr(const void *_xp, const void *_yp)
{
	char *s1 = *(char**)_xp;
	char *s2 = *(char**)_yp;

	return strcmp(s1, s2); //字符串比较函数 1 0 -1
}

void swap(char *src, char *dst, int size)//两数交换
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
	assert(comp != NULL);//判断数组是否为空

	char *e = (char*)arr;//讲数组强转为char*，进行1字节比较

	for (int i = 0; i < num - 1; i++){//冒泡排序
		int flag = 0;//判断是否原数组已经有序
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

	
//排序问题都要进行 1 大小比较 ； 2 两数交换
//qsort回调函数主要进行两数交换，这一步骤是固定的



	/*char *arr[] = { "b1234", "a1234", "4321", "abcdef" };
	int num = sizeof(arr) / sizeof(arr[0]);*/
	int arr[] = { 24, 345, 13, 45, 5, 23, 35, 856, 234, 21, 3, 45, 34, 234, 1, 4, 6 };
	int num = sizeof(arr) / sizeof(arr[0]);

	print(arr, num);
	my_qsort(arr, num, sizeof(int), compint);//进行交换两个数
	print(arr, num);


       // int a[4] = { 1, 2, 3, 4 };
	//int *ptr1 = (int *)(&a + 1);
	//int *ptr2 = (int *)((int)a + 1);//对a进行强转，将指针类型转为整形类型，即a == 0
	//printf("%x,%x", ptr1[-1], *ptr2);


	//int a[3][4] = { 0 }; //a[3][4], a[0] a[1] a[2]
	//printf("%d\n", sizeof(a)); //48
	//printf("%d\n", sizeof(a[0][0])); //4
	//printf("%d\n", sizeof(a[0])); //16
	////int b[5], sizeof(b+1);
	//printf("%d\n", sizeof(a[0] + 1));//4， b +1
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
//	//重要，p是指针，和数组没有关系
//	printf("%d\n", strlen(&p)); //waring.随机
//	printf("%d\n", strlen(&p + 1)); //waring, 随机
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
	//printf("%d\n", strlen(&arr + 1)); //warning, 随机
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
	//printf("%d\n", strlen(arr)); // 随机6+
	//printf("%d\n", strlen(arr + 0)); //  随机6+
	////printf("%d\n", strlen(*arr)); //报错
	////printf("%d\n", strlen(arr[1])); //报错
	//printf("%d\n", strlen(&arr)); // waring，随机6+
	//printf("%d\n", strlen(&arr + 1)); //warning， 随机
	//printf("%d\n", strlen(&arr[0] + 1)); //5+随机


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