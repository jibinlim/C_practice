#include <stdio.h>
#include <stdlib.h>
#define INF 500000

int **map;
int *visit;
int *d;

void dijkstra(int maxV, int startV)
{
	for(int i = 1; i <= maxV; i++)
		d[i] = INF;
	d[startV] = 0;

	for(int i = 1; i <= maxV; i++)
	{
		int min = INF;

		for(int j = 1; j <= maxV; j++)
		{
			if(visit[j] == 0 && min > d[j])
			{
				min = d[j];
				startV = j;
			}
		}
		visit[startV] = 1;

		for(int nextV = 1; nextV <= maxV; nextV++)
			if(map[startV][nextV] != INF && d[nextV] > d[startV] + map[startV][nextV])
				d[nextV] = d[startV] + map[startV][nextV];
	}
	for(int i = 1; i <= maxV; i++)
	{
		if(d[i] == INF)
			printf("INF\n");
		else
			printf("%d\n",d[i]);
	}
}



int main(void)
{
	int v,e;
	scanf("%d %d",&v,&e);
	int s;
	scanf("%d",&s);

	visit = (int *) malloc (sizeof(int) * (v + 1));
	d = (int *) malloc (sizeof(int) * (v + 1));

	map = (int **) malloc (sizeof(int *) * (v + 1));
	for(int i = 1; i <= v; i++)
	{
		map[i] = (int *) malloc (sizeof(int) * (v + 1));
		for(int j = 1; j <= v; j++)
			map[i][j] = INF;
		visit[i] = 0;
	}
	for(int i = 0; i < e; i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		if(map[a][b] > c)
			map[a][b] = c;
	}
	dijkstra(v, s);
	for(int i = 0; i <= v; i++)
		free(map[i]);
	free(map);
	free(visit);
	free(d);
	return (0);
}
