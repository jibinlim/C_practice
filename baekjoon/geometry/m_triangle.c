#include <stdio.h>

int main(void)
{
	int x[3];
	int sum = 0;
	int count = 0;
	for(int i = 0; i < 3; i++)
	{
		scanf("%d",&x[i]);
		sum += x[i];
	}
	if(sum == 180)
	{
		for(int i = 0; i < 3; i++)
			for(int j = i + 1; j < 3; j++)
				if(x[i] == x[j])
					count++;
		if(count == 3)
			printf("Equilateral\n");
		else if(count == 1)
			printf("Isosceles\n");
		else
			printf("Scalene\n");
	}
	else
		printf("Error\n");
	return (0);
}
