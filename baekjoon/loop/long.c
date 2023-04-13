#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d",&n);

	if(n % 4 == 0)
		n--;
	n /= 4;
	while(n >= 0)
	{
		printf("long ");
		n--;
	}
	printf("int");
	return (0);
}
