#include <stdio.h>

int main(void)
{
	char sub[51];
	float grade;
	float result = 0.0;
	char g[3];
	float x;
	float j = 0.0;

	for(int i = 0; i < 20; i++)
	{
		scanf("%s",sub);
		scanf("%f",&grade);
		scanf("%s",g);
		if(g[0] == 'P')
			continue;
		x = 4.0;
		x -= g[0] - 'A';
		if(g[0] == 'F')
			x = 0.0;
		if(g[1] == '+')
			x += 0.5;
		result += x * grade;
		j += grade;
	}
	printf("%lf",result / j);
	return (0);
}
