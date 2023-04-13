#include <stdio.h>
#include <stdlib.h>

struct p{
	int x;
	int y;
};

int main(void)
{
	int n,m;

	scanf("%d %d",&n,&m);

	long long  dp[1025][1025];
	int x[1025][1025];
	long long q;

	for(int i = 1; i <= n; i++)
	{
		q = 0;
		for(int j = 1; j <= n; j++)
		{
			scanf("%d",&x[i][j]);
			q += x[i][j];
			if(i == 1 && j == 1)
				dp[i][j] = x[i][j];
			else if(i == 1)
				dp[i][j] = q;
			else if(j == 1)
				dp[i][j] = dp[i - 1][j] + x[i][j];
			else
				dp[i][j] = q + dp[i - 1][j];
		}
	}


	struct p* a;
	struct p* b;
	int z;
	int y;

	a = (struct p*) malloc (sizeof(struct p) * m);
	b = (struct p*) malloc (sizeof(struct p) * m);

	for(int i = 0; i < m; i++)
	{
		int sum = 0;
		scanf("%d %d %d %d",&a[i].x,&a[i].y,&b[i].x,&b[i].y);
		z = b[i].x - a[i].x;
		y = b[i].y - a[i].y;
		if(a[i].x > 1 && a[i].y > 1)
			sum = dp[b[i].x][b[i].y] - (dp[a[i].x - 1][b[i].y] + dp[b[i].x][a[i].y - 1] - dp[a[i].x - 1][a[i].y - 1]);
		else if(a[i].x > 1)
			sum = dp[b[i].x][b[i].y] - dp[a[i].x - 1][b[i].y];
		else if(a[i].y > 1)
			sum = dp[b[i].x][b[i].y] - dp[b[i].x][a[i].y - 1];
		else
			sum = dp[b[i].x][b[i].y];
		printf("%d\n",sum);
	}
	free(a);
	free(b);
	return (0);
}
