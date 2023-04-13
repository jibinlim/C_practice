#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	int m;

	scanf("%d %d",&n,&m);

	int *a;
	int max = 0;

	a = (int *) malloc (sizeof(int) * n);

	for(int i = 0; i < n; i++)
		scanf("%d",&a[i]);
	for(int i = 0; i < n -2 ; i++)
		for(int j = i + 1 ; j < n - 1; j++)
			for(int k = j + 1; k < n; k++)
				if(max < a[i]+a[j]+a[k] && a[i]+a[j]+a[k] <= m)
					max = a[i] + a[j] + a[k];
	printf("%d\n",max);
	return (0);
	free(a);
}
