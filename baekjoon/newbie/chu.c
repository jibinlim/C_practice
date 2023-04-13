#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	scanf("%d",&n);

	int *arr = (int *) malloc (sizeof(int) * n);
	int c = 0;
	int b = 0;
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&arr[i]);
		if(i == 1)
		{
			c = arr[1] - arr[0];
			b = arr[1] / arr[0];
		}
	}
	int f = 0;
	if(arr[1] + c == arr[2])
		f = 1;
	if(f == 0)
		printf("%d\n",arr[n - 1] * b);
	else
		printf("%d\n",arr[n - 1] + c);
	free(arr);
	return (0);
}
