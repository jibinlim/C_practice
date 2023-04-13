#include <stdio.h>
#include <stdlib.h>

int min = 1000000001;
int max = -1000000001;
int n;
int *num;
int *op;
int *cp;
int visit[4] = {0,};

void dfs(int a, int c, int p,int x)
{
	visit[p]++;
	if(p == 0)
		x += num[a + 1];
	else if(p == 1)
		x -= num[a + 1];
	else if(p == 2)
		x *= num[a + 1];
	else
		x /= num[a + 1];
	if(c == n - 1)
	{
		if(x > max)
			max = x;
		if(x < min)
			min = x;
	}
	else
	{
		for(int i = 0; i < 4; i++)
			if(visit[i] < op[i])
				dfs(a + 1, c + 1, i, x);
	}
	visit[p]--;
}


int main(void)
{
	scanf("%d",&n);
	num = (int *) malloc (sizeof(int) * n);
	for(int i = 0; i < n; i++)
		scanf("%d",&num[i]);
	op = (int *) malloc (sizeof(int) * 4);
	for(int i = 0; i < 4; i++)
		scanf("%d",&op[i]);
	for(int i = 0; i < 4; i++)
		if(op[i] > 0)
			dfs(0,1,i,num[0]);
	printf("%d\n%d\n",max,min);
	free(num);
	free(op);
	return (0);
}
