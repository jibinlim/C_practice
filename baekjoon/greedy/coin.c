#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	int k;
	int *a;
	int count = 0;

	scanf("%d %d",&n, &k);
	
	a = (int *) malloc (sizeof(int) * n);
	for(int i = 0; i < n; i++)
		scanf("%d",a+i);
	for(int i = n - 1; i >= 0; i--)
	{
		if(k / a[i] >= 1)
		{
			count += k / a[i];
			k %= a[i];
		}
	}
	free(a);
	printf("%d",count);
	return (0);
}
