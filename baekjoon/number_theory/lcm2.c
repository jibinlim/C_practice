#include <stdio.h>

unsigned long long gcd(unsigned long long a, unsigned long long b)
{
	if(a % b == 0)
		return b;
	else
		return gcd(b, a % b);
}

int main(void)
{
	unsigned long long a,b;
	scanf("%lld %lld",&a,&b);

	unsigned long long g = gcd(a,b);
	printf("%lld\n",g * (a / g) * (b / g));
	return (0);
}
