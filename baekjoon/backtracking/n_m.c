#include <stdio.h>

int n,m;
int stack[9];
int visit[9] = {0,};

void dfs(int x, int count)
{
	stack[count] = x;
	if(count == m - 1)
	{
		for(int i = 0; i <= count; i++)
			printf("%d ",stack[i]);
		printf("\n");
		return ;
	}
	for(int i = 1; i <= n; i++)
		if(visit[i] == 0)
		{
			visit[i] = 1;
			dfs(i,count + 1);
			visit[i] = 0;
		}
}

int main(void)
{
	scanf("%d %d",&n,&m);

	for(int i = 1; i <= n; i++)
	{
		visit[i] = 1;
		dfs(i,0);
		visit[i] = 0;
	}
	return (0);
}
