#include <stdio.h>

int main(void)
{
	int n;
	int sum = 0;
	int min = 101;

	for(int i = 0; i < 7; i++)
	{
		scanf("%d",&n);
		if(n % 2 == 1)
		{
			sum += n;
			if(min > n)
				min = n;
		}
	}

	if(min == 101)
		printf("-1\n");
	else
		printf("%d\n%d\n",sum,min);
	return (0);
}
