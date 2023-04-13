#include <stdio.h>

int main()
{
	int t;
	scanf("%d",&t);
	int h;
	int w;
	int n;
	int r[t];
	int x;
	int y;
	for(int i = 0 ; i < t ; i++)
	{
		scanf("%d %d %d",&h,&w,&n);
		x = 0;
		y = 1;
		while(n > 0)
		{
			n--;
			if(x == h)
			{
				y++;
				x = 0;
			}
			x++;
		}
		r[i] = x*100+y;
	}
	for(int i = 0; i < t; i++)
		printf("%d\n",r[i]);
	return(0);
}
