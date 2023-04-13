#include <stdio.h>

int main(void)
{
	int x[3];

	while(1)
	{
		int max = 0;
		int two = 0;
		int c = 0;
		for(int i = 0; i < 3; i++)
		{
			scanf("%d",&x[i]);
			if(max < x[i])
				max = x[i];
		}
		if(x[0] == 0 && x[1] == 0 && x[2] == 0)
			break;
		for(int i = 0; i < 3; i++)
		{
			if(max == x[i])
				c++;
			if(max != x[i] ||c > 1)
				two += x[i];
		}
		if(two <= max)
		{
			printf("Invalid\n");
			continue;
		}
		if(x[0] == x[1] && x[1] == x[2])
		{
			printf("Equilateral\n");
			continue;
		}
		else if(x[0] == x[1] || x[0] == x[2] || x[1] == x[2])
		{
			printf("Isosceles\n");
			continue;
		}
		else
		{
			printf("Scalene\n");
			continue;
		}
	}
	return (0);
}
