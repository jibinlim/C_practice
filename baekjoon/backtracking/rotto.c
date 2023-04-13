#include <stdio.h>
#include <stdlib.h>

int x[6];

void dfs(int a, int* r, int *visit, int c,int n)
{
	x[c] = r[a];
	if(c == 5)
	{
		for(int i = 0; i <= c; i++)
			printf("%d ",x[i]);
		printf("\n");
		return;
	}
	for(int i = a + 1; i < n; i++)
	{
		if(visit[i] == 0)
		{
			visit[i] = 1;
			dfs(i,r,visit,c + 1,n);
			visit[i] = 0;
		}
	}
}

int main(void)
{
	while(1)
	{
		int n;
		scanf("%d",&n);
		if(n == 0)
			break;
		int *r = (int *) malloc (sizeof(int) * n);

		for(int i = 0; i < n; i++)
			scanf("%d",&r[i]);

		int *visit = (int *) malloc (sizeof(int) * n);
		for(int i = 0; i < n; i++)
			visit[i] = 0;
		for(int i = 0; i < n; i++)
		{
			if(visit[i] == 0)
			{
				visit[i] = 1;
				dfs(i,r,visit,0,n);
				visit[i] = 0;
			}
		}
		printf("\n");
		free(visit);
		free(r);
	}
	return (0);
}
