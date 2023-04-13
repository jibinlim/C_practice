#include <stdio.h>
#include <string.h>

int main(void)
{
	int t;
	scanf("%d",&t);

	for(int i = 0; i < t; i++)
	{
		int d;
		char x[81];
		scanf("%d",&d);
		scanf("%s",x);
		int len = strlen(x);
		for(int j = 0; j < len; j++)
		{
			if(d - 1 == j)
				continue;
			printf("%c",x[j]);
		}
		printf("\n");
	}
	return (0);
}
