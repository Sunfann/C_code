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
				printf("�ټ���\n");
				quit = 1;
				break;
			default :
				printf("�����������������룡\n");
				break;
		}
	}
	system("pause");
	return 0;
}