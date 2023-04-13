#include <stdio.h>

int main()
{
	int	max;
	int	N;
	int	arr[9];
	int	j;

	N = 9;
	for(int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	max = arr[0];

	for (int i = 0; i < N; i++)
	{
		if (max <= arr[i])
		{
			max = arr[i];
			j = i + 1;
		}
	}

	printf("%d\n%d", max, j);
	return (0);
}
