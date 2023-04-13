#include <stdio.h>

int main(void)
{
	long long a,b;
	long long sum = 0;
	scanf("%lld %lld",&a,&b);
	if(a >= 0 && b >= 0 || a <= 0 && b >= 0 || a >= 0 && b <= 0)
	{
		if(a > b)
		{
			if((a - b) % 2 == 1)
				sum = (a + b) * ((a - b + 1) / 2);
			else
				sum = (a + b) * ((a - b) / 2) + (a + b) / 2;
		}
		else
		{
			if((b - a) % 2 == 1)
				sum = (a + b) * ((b - a + 1) / 2);
			else
				sum = (a + b) * ((b - a)/ 2) + (a + b) / 2;
		}
	}
	else if(a < 0 && b < 0)
	{
		a *= -1;
		b *= -1;
		if(a > b)
		{
			if((a - b) % 2 == 1)
				sum = (a + b) * ((a - b + 1) / 2);
			else
				sum = (a + b) * ((a - b) / 2) + (a + b) / 2;
		}
		else
		{
			if((b - a) % 2 == 1)
				sum = (a + b) * ((b - a + 1) / 2);
			else
				sum = (a + b) * ((b - a) / 2) + (a + b) / 2;
		}
		sum *= -1;
	}

	printf("%lld\n",sum);
	return (0);
}
