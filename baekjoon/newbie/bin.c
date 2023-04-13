#include <stdio.h>

int main(void)
{
	int t;
	scanf("%d",&t);

	for(int i = 0; i < t; i++)
	{
		int n;
		scanf("%d",&n);
		int t = 0;
		while(n > 0)
		{
			if(n % 2 == 1)
				printf("%d ",t);
			n /= 2;
			t++;
		}
		printf("\n");
	}
	return (0);
}
