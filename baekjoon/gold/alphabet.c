#include <stdio.h>
#include <stdlib.h>


int r,c;
int result;

int max(int a, int b)
{
	if(a > b)
		return a;
	else 
		return b;
}

void dfs(char **board, int x, int y, int visit[27],int count)
{
	visit[board[x][y] - 'A'] = 1;
	result = max(result,count);
	int mo[4] = {0, 0, -1, 1};
	int ve[4] = {-1, 1 , 0 , 0};

	for(int i = 0; i < 4; i++)
	{
		int dx = x + mo[i];
		int dy = y + ve[i];

		if(dx < 0 || dy < 0 || dx > r - 1 || dy > c - 1)
			continue;
		if(visit[board[dx][dy] - 'A'] == 0)
		{
			dfs(board, dx, dy, visit,count + 1);
			visit[board[dx][dy] - 'A'] = 0;
		}
	}
}
	

int main(void)
{
	scanf("%d %d",&r,&c);

	char **board;

	int max = 0;
	board = (char **) malloc (sizeof(char *) * (r + 1));
	for(int i = 0; i < r; i++)
	{
		board[i] = (char *) malloc (sizeof(char) * (c + 1));
		scanf("%s",board[i]);
	}
	int count = 1;
	int visit[27] = {0,};
	dfs(board,0,0,visit,count);
	printf("%d\n",result);
	for(int i = 0 ; i < r; i++)
		free(board[i]);
	free(board);
	return (0);
}
