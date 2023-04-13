#include <stdio.h>

int main(void)
{
	int x[3];
	int max = 0;

	for(int i = 0; i < 3; i++)
	{
		scanf("%d",&x[i]);
		if(max < x[i])
			max = x[i];
	}
	int c = 0;
	int two = 0;
	for(int i = 0; i < 3; i++)
	{
		if(max == x[i])
			c++;
		if(c > 1 || max != x[i])
			two += x[i];
	}
	while(max >= two)
		max--;
	printf("%d\n",max + two);
	return (0);
}
