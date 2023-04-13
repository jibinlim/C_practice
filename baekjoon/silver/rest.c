#include<stdio.h>

int main(void)
{
	int n;
	scanf("%d",&n);
	int count = 0;
	int m[6] = {500,100,50,10,5,1};

	n = 1000 - n;

	for(int i = 0; i <= 5; i++)
	{
		count += n / m[i];
		n %= m[i];
	}
	printf("%d",count);
	return (0);
}
