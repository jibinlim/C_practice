#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	int a;
	a = 2;

	if (n == 1)
		a = 1;
	while(n != 1)
	{
		if(n % a == 0)
		{
			n /= a;
			printf("%d\n",a);
			a = 2;
		}
		else
			a++;
	}

	return (0);
}
