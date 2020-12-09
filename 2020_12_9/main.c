#include<stdio.h>
#include<windows.h>
#include<string.h>

int main()
{
	int a[] = { 1, 2, 3, 4 };
	printf("%d\n", sizeof(a));
	//��sizeof(a)�� a�����������飬��������Ϊintÿ��Ԫ��ռ�ĸ��ֽڣ�4��Ԫ�ظ�����*4��int���ͣ�=16�ֽڡ�
	printf("%d\n", sizeof(a + 0));
	//a+0������������Ԫ�ص�ַ��ռ4/8�ֽڡ�
	printf("%d\n", sizeof(*a));
	//a��ʾ������Ԫ�ص�ַ��*aΪ������Ԫ��ռ4�ֽڡ�
	printf("%d\n", sizeof(a + 1));
	//a+1:ָ��������Ԫ�ص�ַ��ָ��ָ����һԪ�صĵ�ַ��ռ4/8�ֽڡ�
	printf("%d\n", sizeof(a[1]));
	//a[1]����ʾ�ڶ�Ԫ�أ�int����ռ4���ֽڡ�
	printf("%d\n", sizeof(&a));
	//&a��������ĵ�ַҲ������Ԫ�ص�ַ��int����ռ4/8�ֽڡ�
	printf("%d\n", sizeof(*&a));
	//*&a��ʾ�������飬��sizeof(a)�ȼ�4*4=16�ֽڡ�
	printf("%d\n", sizeof(&a + 1));
	//&a+1:������������׵�ַ������������Ĵ�С����������������int������+1������ǵ�ַ����4x4=16���������ַ�Ĵ�С��Ϊ4/8�ֽڡ�
	printf("%d\n", sizeof(&a[0]));
	//&a[0]����Ԫ�ص�ַ��int����ռ4/8�ֽڡ�
	printf("%d\n", sizeof(&a[0] + 1));
	//&a[0]+1=&a[1],int����ռ4/8�ֽڡ�

	char a[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	printf("%d\n", strlen(a));
	//a:��Ԫ�ص�ַ��strlen(a)�����ֵ��strlen(char*)�Ǻ�����Ҫ������ʱ���ܼ��㡣�����������ַ���ָ�루char*��������������Ϊ��������ʱ��ʵ����������˻���ָ���ˡ�
	printf("%d\n", strlen(a + 0));
	//a + 0:����������Ԫ�ص�ַ�������ֵ��
//    printf("%d\n", strlen(*a));
	//*a:err����
//	printf("%d\n", strlen(a[1]));
	//a[1]:err����
	printf("%d\n", strlen(&a));
	//&a:�����׵�ַ�����ֵ��
	printf("%d\n", strlen(&a + 1));
	//&a + 1:�������������С�ĵ�ַ�����ֵ - 6��
	printf("%d\n", strlen(&a[0] + 1));
	//&a[0] + 1:���ֵ - 1��

	char a[] = { "abcdef" };
	printf("%d\n", sizeof(a));
//	a:�������飬�����ַ��� \0������ ����7���ַ���7�ֽڡ�
	printf("%d\n", sizeof(a + 0));
//	a + 0:��Ԫ�ص�ַ��4/8�ֽڡ�
	printf("%d\n", sizeof(*a));
//	*a:Ϊ������Ԫ�أ�1�ֽڡ�
	printf("%d\n", sizeof(a[1]));
//	a[1]:Ϊ����ڶ�Ԫ�أ�1�ֽڡ�
	printf("%d\n", sizeof(&a));
//	&a:����ĵ�ַ��4/8�ֽڡ�
	printf("%d\n", sizeof(&a + 1));
//	&a + 1:�������������С�ĵ�ַ��4/8�ֽڡ�
	printf("%d\n", sizeof(&a[0] + 1));
//	&a[0] + 1:��ʾ�ڶ�Ԫ�ص�ַ��4/8�ֽڡ�

	char a[] = { "abcdef"};
	printf("%d\n", strlen(a));
	//a:��Ԫ�ص�ַ�������ַ��� \0������������6���ַ���6��
	printf("%d\n", strlen(a + 0));
	//a + 0:��Ԫ�ص�ַ��6��
//	printf("%d\n", strlen(*a));
	//*a:err����
//	printf("%d\n", strlen(a[1]));
	//a[1]:err����
	printf("%d\n", strlen(&a));
	//&a:����ĵ�ַ��6��
	printf("%d\n", strlen(&a + 1));
	//&a + 1:�������������С�ĵ�ַ�����ֵ��
	printf("%d\n", strlen(&a[0] + 1));
	//&a[0] + 1:��ʾ�ڶ�Ԫ�ص�ַ�����ֵ - 1��

	char *p = "abcdef";
	//�ȼ���arr[]={"abcdef"};  p = &arr;
	printf("%d\n", sizeof(p));
	//�ַ���ָ��pָ���ַ����׵�ַ��СΪ4/8�ֽڡ�
	printf("%d\n", sizeof(p + 1));
	//p+1��ָ��ָ����һ�ַ�4/8�ֽڡ�
	printf("%d\n", sizeof(*p));
	//*p��ָ������ã���ʾָ��ָ������ݣ����ַ������ַ���char����1�ֽڡ�
	printf("%d\n", sizeof(p[0]));
	//p[0]���ȼ���*(p + 0),char����1�ֽڡ�
	printf("%d\n", sizeof(&p));
	//&p�������ַ����ĵ�ַ��4/8�ֽڡ�
	printf("%d\n", sizeof(&p + 1));
	//&p + 1���ȼ���&arr+1,�׵�ַ���������ַ�������ָ����һ�ַ���ַ��4/8�ֽڡ�
	printf("%d\n", sizeof(&p[0] + 1));
	//&p[0] + 1��p[0]���ַ���&p[0]��Ԫ�ص�ַ��&p[0] + 1�ȼ���p + 1��4/8�ֽڡ�


	char *p = "abcdef";
	printf("%d\n", strlen(p));
	//p:ָ���׵�ַ��6��
	printf("%d\n", strlen(p + 1));
	//p + 1:ָ����һ�ַ���5��
	printf("%d\n", strlen(*p));
	//*p�������ã�*p = arr[0],�����ַ���ָ�룬err����
	printf("%d\n", strlen(p[0]));
	//p[0] ���ȼ� *(p + 0)��Ԫ��,err����
	printf("%d\n", strlen(&p));
	//&p�������ַ����׵�ַ��
	printf("%d\n", strlen(&p + 1));
	// &p + 1:�׵�ַ���������ַ�������ָ����һ�ַ���ַ,���ֵ //sizeof������������������strlenֻ����char*���������ұ�������'\0'��β��
	printf("%d\n", strlen(&p[0] + 1));
	//&p[0] + 1:�ȼ���&arr[1],�ڶ��ַ���ַ��5��
	printf("%d\n", strlen(&p[0]));
	//&p[0]�����ַ���ַ��6��

//	��ά����
	int a[3][4] = { 0 };
	printf("%d\n", sizeof(a));
//	a���������飬3*4*4=48�ֽڡ�
	printf("%d\n", sizeof(a[0][0]));
//	a[0][0]����һ��Ԫ�أ�int����4�ֽڡ�
	printf("%d\n", sizeof(a[0]));
//	a[0]:������һ��Ԫ�أ�4*4=16�ֽڡ�
	printf("%d\n", sizeof(*a));
//	*a:a����Ԫ�ص�ַ��&a[0]����Ԫ�ص�ַ��*a��ʾ����Ԫ�أ�4*4=16�ֽڡ�
	printf("%d\n", sizeof(a[0] + 1));
//	a[0] + 1 = &a[0][1],ָ������4/8�ֽڡ�
	printf("%d\n", sizeof(*(a[0] + 1)));
//	*(a[0] + 1) = a[0][1]int���ͣ�4�ֽڡ�
	printf("%d\n", sizeof(a + 1));
//	a + 1 = &a[1],4/8�ֽڡ�
	printf("%d\n", sizeof(*(a + 1)));
//	*(a + 1) = a[2],4*4=16�ֽڡ�
	printf("%d\n", sizeof(&a[0] + 1));
//	&a[0] + 1 = &a[1],4/8�ֽڡ�
	printf("%d\n", sizeof(*(&a[0] + 1)));
//	*(&a[0] + 1) = a[1],4*4=16�ֽڡ�
	printf("%d\n", sizeof(a[3]));
//	4*4=16�ֽڡ�

	system("pause");
	return 0;
}