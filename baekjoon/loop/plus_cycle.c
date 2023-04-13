#include <stdio.h>

int main()
{
	int N;
	int count;
	int N_cpy;
	int	a;
	int	b;
	int temp;

	scanf("%d", &N);
	count = 0;
	N_cpy = N;

	a = N / 10;
	b = N % 10;

	temp = a;
	a = b;
	b = (temp + b) % 10;
	N = a * 10 + b;
	count ++;

	while (N != N_cpy)
	{
		a = N / 10;
		b = N % 10;
		temp = a;
		a = b;
		b = (temp + b) % 10;
		N = a * 10 + b;
		count ++;
	}

	printf("%d", count);

	return (0);
}
