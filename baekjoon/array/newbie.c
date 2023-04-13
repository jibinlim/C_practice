#include<stdio.h>

int main()
{
	int	C;
	scanf("%d", &C);
	int	arr[C];
	float	x[C];
	int	sum;
	float	result
	int	count;

	result = 0.0;
	for (int i = 0; i < C; i++)
	{
		scanf("%d", &arr[i]);
		int ar[arr[i]];
		sum = 0;
		for (int j = 0; j < arr[i]; j++)
		{
			scanf("%d", &ar[j]);
			sum += ar[j];
		}
		result = (float) sum / arr[i];
		x[i] = result;
		count = 0;
		for (int j = 0; j < arr[i]; j++)
		{
			if(x[i] < ar[j])
				count++;
		}
		x[i] = (float)count / arr[i] * 100;
	}

	for (int i = 0; i < C; i++)
	{
		printf("%.3lf%%", x[i]);
		printf("\n");
	}
	return (0);
}
