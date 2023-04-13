#include <stdio.h>

unsigned long long gcd(unsigned long long a,unsigned long long b)
{
	if(b == 0)
		return (a);
	return gcd(b,a%b);
}

int main(void)
{
	unsigned long long a;
	unsigned long long b;
	scanf("%lld %lld",&a,&b);

	unsigned long long c = gcd(a,b);

	for(int i = 0; i < c; i++)
		printf("1");
	return (0);
}
