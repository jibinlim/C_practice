#include <stdio.h>
#include <stdlib.h>

int gcd(int a,int b)
{
	if(b == 0)
		return (a);
	else
		return gcd(b,a % b);
}

int main(void)
{
	int n;
	scanf("%d",&n);

	int *r;
	int *g;

	r = (int *) malloc (sizeof(int) * n);
	g = (int *) malloc (sizeof(int) * n);

	for(int i = 0; i < n; i++)
	{
		scanf("%d",r+i);
		if(i != 0)
			g[i] = gcd(r[i],r[0]);
	}

	for(int i = 1; i < n; i++)
		printf("%d/%d\n",r[0]/g[i],r[i]/g[i]);
	free(r);
	free(g);
	return (0);
}
