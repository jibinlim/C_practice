#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	scanf("%d",&n);

	int *a;
	int *b;

	a = (int *) malloc (sizeof(int) * n);
	b = (int *) malloc (sizeof(int) * n);

	int count = 1;

	for(int i = 0; i < n; i++)
		scanf("%d %d",a + i, b + i);
	for(int i = 0; i < n; i++)
	{
		count = 1;
		for(int j = 0; j < n; j++)
		{
			if((a[i] < a[j]) && (b[i] < b[j]))
					count++;
		}
		if(i < n - 1)
			printf("%d ", count);
		else
			printf("%d", count);
	}
	free(a);
	free(b);
	return (0);
}
