#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	char a[n];
	scanf("%s",a);
	int i = 0;
	int sum = 0;
	while(i < n)
	{
		sum += a[i] - '0';
		i++;
	}
	printf("%d",sum);
	return (0);
}
