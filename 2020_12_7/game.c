#include "game.h"

int Meun(int choice)
{
	printf("*************************************\n");
	printf("****   1.Play    ***    2.Exit   ****\n");
	printf("*************************************\n");
	printf("请选择：");
	scanf("%d", &choice);
	return choice;
}

//char board[][COL] 形参实例化时，二维数组降维成数组指针，
//所以初始化二维数组的第二个[COL]必须有值。
//静态函数只能本game.c文件中调用。
static void ChessBoard(char board[][COL], int row, int col)
{   /*棋盘界面*/
	printf("     1   2   3  \n");
	printf("   +---+---+---+\n");
	for (int row = 0; row < ROW; row++)
	{
		printf("%d", row + 1);
		printf("  | %c | %c | %c |\n", board[row][0],
			board[row][1], board[row][2]);//memset(board,' ',sizeof(board)); %c 打印空格。
		printf("   +---+---+---+\n");
	}
}

static void PlayerMove(char board[][COL], int row, int col)
{   /*棋手落子*/
	int x = 0;
	int y = 0;
	int quit = 0;
	while (1){
		printf("请输入你的位置# ");
		scanf("%d %d", &x, &y);
		if (x < 1 || x > 3 || y < 1 || y > 3)
		{
			printf("你输入的坐标有误！\n");
			continue;
		}
		else if (board[x - 1][y - 1] != ' ')
		{
			printf("该位置已经被占用!\n");
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
{  /*判断三子连珠*/
	for (int i = 0; i < row; i++)//"行"三子连珠
	{
		if (board[i][0] == board[i][1] && \
			board[i][1] == board[i][2] && \
			board[i][0] != ' ')//反斜杠接续下一行
		{   
			return board[i][0];
		}
	}

	for (int j = 0; j < col; j++)//"列"三子连珠
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
		board[0][0] != ' ')//"\"三子连珠
	{
		return board[1][1];
	}

	if (board[0][2] == board[1][1] && \
		board[1][1] == board[2][0] && \
		board[1][1] != ' ')//"/"三子连珠
	{
		return board[1][1];
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return NEXT;//还有空位，正在落子。
			}
		}
	}

	return DRAW;//没有空位，和棋平局。
}

static void ComputerMove(char board[][COL], int row, int col)
{  /*电脑落子*/
	while (1)
	{
		int x = rand() % row;//如要产生[m,n]范围内的随机数num，可用：int num = rand() % (n - m + 1) + m;
		int y = rand() % col;//产生一个[0，clo-1]数
		if (board[x][y] == ' ')
		{
			board[x][y] = C_COLOR;
			break;
		}
	}
}

void Game()
{
	srand((unsigned long)time(NULL));//种一个随机数种子
	char board[ROW][COL];
	memset(board,' ',sizeof(board));//将数组board用空格替换；sizeof(board)代表整个数组大小
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
			printf("你赢了!\n");
		}
		else if (C_COLOR == result)
		{
			printf("你输了!\n");
		}
		else
		{
			printf("和棋!\n");
		}
		ChessBoard(board, ROW, COL);
}