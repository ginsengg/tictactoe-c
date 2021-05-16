#include <stdio.h>

int board[3][3];

void clearBoard()
{
int i,j;

	for (i=0;i<3;i++)
	{
		for (j=0;j<3;j++)
		{
			board[i][j] = 0;
		}
	}
}

void printBoard()
{
int i,j;

	for (i=0;i<3;i++)
	{
		for (j=0;j<3;j++)
		{
			if (board[i][j] == 0)
				{printf("| ");}
			if (board[i][j] == 1)
				{printf("|X");}
			if (board[i][j] == 2)
				{printf("|O");}
		}
		printf("|\n");
	}
}

void move(int turn)
{
int i,j,b;
int playerMove;
b = 0;

printf("Ходит %d игрок\n", turn);
	while (b==0)
	{
		scanf("%d", &playerMove);
		i = playerMove % 10;
		j = (playerMove - i) / 10;
		i -= 1;
		j -= 1;
		if (board[i][j] != 0)
			{printf("Введите верное значение\n");}
		else
			{b=1;}
	}
board[i][j] = turn;
}

int isGameOver(int turn)
{
int i;
int result;
result = 0;

	for (i=0;i<3;i++)
	{
		/*	 lanes		*/
		if (board[i][0] == turn && board[i][1] == turn && board[i][2] == turn)
			{result = turn;}
		if (board[0][i] == turn && board[1][i] == turn && board[2][i] == turn)
			{result = turn;}
	}
		/* 	diagonals	*/
	if (board[0][0] == turn && board[1][1] == turn && board[2][2] == turn)
		{result = turn;}
	if (board[0][2] == turn && board[1][1] == turn && board[2][0] == turn)
		{result = turn;}
	return result;
}

main()
{
int winner;
int turn;
int movesCount;
clearBoard();
printBoard();
turn = 1;
movesCount = 0;
winner = 0;

while (winner == 0 && movesCount < 9)
{
	move(turn);
	printBoard();
	winner = isGameOver(turn);
	movesCount = movesCount + 1;
	if (turn==1){turn=2;}
	else {turn=1;}
}
if (movesCount == 9 && winner == 0)
	{printf("Ничья");}
else
	{printf("Победил %d игрок", winner);}
}
