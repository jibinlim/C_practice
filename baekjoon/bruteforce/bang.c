#include <stdio.h>


int main(void)
{
	int x1,y1,h1,x2,y2,h2;
	scanf("%d %d %d %d %d %d", &x1, &y1, &h1, &x2, &y2, &h2);
	int f = 0;
	for(int i = -999; i < 1000; i++)
	{
		for(int j = -999; j < 1000; j++)
		{
			if(x1 * i + y1 * j == h1)
			{
				if(x2 * i + y2 * j == h2)
				{
					printf("%d %d",i,j);
					f = 1;
					break;
				}
			}
		}
		if(f == 1)
			break;
	}
	return (0);
}

