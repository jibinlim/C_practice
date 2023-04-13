#include <stdio.h>
int n,m;
int s[10];

void dfs(int x, int y)
{
	s[y] = x;
	if(y == m - 1)
	{
		for(int i = 0; i < m; i++)
			printf("%d ",s[i]);
		printf("\n");
	}
	else
	{
		for(int i = 1; i <= n; i++)
			dfs(i, y + 1);
	}
}

int main(void)
{
	scanf("%d %d",&n,&m);

	for(int i = 1; i <= n; i++)
		dfs(i,0);
	return (0);
}
