#include <stdio.h>
#include <stdlib.h>

#define INF 9999999
int **map;

void dijikstra(int start, int max)
{
	int *p;
	int *visit;
	p = (int *) malloc (sizeof(int) * (max + 1));
	visit = (int *) malloc (sizeof(int) * (max + 1));
	for(int i = 1; i <= max; i++)
	{
		p[i] = INF;
		visit[i] = 0;
	}
	p[start] = 0;

	for(int i = 1; i <= max; i++)
	{
		int min = INF;

		for(int j = 1; j <= max; j++)
		{
			if(visit[j] == 0 && min > p[j])
			{
				min = p[j];
				start = j;
			}
		}
		visit[start] = 1;

		for(int a = 1; a <= max; a++)
			if(map[start][a] != INF && p[a] > p[start] + map[start][a])
				p[a] = p[start] + map[start][a];
	}
	for(int i = 1; i <= max; i++)
	{
		if(p[i] == INF)
			printf("0 ");
		else
			printf("%d ",p[i]);
	}
	free(p);
	free(visit);
}

int main(void)
{
	int n,m;
	scanf("%d",&n);
	scanf("%d",&m);


	map = (int **) malloc (sizeof(int *) * (n + 1));
	for(int i = 1; i <= n; i++)
	{
		map[i] = (int *) malloc (sizeof(int) * (n + 1));
		for(int j = 1; j <= n; j++)
			map[i][j] = INF;
	}
	int start, end, cost;

	for(int i = 0; i < m; i++)
	{
		scanf("%d %d %d",&start,&end,&cost);
		if(map[start][end] > cost)
			map[start][end] = cost;
	}

	for(int i = 1; i <= n; i++)
	{
		dijikstra(i,n);
		printf("\n");
	}
	for(int i = 1; i <= n; i++)
		free(map[i]);
	free(map);
	return (0);
}

