#include <stdio.h>

int main(void)
{
	int h,m,s;
	scanf("%d %d %d",&h,&m,&s);
	int d;
	scanf("%d",&d);
	s += d;
	if(s >= 60)
	{
		m += s / 60;
		s %= 60;
	}
	if(m >= 60)
	{
		h += m / 60;
		m %= 60;
	}
	if(h >= 24)
	{
		h %= 24;
	}
	printf("%d %d %d\n",h,m,s);
	return (0);
}
