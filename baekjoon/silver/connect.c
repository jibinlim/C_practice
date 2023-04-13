#include <stdio.h>
#include <stdlib.h>

int *visit;
int **graph;
int n;

void dfs(int x)
{
	visit[x] = 1;
	for(int i = 0; i < n; i++)
		if(visit[i] == 0 && graph[x][i] == 1)
		{
			graph[x][i] = 0;
			dfs(i);
		}
}

int main(void)
{
	int m;
	scanf("%d %d",&n,&m);

	graph = (int **) malloc (sizeof(int *) * n);
	visit = (int *) malloc (sizeof(int) * n);
	for(int i = 0; i < n; i++)
	{
		visit[i] = 0;
		graph[i] = (int *) malloc (sizeof(int) * n);
		for(int j = 0 ; j < n ; j++)
			graph[i][j] = 0;
	}
	int a,b;
	for(int i = 0; i < m; i++)
	{
		scanf("%d %d",&a,&b);
		graph[a - 1][b - 1] = 1;
		graph[b - 1][a - 1] = 1;
	}
	int count = 0;
	for(int i = 0; i < n; i++)
		if(visit[i] == 0)
		{
			dfs(i);
			count++;
		}

	for(int i = 0; i < n; i++)
		free(graph[i]);
	free(graph);
	free(visit);
	printf("%d\n",count);
	return (0);
}
