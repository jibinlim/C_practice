#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d",&n);
	int count = 0;
	int j = 0;

	while(n > 4)
	{
		if(n % 5 == 0)
		{
			count++;
			if(n % 25 == 0)
			{
				count++;
				if(n % 125 == 0)
					count++;
			}
		}
		n--;
	}

	printf("%d",count);
	return (0);
}
