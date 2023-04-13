#include <stdio.h>

int main()
{
	int	max;
	int	N;
	float	result;

	max = 0;
	result = 0.0;
	scanf("%d", &N);
	int arr[N];

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
		if (max < arr[i])
			max = arr[i];
	}
	for (int i = 0; i < N; i++)
	{
		result += (float) arr[i] / max * 100;
	}
	printf("%lf", result/N);

	return (0);
}
