#include <stdio.h>

int stack[10] = {0,};
int visit[10] = {0,};

int n,m;

void dfs(int i,int x)
{
	visit[i] = 1;
	stack[x - 1] = i;
	if(x == m)
	{
		for(int j = 0; j < m; j++)
			printf("%d ",stack[j]);
		printf("\n");
	}
	else
	{
		for(int j = i + 1; j <= n; j++)
		{
			if(visit[j] == 0)
				dfs(j,x+1);
		}
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
