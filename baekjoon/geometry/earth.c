#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d",&n);
	int x,y;
	int x_min = 10001 ,x_max = -10001 ,y_min = 10001,y_max = -10001;

	for(int i = 0; i < n; i++)
	{
		scanf("%d %d",&x,&y);
		if(x < x_min)
			x_min = x;
		if(x > x_max)
			x_max = x;
		if(y < y_min)
			y_min = y;
		if(y > y_max)
			y_max = y;
	}
	printf("%d\n",(x_max - x_min) * (y_max - y_min));
	return (0);
}
