#include <stdio.h>

int main(void)
{
	int n, m;
	scanf("%d %d",&n,&m);
	int a,b;
	int min1, min2;
	int sum = 0;

	for(int i = 0; i < m; i++)
	{
		scanf("%d %d",&a, &b);
		if(i == 0)
		{
			min1 = a;
			min2 = b;
		}
		else
		{
			if(a < min1)
				min1 = a;
			if(b < min2)
				min2 = b;
		}
	}
	if(min2 * 6 < min1)
		printf("%d",min2 * n);
	else
	{
		sum += (n / 6) * min1;
		if((n % 6) * min2 < min1)
			sum += (n % 6) * min2;
		else
			sum += min1;
		printf("%d",sum);
	}
	return (0);
}
