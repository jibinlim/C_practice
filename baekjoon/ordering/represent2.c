#include <stdio.h>

int main(void)
{
	int arr[5];
	int sum;
	int med;
	int avg;
	int temp;

	sum = 0;
	for(int i = 0; i < 5 ; i++)
	{
		scanf("%d",&arr[i]);
		sum += arr[i];
	}
	avg = sum / 5;
	for(int i = 0; i < 4; i++)
		for(int j = i + 1; j < 5; j++)
			if(arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
	med = arr[2];
	printf("%d\n%d",avg,med);
	return (0);
}
