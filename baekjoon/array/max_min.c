#include <stdio.h>

int main()
{
	int	N;
	int	max;
	int	min;

	scanf ("%d", &N);
	int arr[N];
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	max = arr[0];
	min = arr[0];
	for( int i = 0; i < N; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	printf("%d %d", min, max);
	return (0);
}
