#include <stdio.h>

int main(void)
{
	int n,b;
	scanf("%d %d",&n,&b);

	char x[101];
	int i = 0;
	while(n > 0)
	{
		if(n % b >= 0 && n % b <= 9)
			x[i] = n % b + '0';
		else if(n % b >= 10 && n % b < b)
			x[i] = n % b - 10 + 'A';
		i++;
		n /= b;
	}

	for(int j = i - 1; j >= 0; j--)
		printf("%c",x[j]);
	return (0);
}
