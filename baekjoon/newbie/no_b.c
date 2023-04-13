#include <stdio.h>

int main(void)
{
	int x;
	scanf("%d",&x);

	if(x % 10 == 0)
	{
		x /= 10;
		x /= 10;
		if(x % 10 == 0)
			printf("20\n");
		else
			printf("%d\n",x + 10);
	}
	else
	{
		int a = x % 10;
		x /= 10;
		if(x % 10 == 0)
			printf("%d\n",a + 10);
		else
			printf("%d\n",a + x % 10);
	}
	return (0);
}
