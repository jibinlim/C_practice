#include <stdio.h>

int gcd(int a,int b)
{
	if(a % b == 0)
		return b;
	else
		return gcd(b, a % b);
}

int main(void)
{
	int n;
	int g[100001];
	int x[100001];
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&g[i]);
		if(i >= 1)
			x[i - 1] = g[i] - g[i - 1];
	}
	int gc = x[0];
	for(int i = 1; i < n - 1; i++)
		gc = gcd(gc,x[i]);
	int count = 0;
	int a = g[0] + gc;
	int k = 1;
	while(g[n - 1] > a)
	{
		while(a != g[k])
		{
			a += gc;
			count++;
		}
		if(a == g[k])
		{
			k++;
			a += gc;
		}
	}
	printf("%d\n",count);
	return (0);
}
