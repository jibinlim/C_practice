#include <stdio.h>
int n,m;
int s[9] = {0,};

void dfs(int i,int x)
{
	visit[i] = 1;
	s[x] = i;
	if(x == m)
	{
		for(int j = 1; j <= m; j++)
			printf("%d ",s[j]);
		printf("\n");
	}
	else
		for(int j = 1; j <= n; j++)
		{
			if(visit[j] != 1)
				dfs(j, x + 1);
		}
	visit[i] = 0;
}

int main(void)
{
	scanf("%d %d",&n,&m);

	for(int i = 1; i <= n; i++)
		dfs(i,1);
	return (0);
}
