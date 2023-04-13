#include <stdio.h>

int main(void)
{
	int b[3];
	int min = 3000;
	int d[2];

	for(int i = 0; i < 3; i++)
	{
		scanf("%d",&b[i]);
		if(b[i] < min)
			min = b[i];
	}
	int sum = -50;
	sum += min;
	min = 3000;
	for(int i = 0; i < 2; i++)
	{
		scanf("%d",&d[i]);
		if(d[i] < min)
			min = d[i];
	}
	sum += min;
	printf("%d\n",sum);
	return (0);
}
