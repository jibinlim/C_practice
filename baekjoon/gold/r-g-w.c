#include <stdio.h>
#include <stdlib.h>

int n;
int count = 0;
int count_x = 0;
int visit[101][101] = {0,};
int visit_x[101][101] = {0,};

void dfs_x(char **a,char s,int x,int y)
{
	visit_x[x][y] = 1;
	int mo[4] = {0,0,1,-1};
	int ve[4] = {1,-1,0,0};
	for(int i = 0; i < 4; i++)
	{
		int dx = x + mo[i];
		int dy = y + ve[i];
		if(dx < 0 || dy < 0 || dx > n - 1 || dy > n - 1)
			continue;
		if(visit_x[dx][dy] == 0)
		{
			if(s == 'B' && a[dx][dy] == 'B')
				dfs_x(a,s,dx,dy);
			if(s != 'B' && a[dx][dy] != 'B')
				dfs_x(a,s,dx,dy);
		}
	}
}

void dfs(char **a,char s, int x,int y)
{
	visit[x][y] = 1;
	int mo[4] = {0,0,1,-1};
	int ve[4] = {1,-1,0,0};
	for(int i = 0; i < 4; i++)
	{
		int dx = x + mo[i];
		int dy = y + ve[i];
		if(dx < 0 || dy < 0 || dx > n - 1 || dy > n - 1)
			continue;
		if(visit[dx][dy] == 0 && a[dx][dy] == s)
			dfs(a,s,dx,dy);
	}
}
int main(void)
{
	scanf("%d",&n);
	char color[4] = "RBG";

	char **a;
	a = (char **) malloc (sizeof(char *) * (n + 1));
	for(int i = 0; i < n; i++)
	{
		a[i] = (char *) malloc (sizeof(char) * (n + 1));
		scanf("%s",a[i]);
	}
	for(int k = 0; k < 3; k++)
	{
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if(visit[i][j] == 0 && a[i][j] == color[k])
				{
					dfs(a,color[k],i,j);
					count++;
				}
	}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(visit_x[i][j] == 0 && a[i][j] == 'B')
			{
				dfs_x(a,'B',i,j);
				count_x++;
			}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(visit_x[i][j] == 0 && a[i][j] != 'B')
			{
				dfs_x(a,'R',i,j);
				count_x++;
			}
	printf("%d %d\n",count, count_x);
	for(int i = 0; i < n; i++)
		free(a[i]);
	free(a);
	return (0);
}
