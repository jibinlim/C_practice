#include <stdio.h>

int main()
{
	int v;
	int a;
	int b;
	scanf("%d %d %d",&a,&b,&v);
	int c;
	if (a >= v)
	{
		c = 1;
		printf("%d",c);
		return(0);
	}
	c = (v - b) / (a - b);

	if(a*c-b*c+b != v)
		c++;

	printf("%d",c);
	return (0);
}
