#include <stdio.h>

int main(void)
{
	int mon[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	char day[8][4] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
	int x,y;
	int d = 0;
	scanf("%d %d",&x,&y);
	for(int i = 1; i < x; i++)
		d += mon[i - 1];
	d += y;
	printf("%s",day[d % 7]);
	return (0);
}
