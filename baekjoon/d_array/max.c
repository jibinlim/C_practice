#include <stdio.h>

int main(void)
{
	int board[9][9];
	int max = 0;;
	int a = 1;
	int b = 1;

	for(int i = 0 ; i < 9 ; i++)
		for(int j = 0; j < 9 ; j++)
			scanf("%d",&board[i][j]);

	for(int i = 0; i < 9; i++)
		for(int j = 0; j < 9; j++)
			if(max < board[i][j])
			{
				max = board[i][j];
				a = i + 1;
				b = j + 1;
			}

	printf("%d\n",max);
	printf("%d %d",a,b);
	return (0);
}
