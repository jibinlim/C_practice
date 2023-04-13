#include <stdio.h>

int m,n,k,count;
int map[51][51], visit[51][51];

int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};


void dfs(int y, int x)
{
	visit[y][x] = 1;

	for(int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if(ny < 0 || nx < 0 || ny >= n || nx >= m)
			continue;
		if(map[ny][nx] == 1 && visit[ny][nx] == 0)
			dfs(ny ,nx);
	}
}

int main(void)
{
	int t;
	scanf("%d",&t);
	for(int b = 0; b < t; b++)
	{
		count = 0;

		scanf("%d %d %d",&m, &n, &k);

		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
			{
				visit[i][j] = 0;
				map[i][j] = 0;
			}

		for(int i = 0; i < k; i++)
		{
			int x , y;
			scanf("%d %d",&x, &y);
			map[y][x] = 1;
		}

		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				if(map[i][j] == 1 && visit[i][j] == 0)
				{
					dfs(i , j);
					count++;
				}
		printf("%d\n",count);
	}
	return (0);
}
