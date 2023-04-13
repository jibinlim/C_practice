#include <stdio.h>

int main(void)
{
	unsigned int a;

	int g;

	int m;
	scanf("%d",&g);
	int max = 0;
	int min = 2147483647;
	for(int i = 0; i < g; i++)
	{
		scanf("%d",&m);
		if(max < m)
			max = m;
		if(min > m)
			min = m;
	}
	printf("%d",max * min);
	return (0);
}
