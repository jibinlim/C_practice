#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int k;
	scanf("%d",&k);
	int *a;
	a = (int *) malloc (sizeof(int) * k);
	int sum = 0;
	int j = 0;

	for(int i = 0; i < k; i++)
	{
		scanf("%d",a+j);
		if(a[j] != 0)
			j++;
		else
			j--;
	}
	for(int i = 0; i < j; i++)
		sum += a[i];
	printf("%d",sum);
	free(a);
	return (0);
}
