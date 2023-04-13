#include <stdio.h>
#include <stdlib.h>

int n,m;
int visit[9] = {0,};
int s[9] = {0,};
int a[9];

int cmp(const void *a, const void *b)
{
	if(*(int *)a > *(int *)b)
		return 1;
	else if (*(int *)a < *(int *)b)
		return -1;
	else 
		return 0;
}

void dfs(int x,int cnt)
{
	visit[x] = 1;
	s[cnt] = a[x];
	if(cnt == m - 1)
	{
		for(int i = 0; i < m; i++)
			printf("%d ",s[i]);
		printf("\n");
	}
	else
	{
		for(int i = x + 1; i < n; i++)
		{
			if(visit[i] == 0)
				dfs(i,cnt+1);
		}
	}
	visit[x] = 0;
}

int main(void)
{
	scanf("%d %d",&n,&m);


	for(int i = 0; i < n; i++)
		scanf("%d",&a[i]);
	qsort(a,n,sizeof(int),cmp);
	for(int i = 0; i < n; i++)
		dfs(i,0);
	return (0);
}
