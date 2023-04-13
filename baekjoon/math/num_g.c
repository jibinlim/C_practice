#include <stdio.h>

int main(void)
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	int g;
	int num[10];

	for(int i = 0; i < 10; i++)
		num[i] = 0;
	g = a * b * c;
	while(g > 0)
	{
		num[g%10]++;
		g /= 10;
	}
	for(int i = 0; i < 10; i++)
		printf("%d\n",num[i]);
	return (0);
}
