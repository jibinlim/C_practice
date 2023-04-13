#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	int m;
	int i = 0;

	while(1)
	{
		scanf("%d %d",&n, &m);
		if(n == 0 || m == 0)
			break;
		if(n % m == 0)
			printf("multiple\n");
		else if(m % n == 0)
			printf("factor\n");
		else
			printf("neither\n");
		i++;
	}

	return (0);
}
