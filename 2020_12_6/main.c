/**************************猜数小游戏*********************************/
/**************** 首先开始游戏之前先登录，共有3次机会；***************
***************** 3次登录错误后，必须等10S后才能登录；****************
***************** 以后1次登录失败就会有10S延时。**********************/
#include"game.h"

int main()
{
	LogIn();
	while (1)
	{
		Menu();
		int a = 0;
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			Game();
			printf("再来一次！！！！\n");
			break;
		case 2:
			printf("886\n");
			goto exit;//跳出while（a）循环：a=0 ; break;
		default:
			printf("输入有误！重新输入\n");
			break;
		}
	}

exit:

	system("pause");
	return 0;
}