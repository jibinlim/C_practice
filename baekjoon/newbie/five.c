#include <stdio.h>

int five(int n)
{
	int x = 1;
	for(int i = 0; i < 5; i++)
		x *= n;
	return x;
}

int main(void)
{
	int n;
	scanf("%d",&n);

	int sum = 0;
	while(n > 0)
	{
		sum += five(n % 10);
		n /= 10;
	}
	printf("%d",sum);
	return (0);
}
