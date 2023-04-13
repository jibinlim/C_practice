#include <stdio.h>

int main()
{
	int x;
	scanf("%d",&x);
	int a = 1;
	int b = 1;
	int sum = 2;

	while(x > 1)
	{
		if(a == 1)
		{
			sum++;
			b = sum - 1;
			x--;
		}
		while(b != 1 && x > 1)
		{
			a++;
			b--;
			x--;
		}
		if (x <= 1)
			break;
		if(b == 1)
		{
			sum++;
			a = sum - 1;
			x--;
		}
		while(a != 1 && x > 1)
		{
			a--;
			b++;
			x--;
		}
	}
	printf("%d/%d",a,b);
	return (0);
}
