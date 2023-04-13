#include <stdio.h>

int main(void)
{
	unsigned int s;
	scanf("%d",&s);

	int n = 0;
	unsigned long long sum = 0;
	while(sum <= s)
	{
		n++;
		sum += n;
	}
	n--;
	printf("%d",n);
	return (0);
}
