#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sol(int x[100][100],int visit[100][100],int a, int b,int n)
{
	visit[a][b] = 1;
	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0 , 1, -1};
	for(int i = 0; i < 4; i++)
	{
		int nx = a + dx[i];
		int ny = b + dy[i];
		if(nx < 0 || ny < 0 || nx > n - 1 || ny > n - 1)
			continue;
		if(x[nx][ny] != 0 && visit[nx][ny] == 0)
			sol(x,visit,nx,ny,n);
	}
}


int dfs(int zone[100][100], int n,int m)
{
	int x[100][100];
	int count = 0;
	int visit[100][100] = {0,};
	int t = 0;
	for(int i = 0; i < n; i++)
	{
		memcpy(x[i],zone[i],sizeof(int) * n);
		for(int j = 0; j < n; j++)
		{
			if(x[i][j] <= m)
				x[i][j] = 0;
		}
	}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(x[i][j] != 0 && visit[i][j] == 0)
			{
				sol(x,visit,i,j,n);
				count++;
			}
	return (count);
}



int main(void)
{
	int n;
	scanf("%d",&n);
	int zone[100][100] = {0,};
	int max = 0;
	int ans = 0;
	int a;
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			scanf("%d",&zone[i][j]);
			if(zone[i][j] > max)
				max = zone[i][j];
		}
	}
	for(int i = max - 1; i >= 1; i--)
	{
		a = dfs(zone, n, i);
		if(a > ans)
			ans = a;
	}
	if(ans == 0)
		ans = 1;
	printf("%d",ans);
	return (0);
}

