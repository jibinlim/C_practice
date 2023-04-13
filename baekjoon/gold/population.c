#include <stdio.h>
#include <stdlib.h>
int check[51][51][4] = {0,};
int **a;
int n;
int visit[51][51] = {0,};
int sum = 0;
int count = 0;
int f;
int q[51][51] = {0,};

void dfs(int x,int y,int l, int r)
{
	int mo[4] = {0,0,-1,1};
	int ve[4] = {-1,1,0,0};
	for(int i = 0; i < 4; i++)
	{
		int dx = x + mo[i];
		int dy = y + ve[i];

		if(dx < 0 || dy < 0 || dx > n - 1 || dy > n - 1)
			continue;
		if(a[dx][dy] > a[x][y])
		{
			if(a[dx][dy] - a[x][y] >= l && a[dx][dy] - a[x][y] <= r)
			{
				f = 1;
				q[dx][dy] = 1;
				check[x][y][i] = 1;
			}
		}
		else
			if(a[x][y] - a[dx][dy] >= l && a[x][y] - a[dx][dy] <= r)
			{
				f = 1;
				q[dx][dy] = 1;
				check[x][y][i] = 1;
			}
	}
}

void avg(int x,int y)
{
	visit[x][y] = 1;
	int mo[4] = {0,0,-1,1};
	int ve[4] = {-1,1,0,0};
	sum += a[x][y];
	count++;
	for(int i = 0; i < 4; i++)
	{
		int dx = x + mo[i];
		int dy = y + ve[i];

		if(dx < 0 || dy < 0 || dx > n - 1 || dy > n - 1)
			continue;
		if(visit[dx][dy] == 0 && check[x][y][i] == 1)
			avg(dx,dy);
	}
}

void g(int x,int y, int sum)
{
	visit[x][y] = 1;
	a[x][y] = sum;
	int mo[4] = {0,0,-1,1};
	int ve[4] = {-1,1,0,0};

	for(int i = 0; i < 4; i++)
	{
		int dx = x + mo[i];
		int dy = y + ve[i];

		if(dx < 0 || dy < 0 || dx > n - 1 || dy > n - 1)
			continue;
		if(visit[dx][dy] == 0 && check[x][y][i] == 1)
			g(dx,dy,sum);
	}
}


int main(void)
{
	int l,r;
	scanf("%d %d %d",&n,&l,&r);

	int i,j,k;
	a = (int **) malloc (sizeof(int *) * n);
	for(i = 0; i < n; i++)
	{
		a[i] = (int *) malloc (sizeof(int) * n);
		for(j = 0; j < n; j++)
			scanf("%d",&a[i][j]);
	}
	int d = 0;
	while(1)
	{
		f = 0;
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				dfs(i,j,l,r);
		if(f == 0)
			break;
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
			{
				if(visit[i][j] == 0 && q[i][j] == 1)
				{
					sum = 0;
					count = 0;
					avg(i,j);
				}
				for(k = 0; k < n; k++)
					for(int z = 0; z < n; z++)
						visit[k][z] = 0;
				if(count == 0)
					continue;
				int x = sum / count;
				if(visit[i][j] == 0 && q[i][j] == 1)
					g(i,j,x);
			}
		for(k = 0; k < n; k++)
			for(int z = 0; z < n; z++)
			{
				q[k][z] = 0;
				visit[k][z] = 0;
			}

		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				for(k = 0; k < 4; k++)
					check[i][j][k] = 0;

		d++;
	}
	printf("%d",d);
	for(int i = 0; i < n; i++)
		free(a[i]);
	free(a);

	return (0);
}
