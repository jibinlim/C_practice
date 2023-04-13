#include <stdio.h>
#define MAX 1001
#define INF 999999999

int dd[MAX];

int visited[MAX];
int map[MAX][MAX];

void dijkstra(int maxV, int startV, int destV)
{
	for(int i = 1; i <= maxV; i++)
		dd[i] = INF;
	dd[startV] = 0;

	for(int i = 1; i <= maxV; i++)
	{
		int min = INF;

		for(int j = 1; j <= maxV; j++)
		{
			if(!visited[j] && min > dd[j])
			{
				min = dd[j];
				startV = j;
			}
		}
		visited[startV] = 1;

		for(int nextV = 1; nextV <= maxV; nextV++)
			if(map[startV][nextV] != INF && dd[nextV] > dd[startV] + map[startV][nextV])
				dd[nextV] = dd[startV] + map[startV][nextV];
	}
	printf("%d\n", dd[destV]);
}

void initMap(void)
{
	for(int y = 0; y < MAX; y++)
		for(int x = 0; x < MAX; x++)
			map[y][x] = INF;
}

int main(void)
{
	int S = 0;
	int D = 0;
	int N = 0;
	int M = 0;

	initMap();

	scanf("%d",&N);
	scanf("%d",&M);

	for(int i = 0; i < M; i++)
	{
		int s = 0;
		int d = 0;
		int w = 0;

		scanf("%d %d %d", &s, &d, &w);
		if(map[s][d] > w)
			map[s][d] = w;
	}

	scanf("%d %d", &S, &D);

	dijkstra(N, S, D);

	return (0);
}

