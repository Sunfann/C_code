#include"game.h"

void Menu()
{   /*菜单界面*/
	printf("**************************\n");
	printf("****  1.play  2.exit  ****\n");
	printf("**************************\n");
	printf("请选择：");
}


void Game()
{   /*猜数比较*/
	srand((unsigned long)time(NULL));
	int r = rand() % RANGE + 1;//产生一个100以内的随机数
	printf("准备好了！\n");
	while (1)
	{
		printf("来猜猜看:");
		int num = 0;
		scanf("%d", &num);
		if (r > num)
		{
			printf("猜小了！\n");
		}
		else if (r < num)
		{
			printf("猜大了！\n");
		}
		else
		{
			printf("恭喜你！\n");
			break;
		}
	}

}

void LogIn()
{
	/*登录界面*/
	char name[64];
	char passwd[64];
	
	for (int times = 0; times < 3; times++)//3次登录机会
	{
the:	printf("请输入账号：");
		scanf("%s", name);//数组在scanf输入时，降维成指针；所以不带&
		printf("请输入密码：");
		scanf("%s", passwd);
		if (strcmp(NAME, name) == 0 && strcmp(PASSWD, passwd) == 0)
		{   //strcmp(str1,str2)  string compare(字符串比较)的缩写
			//若str1=str2，则返回零；若str1<str2，则返回负数；若str1>str2，则返回正数。
			printf("登录成功！%c\n",3);
			break;//退出循环
		}
		else 
		{
			printf("登录失败！%c\n",2);
			times == 2;
		}
		if (times == 2)
		{
			printf("Please wait %dS！\r", MyTime);
			Time();
			goto the;//跳转到登录，登录失败1次就延时！
		}
	}
	
}


void Time()
{
	/*倒计时登录*/
	//const char *str = "hello world,hello china!"; //待定
	char content[] = "9876543210";
	char lable[] = "Please wait #S!";
	
	int len = strlen(content);
	int start = 0;
	   printf("%s\r", lable);

	for (start = 0; start < len; start++)
	{
		lable[12] = content[start];//给lable数组13号元素传数
		int t = 1000 ;
		Sleep(t);
		printf("%s\r", lable);
		if (start == len-1)//数传完毕
		{
			printf("\bPlease log in again! %c",3);// \b 退格符
		}
	}
	printf("\n");
}