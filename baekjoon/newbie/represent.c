#include <stdio.h>

int main(void)
{
	int a;
	int x[1001] = {0,};
	int sum = 0;

	for(int i = 0; i < 10; i++)
	{
		scanf("%d",&a);
		sum += a;
		x[a]++;
	}
	int max = 0;
	int max_j;

	for(int i = 10; i <= 1000; i += 10)
		if(max < x[i])
		{
			max = x[i];
			max_j = i;
		}
	printf("%d\n%d\n",sum / 10, max_j);
	return (0);
}
