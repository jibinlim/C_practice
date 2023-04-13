#include <stdio.h>

long long sol(unsigned int a, unsigned int b, unsigned int c)
{
	long long n;

	if(b == 1)
		return a % c;
	n = sol(a % c, b / 2, c);
	if(b % 2 == 0)
		return n % c * n % c % c;
	else
		return n % c * n % c * a % c % c;
}

int main(void)
{
	unsigned int a,b,c;
	unsigned long long result;

	scanf("%d %d %d",&a,&b,&c);
	result = sol(a,b,c);

	printf("%lld", result);
	return (0);
}
