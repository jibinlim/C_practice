#include <stdio.h>

int count = 0;
int stack[10];

void dfs(int x,int c)
{
	stack[c] = x;
	if(c == 2)
	{
		for(int i = 0; i <= c; i++)
			printf("%d ",stack[i]);
		printf("\n");
		count++;
	}
	else
	{
		for(int i = 1; i <= 6; i++)
			dfs(i,c + 1);
	}
}

int main(void)
{
	for(int i = 1; i <= 6; i++)
		dfs(i,0);
	printf("%d\n",count);
	return (0);
}
