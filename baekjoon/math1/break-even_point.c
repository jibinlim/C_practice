#include <stdio.h>

int main(void)
{
	int	a;
	int	b;
	int	c;
	scanf("%d %d %d", &a, &b, &c);
	int	n;
	long long	x;
	if (b >= c)
	{
		printf("-1");
		return (0);
	}
	n = a / (c - b) + 1;
	printf("%d", n);
	return (0);
}
