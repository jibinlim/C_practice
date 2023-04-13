#include <stdio.h>
#include <stdlib.h>

int n;
int **g;
int **out;
int **visit;

void dfs(int x,int y,int a)
{
	if(out[a][y] == 1)
		return ;
	out[a][y] = 1;
	visit[a][y] = 1;
	for(int i = 0; i < n; i++)
		if(g[y][i] == 1 && visit[y][i] == 0)
			dfs(y,i,a);
	visit[a][y] = 0;
}

int main(void)
{
	scanf("%d", &n);
	visit = (int **) malloc (sizeof(int *) * n);
	out = (int **) malloc (sizeof(int *) * n);
	g = (int **) malloc (sizeof(int *) * n);
	for(int i = 0; i < n; i++)
	{
		out[i] = (int *) malloc (sizeof(int) * n);
		g[i] = (int *) malloc (sizeof(int) * n);
		visit[i] = (int *) malloc (sizeof(int) * n);
		for(int j = 0; j < n; j++)
		{
			scanf("%d",&g[i][j]);
			visit[i][j] = 0;
			out[i][j] = 0;
		}
	}

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(g[i][j] == 1 && visit[i][j] == 0)
				dfs(i,j,i);

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			printf("%d ",out[i][j]);
		printf("\n");
		free(visit[i]);
		free(g[i]);
		free(out[i]);
	}
	free(visit);
	free(g);
	free(out);
	return (0);
}
