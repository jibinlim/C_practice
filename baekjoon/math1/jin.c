#include <stdio.h>

int main(void)
{
	char n[101];
	int b;
	scanf("%s",n);
	scanf("%d",&b);

	int res = 0;
	for(int i = 0; n[i]; i++)
	{
		if(n[i] >= '0' && n[i] <= '9')
			res = (res * b) + (n[i] - '0');
		if(n[i] >= 'A' && n[i] <= 'Z')
			res = (res * b) + (n[i] - 'A' + 10);
	}
	printf("%d",res);
	return (0);
}
