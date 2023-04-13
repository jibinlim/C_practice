#include <stdio.h>

int factorial(int n)
{
	int	result;

	result = 1;
	if (n == 0)
		return (result);
	return (n * factorial(n - 1));
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", factorial(n));
	return (0);
}
