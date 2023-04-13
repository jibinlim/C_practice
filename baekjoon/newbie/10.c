#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d",&n);
	int count = 0;
	int x;
	for(int i = 0; i < 5; i++)
	{
		scanf("%d",&x);
		if(x == n)
			count++;
	}
	printf("%d\n",count);
	return (0);
}
