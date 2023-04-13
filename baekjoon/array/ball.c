#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n,m;
	scanf("%d %d",&n,&m);
	int *b;
	b = (int *) malloc (sizeof(int) * n);
	int x,y,z;
	for(int i = 0; i < m; i++)
	{
		scanf("%d %d %d",&x,&y,&z);
		for(int j = x - 1; j <= y - 1; j++)
			b[j] = z;
	}
	for(int i = 0; i < n; i++)
		printf("%d ",b[i]);
	free(b);
	return (0);
}
