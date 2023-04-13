#include <stdio.h>

int main()
{
	int	total;
	int	N;
	int	a;
	int	b;
	int	g;

	g = 0;
	scanf("%d", &total);
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &a, &b);
		g += a * b;
	}
	if (g == total)
		printf("Yes");
	else
		printf("No");
	return (0);
}
