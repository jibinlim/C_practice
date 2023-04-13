#include <stdio.h>

int main(void)
{
	int x;
	scanf("%d",&x);
	int stick[7] = {1,2,4,8,16,32,64};
	int count = 0;
	int x_a = 0;
	int j = 0;
	int x_t = x;

	int min;

	while(x_a != x_t)
	{
		min = 64;
		for(int i = 0; i < 7; i++)
			if(x - stick[i] < min && x - stick[i] >= 0)
			{
				min = x - stick[i];
				j = i;
			}
		x -= stick[j];
		x_a += stick[j];
		count++;
	}
	printf("%d",count);
	return (0);
}
		
