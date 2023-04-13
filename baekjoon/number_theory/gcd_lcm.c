#include <stdio.h>

int main(void)
{
	int a;
	int b;
	scanf("%d %d",&a,&b);

	int gcd;
	int lcm;

	if(a > b)
		gcd = a - 1;
	else if(a < b)
		gcd = b - 1;
	else
		gcd = a;
	while(a % gcd != 0 || b % gcd != 0)
		gcd--;
	lcm = (a / gcd) * (b / gcd) * gcd;
	printf("%d\n%d",gcd,lcm);
	return (0);
}
