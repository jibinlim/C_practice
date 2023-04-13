#include <stdio.h>
#include <stdlib.h>

int six_t(int t)
{
	int count = 0;
	while(t > 0)
	{
		if(t % 10 == 6)
			count++;
		else
			count = 0;
		if(count == 3)
			return (1);
		t /= 10;
	}
	return (0);
}

int main(void)
{
	int n;
	scanf("%d",&n);
	int t = 666;
	int j = 1;
	while(n > j)
	{
		t ++;
		if(six_t(t) == 1)
			j++;
	}
	printf("%d",t);
	return (0);
}
