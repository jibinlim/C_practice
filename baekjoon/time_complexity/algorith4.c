#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d",&n);
	unsigned long long sum = 0;
	n--;
	while(n > 0)
	{
		sum += n;
		n--;
	}
	printf("%lld\n2",sum);
	return (0);
}
