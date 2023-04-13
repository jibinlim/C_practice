#include <stdio.h>

long long fac(long long n)
{
	if(n <= 1)
		return 1;
	else
		return n * fac(n - 1);
}

int main(void)
{
	long long n;
	scanf("%lld",&n);

	printf("%lld\n",fac(n));
	return (0);
}
