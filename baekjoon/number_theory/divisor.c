#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d",&n);
	int a[10000];
	int i = 0;
	int x = 1;
	while(n >= x)
	{
		if(n % x == 0)
		{
			a[i] = x;
			i++;
		}
		x++;
	}
	int k;
	scanf("%d",&k);
	if(k > i)
		a[k - 1] = 0;
	printf("%d\n",a[k - 1]);
	return (0);
}

