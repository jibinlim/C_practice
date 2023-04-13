#include <stdio.h>

void hansu(int nb)
{
	int	i;
	int	count;
	int	x;
	int	y;

	i = 1;
	count = 0;
	x = 0;
	y = 0;
	while (i <= nb)
	{
		if ( i < 100)
		{
			count++;
		}
		else if(i < 1000)
		{
			x = i % 100;
			if((i / 100 - x / 10) == (x / 10 - x % 10))
				count++;
		}
		else if(i < 1000)
		{
			x = i % 1000;
			y = x % 100;
			if(((i / 1000 - x / 100) == (x / 100 - y / 10)) && ((x / 100 - y / 10) == (y / 10 - y % 10)))
				count++;
		}
		i++;
	}
	printf("%d\n", count);
	return ;
}
int main()
{
	int	nb;
	scanf("%d", &nb);
	hansu(nb);
	return (0);
}
