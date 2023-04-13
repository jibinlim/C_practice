#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n,m;
	scanf("%d %d",&n,&m);
	int *b;
	b = (int *) malloc (sizeof(int) * (n + 1));
	for(int i = 1; i <= n; i++)
		b[i] = i;
	int x,y;
	for(int i = 0; i < m; i++)
	{
		scanf("%d %d",&x,&y);
		int temp = b[x];
		b[x] = b[y];
		b[y] = temp;
	}

	for(int i = 1; i <= n; i++)
		printf("%d ",b[i]);
	free(b);
	return (0);
}
