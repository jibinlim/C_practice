#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d",&n);

	unsigned long long x = 1;
	for(int i = 0; i < 3; i++)
		x *= n;
	printf("%lld\n3",x);
	return (0);
}
