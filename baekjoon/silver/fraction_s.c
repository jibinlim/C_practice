#include <stdio.h>

unsigned long long gcd(int a,int b)
{
	if(a % b == 0)
		return (b);
	else
		return (gcd(b,a%b));
}

int main(void)
{
	int a_j,a_m;
	int b_j,b_m;
	unsigned long long g;
	unsigned long long c_j,c_m;

	scanf("%d %d",&a_j,&a_m);
	scanf("%d %d",&b_j,&b_m);

	g = gcd(a_m,b_m);
	c_m = g * (a_m / g) * (b_m / g);
	c_j = (c_m / a_m) * a_j + (c_m / b_m) * b_j;
	g = gcd(c_j,c_m);
	c_m /= g;
	c_j /= g;

	printf("%lld %lld",c_j,c_m);
	return (0);
}
