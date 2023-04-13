#include <stdio.h>
#include <stdlib.h>

struct p{
	int x;
	int y;
};

int main(void)
{
	int m,n,k;
	scanf("%d %d %d",&m,&n,&k);

	struct p *a,*b,queue[100001];
	int **map;
	int **dp;
	int front = 0 ,rear = 0;
	int x, y;
	dp = (int **) malloc (sizeof(int *) * m);
	map = (int **) malloc (sizeof(int *) * m);
	for(int i = 0; i < m; i++)
	{
		dp[i] = (int *) malloc (sizeof(int) * n);
		map[i] = (int *) malloc (sizeof(int) * n);
		for(int j = 0; j < n; j++)
			map[i][j] = 0;
	}

	a = (struct p*) malloc (sizeof(struct p) * k);
	b = (struct p*) malloc (sizeof(struct p) * k);

	for(int i = 0 ; i < k; i++)
	{
		scanf("%d %d",&a[i].y,&a[i].x);
		scanf("%d %d",&b[i].y,&b[i].x);
		if(a[i].x < b[i].x)
		{
			for(int j = a[i].x ; j < b[i].x ; j++)
			{
				if(a[i].y < b[i].y)
				{
					for(int t = a[i].y; t < b[i].y; t++)
						map[j][t] = -1;
				}
				else if(a[i].y > b[i].y)
				{
					for(int t = b[i].y; t < a[i].y; t++)
						map[j][t] = -1;
				}
			}
		}
		else if(a[i].x > b[i].x)
		{
			for(int j = b[i].x; j < a[i].x; j++)
			{
				if(a[i].y > b[i].y)
				{
					for(int t = b[i].y; t < a[i].y; t++)
						map[j][t] = -1;
				}
				else if(a[i].y < b[i].y)
				{
					for(int t = a[i].y; t < b[i].y; t++)
						map[j][t] = -1;
				}
			}
		}
	}

	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			if(map[i][j] == 0)
			{
				queue[rear].x = i;
				queue[rear].y = j;
				dp[i][j] = 1;
				rear++;
			}
	while(front < rear)
	{
		x = queue[front].x;
		y = queue[front].y;
		front++;
		map[x][y] = 1;
		if(x > 0 && map[x - 1][y] == 0)
		{
			map[x - 1][y] = 1;
			queue[rear].x = x - 1;
			queue[rear].y = y;
			dp[x - 1][y] += dp[x][y];
			rear++;
		}
		if(x < m - 1 && map[x + 1][y] == 0)
		{
			map[x + 1][y] = 1;
			queue[rear].x = x + 1;
			queue[rear].y = y;
			dp[x + 1][y] += dp[x][y];
			rear++;
		}
		if(y > 0 && map[x][y - 1] == 0)
		{
			map[x][y - 1] = 1;
			queue[rear].x = x;
			queue[rear].y = y - 1;
			dp[x][y - 1] += dp[x][y];
			rear++;
		}
		if(y < n - 1 && map[x][y + 1] == 0)
		{
			map[x][y + 1] = 1;
			queue[rear].x = x;
			queue[rear].y = y + 1;
			dp[x][y + 1] += dp[x][y];
			rear++;
		}
	}

	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
			printf("%d ",dp[i][j]);
		printf("\n");
		free(dp[i]);
		free(map[i]);
	}
	free(dp);
	free(map);
	free(a);
	free(b);
	return (0);
}
