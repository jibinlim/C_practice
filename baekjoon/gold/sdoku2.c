#include <stdio.h>
#include <stdlib.h>

int sdoku[9][9];

int avail(int x,int y, int k)
{
	int x_visit[10] = {0,};
	int y_visit[10] = {0,};
	int r_visit[10] = {0,};
	x_visit[k]++;
	y_visit[k]++;
	r_visit[k]++;

	for(int i = 0; i < 9; i++)
	{
		if(i != y)
		{
			if(sdoku[x][i] != 0)
				x_visit[sdoku[x][i]]++;
		}
		if(i != x)
		{
			if(sdoku[i][y] != 0)
				y_visit[sdoku[i][y]]++;
		}
		if(x_visit[sdoku[x][i]] >= 2)
			return (0);
		if(y_visit[sdoku[i][y]] >= 2)
			return (0);
	}
	for(int i = (x / 3) * 3; i < ((x / 3) * 3) + 3; i++)
		for(int j = (y / 3) * 3; j < ((y / 3) * 3) + 3; j++)
		{
			if(i != x && j != y)
			{
				if(sdoku[i][j] != 0)
					r_visit[sdoku[i][j]]++;
			}
			if(r_visit[sdoku[i][j]] >= 2)
				return (0);
		}
	return (1);
}

void dfs(int x,int y)
{
	if(y == 9)
	{
		x++;
		y = 0;
	}
	if(x == 9)
	{
		for(int i = 0 ; i < 9; i++)
		{
			for(int j = 0; j < 9; j++)
				printf("%d",sdoku[i][j]);
			printf("\n");
		}
		exit(0);
	}

	if(sdoku[x][y] != 0)
		dfs(x, y+1);
	else
	{
		for(int k = 1; k <= 9; k++)
		{
			if(avail(x,y,k) == 1)
			{
				sdoku[x][y] = k;
				dfs(x, y+1);
				sdoku[x][y] = 0;
			}
		}
	}
}

int main(void)
{
	for(int i = 0; i < 9; i++)
		for(int j = 0; j < 9; j++)
			scanf("%1d",&sdoku[i][j]);
				
	dfs(0,0);
	return (0);
}
