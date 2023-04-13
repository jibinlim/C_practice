#include <stdio.h>

int main(void)
{
	int x,y,w,h;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	int min = y - 0;
	if(min > w - x)
		min = w - x;
	if(min > x - 0)
		min = x - 0;
	if(min > h - y)
		min = h - y;
	printf("%d",min);
	return (0);
}
