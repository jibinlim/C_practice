#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d",&n);

	int count = 1;
	int sec = 0;
	while(n > 0)
	{
		n -= count;
		count++;
		if(n < count)
			count = 1;
		sec++;
	}
	printf("%d\n",sec);
	return (0);
}

