#include <stdio.h>

int main(void)
{
	int t;
	scanf("%d",&t);
	for(int a = 0; a < t; a++)
	{
		int c;
		scanf("%d",&c);
		int rest[4] = {0,};

		rest[0] = c / 25;
		c %= 25;
		rest[1] = c / 10;
		c %= 10;
		rest[2] = c / 5;
		c %= 5;
		rest[3] = c;

		for(int i = 0; i < 4; i++)
			printf("%d ",rest[i]);
		printf("\n");
	}
	return (0);
}
