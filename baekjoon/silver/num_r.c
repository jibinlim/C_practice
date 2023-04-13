#include <stdio.h>

int j(int n)
{
	int count = 0;
	while(n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int main(void)
{
	int n;
	scanf("%d",&n);
	int y = j(n);
	int count = 0;
	int t = 1;

	for(int i = 1; i < y; i++)
		t *= 10;
	count = (n - t + 1) * y;
	y--;
	while(y > 0)
	{
		count += (t - (t / 10)) * y;
		y--;
		t /= 10;
	}
	printf("%d",count);
	return (0);
}
