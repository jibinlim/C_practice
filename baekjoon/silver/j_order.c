#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	scanf("%d",&n);
	int count[2002] = {0,};
	int *a = (int *) malloc (sizeof(int) * n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d",a + i);
		count[a[i] + 1000]++;
	}
	for(int i = 0; i < 2001; i++)
		if(count[i] > 0)
			printf("%d ",i - 1000);
	free(a);
	return (0);
}
