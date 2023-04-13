#include <stdio.h>
#include <stdlib.h>
int n;
int *queen;
int count = 0;
int **visit;

int avail(int x,int y)
{
	for(int i = 0; i < x; i++)
		if(queen[i] == y || queen[i] - y == x - i || queen[i] - y == i - x)
			return (0);
	return 1;
}


void dfs(int a)
{
	if(a == n)
		count++;
	else
		for(int i = 0; i < n; i++)
		{
			if(avail(a,i) == 1)
			{
				queen[a] = i;
				dfs(a + 1);
			}
		}

}


int main(void)
{
	scanf("%d",&n);

	queen = (int *) malloc (sizeof(int ) * n);
	dfs(0);

	free(queen);

	printf("%d\n",count);
	return (0);
}
