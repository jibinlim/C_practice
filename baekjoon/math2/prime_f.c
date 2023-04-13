#include <stdio.h>
#include <stdlib.h>

int is_prime(int a)
{
	int n;
	n = 2;
	if(a <= 1)
		return (0);
	while(n != a)
	{
		if(a % n == 0)
			return (0);
		n++;
	}
	return (1);
}

int main(void)
{
	int n;
	scanf("%d",&n);
	int *a;
	int count = 0;

	a = (int *) malloc (sizeof(int) * n);

	for(int i = 0; i < n; i++)
	{
		scanf("%d",&a[i]);
		if(is_prime(a[i]))
			count++;
	}
	printf("%d\n",count);

	return (0);
}
