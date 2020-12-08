#include"game.h"

int main()
{
	int quit = 0;
	while (!quit == 1)
	{
	    Meun();
		int choise = 0;
		scanf("%d",&choise);
		switch (choise)
		{
			case 1:
				Game();
				break;
			case 2:
				printf("再见！\n");
				quit = 1;
				break;
			default :
				printf("输入有误，请重新输入！\n");
				break;
		}
	}
	system("pause");
	return 0;
}