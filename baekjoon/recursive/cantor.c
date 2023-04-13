#include <stdio.h>
#include <stdlib.h>


void blank(int n)
{
	while(n > 0)
	{
		printf(" ");
		n--;
	}
}

void can(int n)
{
	if(n == 1)
	{
		printf("-");
		return;
	}
	can(n / 3);
	blank(n / 3);
	can(n / 3);
}


int main(void)
{
	int n;
	while(scanf("%d",&n) != EOF)
	{
		int x = 1;
		while(n > 0)
		{
			x *= 3;
			n--;
		}
		can(x);
		printf("\n");
	}
	return (0);
}
