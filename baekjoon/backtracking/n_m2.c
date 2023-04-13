#include<stdio.h>

int n,m;
int s[9];

void dfs(int a,int c)
{
	s[c] = a;
	if(c == m - 1)
	{
		for(int i = 0; i < m; i++)
			printf("%d ",s[i]);
		printf("\n");
		return ;
	}
	for(int i = a + 1; i <= n; i++)
		dfs(i, c + 1);
}


int main(void)
{
	scanf("%d %d",&n,&m);

	for(int i = 1; i <= n; i++)
		dfs(i,0);
	return (0);
}
