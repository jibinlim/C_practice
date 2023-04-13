#include <stdio.h>

int z;
int m,n,k;
int sec[101][101];

int cmp(const void *a, const void *b)
{
	if(*(int *)a > *(int *)b)
		return 1;
	else if (*(int *)a < *(int *)b)
		return -1;
	else
		return 0;
}

void dfs(int x, int y)
{
	sec[x][y] = 1;
	z++;
	int mo[4] = {0,0,-1,1};
	int ve[4] = {-1,1,0,0};

	for(int i = 0; i < 4; i++)
	{
		int dx = x + mo[i];
		int dy = y + ve[i];

		if(dx < 0 || dx > m - 1 || dy < 0 || dy > n - 1)
			continue;
		if(sec[dx][dy] == 0)
			dfs(dx, dy);
	}
}



int main(void)
{
	scanf("%d %d %d",&m,&n,&k);
	int x1,x2,y1,y2;
	int count = 0;
	int c[1001] = {0,};

	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			sec[i][j] = 0;

	for(int i = 0; i < k; i++)
	{
		scanf("%d %d %d %d",&y1,&x1,&y2,&x2);
		for(int j = x1; j < x2; j++)
			for(int k = y1; k < y2; k++)
				sec[j][k] = 1;
	}

	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
		{
			if(sec[i][j] == 0)
			{
				z = 0;
				dfs(i,j);
				c[count] = z;
				count++;
			}
		}
	qsort(c,count,sizeof(int),cmp);
	printf("%d\n", count);
	for(int i = 0; i < count; i++)
	{
		if(i != count - 1)
			printf("%d ",c[i]);
		else
			printf("%d",c[i]);
	}
	return (0);
}
