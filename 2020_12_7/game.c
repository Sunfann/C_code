#include "game.h"

int Meun(int choice)
{
	printf("*************************************\n");
	printf("****   1.Play    ***    2.Exit   ****\n");
	printf("*************************************\n");
	printf("��ѡ��");
	scanf("%d", &choice);
	return choice;
}

//char board[][COL] �β�ʵ����ʱ����ά���齵ά������ָ�룬
//���Գ�ʼ����ά����ĵڶ���[COL]������ֵ��
//��̬����ֻ�ܱ�game.c�ļ��е��á�
static void ChessBoard(char board[][COL], int row, int col)
{   /*���̽���*/
	printf("     1   2   3  \n");
	printf("   +---+---+---+\n");
	for (int row = 0; row < ROW; row++)
	{
		printf("%d", row + 1);
		printf("  | %c | %c | %c |\n", board[row][0],
			board[row][1], board[row][2]);//memset(board,' ',sizeof(board)); %c ��ӡ�ո�
		printf("   +---+---+---+\n");
	}
}

static void PlayerMove(char board[][COL], int row, int col)
{   /*��������*/
	int x = 0;
	int y = 0;
	int quit = 0;
	while (1){
		printf("���������λ��# ");
		scanf("%d %d", &x, &y);
		if (x < 1 || x > 3 || y < 1 || y > 3)
		{
			printf("���������������\n");
			continue;
		}
		else if (board[x - 1][y - 1] != ' ')
		{
			printf("��λ���Ѿ���ռ��!\n");
			continue;
		}
		else
		{
			board[x - 1][y -1] = P_COLOR;
			break;
		}
	}
}

static char Judge(char board[][COL], int row, int col)
{  /*�ж���������*/
	for (int i = 0; i < row; i++)//"��"��������
	{
		if (board[i][0] == board[i][1] && \
			board[i][1] == board[i][2] && \
			board[i][0] != ' ')//��б�ܽ�����һ��
		{   
			return board[i][0];
		}
	}

	for (int j = 0; j < col; j++)//"��"��������
	{
		if (board[0][j] == board[1][j] && \
			board[1][j] == board[2][j] && \
			board[0][j] != ' ')
		{
			return board[0][j];
		}
	}

	if (board[0][0] == board[1][1] && \
		board[1][1] == board[2][2] && \
		board[0][0] != ' ')//"\"��������
	{
		return board[1][1];
	}

	if (board[0][2] == board[1][1] && \
		board[1][1] == board[2][0] && \
		board[1][1] != ' ')//"/"��������
	{
		return board[1][1];
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return NEXT;//���п�λ���������ӡ�
			}
		}
	}

	return DRAW;//û�п�λ������ƽ�֡�
}

static void ComputerMove(char board[][COL], int row, int col)
{  /*��������*/
	while (1)
	{
		int x = rand() % row;//��Ҫ����[m,n]��Χ�ڵ������num�����ã�int num = rand() % (n - m + 1) + m;
		int y = rand() % col;//����һ��[0��clo-1]��
		if (board[x][y] == ' ')
		{
			board[x][y] = C_COLOR;
			break;
		}
	}
}

void Game()
{
	srand((unsigned long)time(NULL));//��һ�����������
	char board[ROW][COL];
	memset(board,' ',sizeof(board));//������board�ÿո��滻��sizeof(board)�������������С
	char result = 'x';
	do{
		ChessBoard(board, ROW, COL);
		PlayerMove(board, ROW, COL);
		result = Judge(board, ROW, COL);
		if (result != NEXT)
		{
			break;
		}
		ComputerMove(board, ROW, COL);
		result = Judge(board, ROW, COL);
		if (result != NEXT)
		{
			break;
		}
	} while (1);
		if (P_COLOR == result)
		{
			printf("��Ӯ��!\n");
		}
		else if (C_COLOR == result)
		{
			printf("������!\n");
		}
		else
		{
			printf("����!\n");
		}
		ChessBoard(board, ROW, COL);
}