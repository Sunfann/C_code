#include"game.h"

void Menu()
{   /*�˵�����*/
	printf("**************************\n");
	printf("****  1.play  2.exit  ****\n");
	printf("**************************\n");
	printf("��ѡ��");
}


void Game()
{   /*�����Ƚ�*/
	srand((unsigned long)time(NULL));
	int r = rand() % RANGE + 1;//����һ��100���ڵ������
	printf("׼�����ˣ�\n");
	while (1)
	{
		printf("���²¿�:");
		int num = 0;
		scanf("%d", &num);
		if (r > num)
		{
			printf("��С�ˣ�\n");
		}
		else if (r < num)
		{
			printf("�´��ˣ�\n");
		}
		else
		{
			printf("��ϲ�㣡\n");
			break;
		}
	}

}

void LogIn()
{
	/*��¼����*/
	char name[64];
	char passwd[64];
	
	for (int times = 0; times < 3; times++)//3�ε�¼����
	{
the:	printf("�������˺ţ�");
		scanf("%s", name);//������scanf����ʱ����ά��ָ�룻���Բ���&
		printf("���������룺");
		scanf("%s", passwd);
		if (strcmp(NAME, name) == 0 && strcmp(PASSWD, passwd) == 0)
		{   //strcmp(str1,str2)  string compare(�ַ����Ƚ�)����д
			//��str1=str2���򷵻��㣻��str1<str2���򷵻ظ�������str1>str2���򷵻�������
			printf("��¼�ɹ���%c\n",3);
			break;//�˳�ѭ��
		}
		else 
		{
			printf("��¼ʧ�ܣ�%c\n",2);
			times == 2;
		}
		if (times == 2)
		{
			printf("Please wait %dS��\r", MyTime);
			Time();
			goto the;//��ת����¼����¼ʧ��1�ξ���ʱ��
		}
	}
	
}


void Time()
{
	/*����ʱ��¼*/
	//const char *str = "hello world,hello china!"; //����
	char content[] = "9876543210";
	char lable[] = "Please wait #S!";
	
	int len = strlen(content);
	int start = 0;
	   printf("%s\r", lable);

	for (start = 0; start < len; start++)
	{
		lable[12] = content[start];//��lable����13��Ԫ�ش���
		int t = 1000 ;
		Sleep(t);
		printf("%s\r", lable);
		if (start == len-1)//�������
		{
			printf("\bPlease log in again! %c",3);// \b �˸��
		}
	}
	printf("\n");
}