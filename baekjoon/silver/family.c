#include <stdio.h>
#include <stdlib.h>

int *visit;
int n;
int x;
int m;
int **fam;
int cousine;

void dfs(int me, int count)
{
	visit[me] = 1;
	if(me == cousine - 1)
	{
		x = count;
		return ;
	}
	else
	{
		for(int i = 0; i < n; i++)
			if(fam[me][i] == 1 && visit[i] == 0)
			{
				fam[me][i] = 0;
				fam[i][me] = 0;
				dfs(i, count + 1);
			}
	}
}

int main(void)
{
	int me;
	scanf("%d",&n);
	visit = (int *) malloc (sizeof(int) * n);
	fam = (int **) malloc (sizeof(int *) * n);
	scanf("%d %d",&me,&cousine);
	for(int i = 0; i < n; i++)
	{
		visit[i] = 0;
		fam[i] = (int *) malloc (sizeof(int) * n);
		for(int j = 0; j < n; j++)
			fam[i][j] = 0;
	}
	scanf("%d",&m);
	int a,b;

	for(int i = 0; i < m; i++)
	{
		scanf("%d %d",&a,&b);
		fam[a - 1][b - 1] = 1;
		fam[b - 1][a - 1] = 1;
	}

	dfs(me - 1, 0);
	if(x == 0)
		x = -1;
	printf("%d",x);
	for(int i = 0; i < n; i++)
		free(fam[i]);
	free(visit);
	free(fam);
	
	return (0);
}
