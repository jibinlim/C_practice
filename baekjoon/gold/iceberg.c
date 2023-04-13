#include <stdio.h>

int map[300][300] = {0,};
int visit[300][300] = {0,};
int r_visit[300][300] = {0,};
int n,m;
int x = 0;
void dfs(int x, int y)
{
	int count = 0;
	visit[x][y] = 1;
	int mo[4] = {0,0,-1,1};
	int ve[4] = {-1,1,0,0};

	for(int i = 0; i < 4; i++)
	{
		int dx = x + mo[i];
		int dy = y + ve[i];

		if(dx < 0 || dy < 0 || dx > n - 1 || dy > m - 1)
			continue;
		if(map[dx][dy] == 0 && visit[dx][dy] == 0)
			count++;
		if(visit[dx][dy] == 0 && map[dx][dy] != 0)
			dfs(dx,dy);
	}
	map[x][y] -= count;
	if(map[x][y] < 0)
		map[x][y] = 0;
}

void r_dfs(int x, int y)
{
	r_visit[x][y] = 1;
	int mo[4] = {0,0,-1,1};
	int ve[4] = {-1,1,0,0};

	for(int i = 0; i < 4; i++)
	{
		int dx = x + mo[i];
		int dy = y + ve[i];

		if(dx < 0 || dy < 0 || dx > n - 1 || dy > m - 1)
			continue;
		if(map[dx][dy] != 0 && r_visit[dx][dy] == 0)
			r_dfs(dx,dy);
	}
}

int check(void)
{
	int count = 0;
	for(int i = 0 ; i < n ; i++)
		for(int j = 0; j < m; j++)
		{
			visit[i][j] = 0;
			r_visit[i][j] = 0;
		}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(r_visit[i][j] == 0 && map[i][j] != 0)
			{
				x = 1;
				r_dfs(i,j);
				count++;
				if(count >= 2)
					return (1);
			}
	return (0);
}

int main(void)
{
	scanf("%d %d",&n,&m);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			scanf("%d",&map[i][j]);

	int y = 0;
	int c = check();
	while(1)
	{
		if(c == 1)
			break;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				if(map[i][j] != 0)
				{
					x = 0;
					dfs(i,j);
					y++;
					c = check();
					if(c == 1)
						break;
				}
			}
			if(c == 1)
				break;
		}
		if(x == 0)
			break;
	}

	int f = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
			if(map[i][j] != 0)
			{
				f = 1;
				break;
			}
		if(f == 1)
			break;
	}
	if(f == 0)
		y = 0;
	printf("%d\n",y);
	return (0);
}

