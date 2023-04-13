#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int n;
	int k;
	int temp;

	int *a;

	scanf("%d %d",&n,&k);
	a = (int *) malloc (sizeof(int) * n);
	for(int i = 0; i < n; i++)
		scanf("%d",&a[i]);
	for(int i = 0; i < n - 1; i++)
		for(int j = i + 1; j < n; j++)
			if(a[i] < a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
	printf("%d\n",a[k-1]);
	free(a);
	return (0);
}
