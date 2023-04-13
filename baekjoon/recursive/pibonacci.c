#include<stdio.h>

int pibonacci(int n)
{
	if(n < 2)
		return (n);
	return (pibonacci(n-2) + pibonacci(n-1));
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", pibonacci(n));
	return (0);
}
