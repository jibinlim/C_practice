#include <stdio.h>

int w_p = 0;
int b_p = 0;
int paper[128][128];

void dfs(int x,int y,  int n)
{
	int z = paper[x][y];
	int f = 0;
	for(int i = x; i < x + n; i++)
	{
		for(int j = y; j < y + n; j++)
		{
			if(z != paper[i][j])
			{
				f = 1;
				break;
			}
		}
		if(f == 1)
			break;
	}
	if(f == 0)
	{
		if(z == 0)
			w_p++;
		else
			b_p++;
	}
	else
	{
		dfs(x, y, n / 2);
		dfs(x,y + n / 2, n / 2);
		dfs(x + n / 2, y , n / 2);
		dfs(x + n / 2, y + n / 2,  n / 2);
	}
}
int main(void)
{
	int n;
	scanf("%d",&n);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d",&paper[i][j]);

	dfs(0,0,n);
	printf("%d\n%d",w_p,b_p);
	return (0);
}
