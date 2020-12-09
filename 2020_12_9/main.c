#include<stdio.h>
#include<windows.h>
#include<string.h>

int main()
{
	int a[] = { 1, 2, 3, 4 };
	printf("%d\n", sizeof(a));
	//在sizeof(a)中 a代表整个数组，数组类型为int每个元素占四个字节，4（元素个数）*4（int类型）=16字节。
	printf("%d\n", sizeof(a + 0));
	//a+0：代表数组首元素地址，占4/8字节。
	printf("%d\n", sizeof(*a));
	//a表示数组首元素地址，*a为数组首元素占4字节。
	printf("%d\n", sizeof(a + 1));
	//a+1:指向数组首元素地址的指针指向下一元素的地址，占4/8字节。
	printf("%d\n", sizeof(a[1]));
	//a[1]：表示第二元素，int类型占4个字节。
	printf("%d\n", sizeof(&a));
	//&a整个数组的地址也就是首元素地址，int类型占4/8字节。
	printf("%d\n", sizeof(*&a));
	//*&a表示整个数组，与sizeof(a)等价4*4=16字节。
	printf("%d\n", sizeof(&a + 1));
	//&a+1:代表的是数组首地址加上整个数组的大小，这里数组类型是int，所以+1代表的是地址加上4x4=16；但是其地址的大小仍为4/8字节。
	printf("%d\n", sizeof(&a[0]));
	//&a[0]：首元素地址，int类型占4/8字节。
	printf("%d\n", sizeof(&a[0] + 1));
	//&a[0]+1=&a[1],int类型占4/8字节。

	char a[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	printf("%d\n", strlen(a));
	//a:首元素地址，strlen(a)是随机值。strlen(char*)是函数，要在运行时才能计算。参数必须是字符型指针（char*）。当数组名作为参数传入时，实际上数组就退化成指针了。
	printf("%d\n", strlen(a + 0));
	//a + 0:代表数组首元素地址，是随机值。
//    printf("%d\n", strlen(*a));
	//*a:err报错。
//	printf("%d\n", strlen(a[1]));
	//a[1]:err报错。
	printf("%d\n", strlen(&a));
	//&a:数组首地址，随机值。
	printf("%d\n", strlen(&a + 1));
	//&a + 1:跳过整个数组大小的地址，随机值 - 6。
	printf("%d\n", strlen(&a[0] + 1));
	//&a[0] + 1:随机值 - 1。

	char a[] = { "abcdef" };
	printf("%d\n", sizeof(a));
//	a:整个数组，从首字符到 \0（含） 共有7个字符，7字节。
	printf("%d\n", sizeof(a + 0));
//	a + 0:首元素地址，4/8字节。
	printf("%d\n", sizeof(*a));
//	*a:为数组首元素，1字节。
	printf("%d\n", sizeof(a[1]));
//	a[1]:为数组第二元素，1字节。
	printf("%d\n", sizeof(&a));
//	&a:数组的地址，4/8字节。
	printf("%d\n", sizeof(&a + 1));
//	&a + 1:跳过整个数组大小的地址，4/8字节。
	printf("%d\n", sizeof(&a[0] + 1));
//	&a[0] + 1:表示第二元素地址，4/8字节。

	char a[] = { "abcdef"};
	printf("%d\n", strlen(a));
	//a:首元素地址，从首字符到 \0（不含）共有6个字符，6。
	printf("%d\n", strlen(a + 0));
	//a + 0:首元素地址，6。
//	printf("%d\n", strlen(*a));
	//*a:err报错。
//	printf("%d\n", strlen(a[1]));
	//a[1]:err报错。
	printf("%d\n", strlen(&a));
	//&a:数组的地址，6。
	printf("%d\n", strlen(&a + 1));
	//&a + 1:跳过整个数组大小的地址，随机值。
	printf("%d\n", strlen(&a[0] + 1));
	//&a[0] + 1:表示第二元素地址，随机值 - 1。

	char *p = "abcdef";
	//等价于arr[]={"abcdef"};  p = &arr;
	printf("%d\n", sizeof(p));
	//字符串指针p指向字符串首地址大小为4/8字节。
	printf("%d\n", sizeof(p + 1));
	//p+1：指针指向下一字符4/8字节。
	printf("%d\n", sizeof(*p));
	//*p：指针解引用，表示指针指向的内容，即字符串首字符，char类型1字节。
	printf("%d\n", sizeof(p[0]));
	//p[0]：等价于*(p + 0),char类型1字节。
	printf("%d\n", sizeof(&p));
	//&p：整个字符串的地址，4/8字节。
	printf("%d\n", sizeof(&p + 1));
	//&p + 1：等价于&arr+1,首地址加上整个字符串长度指向下一字符地址，4/8字节。
	printf("%d\n", sizeof(&p[0] + 1));
	//&p[0] + 1：p[0]首字符，&p[0]首元素地址，&p[0] + 1等价于p + 1，4/8字节。


	char *p = "abcdef";
	printf("%d\n", strlen(p));
	//p:指向首地址，6。
	printf("%d\n", strlen(p + 1));
	//p + 1:指向下一字符，5。
	printf("%d\n", strlen(*p));
	//*p：解引用，*p = arr[0],不是字符串指针，err报错。
	printf("%d\n", strlen(p[0]));
	//p[0] ：等价 *(p + 0)首元素,err报错。
	printf("%d\n", strlen(&p));
	//&p：整个字符串首地址，
	printf("%d\n", strlen(&p + 1));
	// &p + 1:首地址加上整个字符串长度指向下一字符地址,随机值 //sizeof可以用类型做参数，strlen只能用char*做参数，且必须是以'\0'结尾的
	printf("%d\n", strlen(&p[0] + 1));
	//&p[0] + 1:等价于&arr[1],第二字符地址，5。
	printf("%d\n", strlen(&p[0]));
	//&p[0]：首字符地址，6。

//	二维数组
	int a[3][4] = { 0 };
	printf("%d\n", sizeof(a));
//	a：整个数组，3*4*4=48字节。
	printf("%d\n", sizeof(a[0][0]));
//	a[0][0]：第一个元素，int类型4字节。
	printf("%d\n", sizeof(a[0]));
//	a[0]:整个第一行元素，4*4=16字节。
	printf("%d\n", sizeof(*a));
//	*a:a是首元素地址即&a[0]首行元素地址，*a表示首行元素，4*4=16字节。
	printf("%d\n", sizeof(a[0] + 1));
//	a[0] + 1 = &a[0][1],指针类型4/8字节。
	printf("%d\n", sizeof(*(a[0] + 1)));
//	*(a[0] + 1) = a[0][1]int类型，4字节。
	printf("%d\n", sizeof(a + 1));
//	a + 1 = &a[1],4/8字节。
	printf("%d\n", sizeof(*(a + 1)));
//	*(a + 1) = a[2],4*4=16字节。
	printf("%d\n", sizeof(&a[0] + 1));
//	&a[0] + 1 = &a[1],4/8字节。
	printf("%d\n", sizeof(*(&a[0] + 1)));
//	*(&a[0] + 1) = a[1],4*4=16字节。
	printf("%d\n", sizeof(a[3]));
//	4*4=16字节。

	system("pause");
	return 0;
}