#include <stdio.h>

int star(int x,int y)
{
	while(1)
	{
		if(((x % 3) == 1) && ((y % 3) == 1))
			return (1);
		if(x == 0 || y == 0)
			return (0);
		return star(x / 3, y / 3);
	}
}

int main(void)
{
	int n;
	scanf("%d",&n);
	int i,j;
	for (i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			if(star(i,j))
				printf(" ");
			else
				printf("*");
		}
		printf("\n");
	}

	return (0);
}
