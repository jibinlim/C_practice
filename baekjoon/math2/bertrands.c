#include <stdio.h>
#include <stdlib.h>

int is_prime(int m,int n)
{
	int arr[n+1];
	int count = 0;

	for(int i = 0; i < n+1; i++)
		arr[i] = 0;

	arr[0] = 1;
	arr[1] = 1;

	for(int i = 2; i <= n; i++)
	{
		if(arr[i] == 1)
			continue;
		for(int j=2*i; j<=n ; j+=i)
			arr[j] = 1;
	}
	for(int i = m+1; i <= n; i++)
		if(!arr[i]) count++;
	return (count);
}

int main(void)
{
	int m = 1;
	int *x;
	int count = 0;
	int i = 0;
	x = (int *) malloc (sizeof(int) * 1000);
	while(m != 0)
	{
		scanf("%d",&m);
		if(m == 0)
			break;
		count++;
		x[i] = is_prime(m,2*m);
		i++;
	}
	for(int i = 0; i < count; i++)
		printf("%d\n",x[i]);
	free(x);
	return (0);
}
