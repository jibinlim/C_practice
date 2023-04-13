#include <stdio.h>

int stack[10] = {0,};
int x[10] = {0,};
int visit[10] = {0,};
int n,m;

int cmp(const void *a, const void *b)
{
	if(*(int *)a > *(int *)b)
		return 1;
	else if (* (int *)a < *(int *)b)
		return -1;
	else
		return 0;
}

void dfs(int i,int y)
{
	visit[i] = 1;
	stack[y - 1] = x[i - 1];
	if(y == m)
	{
		for(int j = 0; j < m; j++)
			printf("%d ",stack[j]);
		printf("\n");
	}
	else
	{
		for(int j = i; j <= n; j++)
			dfs(j,y+1);
	}
	visit[i] = 0;
}


int main(void)
{
	scanf("%d %d",&n,&m);
	for(int i = 0; i < n; i++)
		scanf("%d",&x[i]);
	qsort(x,n,sizeof(int),cmp);
	for(int i = 1; i <= n; i++)
		dfs(i,1);
	return (0);
}
