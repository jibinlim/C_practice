#include <stdio.h>

int main()
{
	int	N;
	scanf("%d", &N);
	char	OX[N][80];
	int	arr[N];
	int	count;
	int	sum;
	int	a;

	for (int i = 0; i < N; i++)
	{
		scanf("%s", OX[i]);
	}
	for (int i = 0; i < N; i++)
	{
		a = 0;
		sum = 0;
		count = 0;
		while(OX[i][a])
		{
			if (OX[i][a] == 'O')
			{
				count += 1;
				sum += count;
			}
			if (OX[i][a] == 'X')
			{
				count = 0;
			}
			a++;
		}
		arr[i] = sum;
	}
	for (int i = 0; i < N; i++)
	{
		printf("%d\n", arr[i]);
	}
	return (0);
}
