#include "game.h"

int main()
{
	
	while (1)
	{
		int choice = 0;
		int i = Meun(choice);
		switch (i)
		{
		case 1:
			Game();
			break;
		case 2:
			printf("�ټ�!\n");
			break;
		default:
			printf("��������\n");
			break;
		}
	}
	

	system("pause");
	return 0;
}