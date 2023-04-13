#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d",&n);
	int stack[10001];
	int f = 0;
	for(int a = 0; a < n; a++)
	{
		char s[55];
		int x;
		scanf("%s",s);
		if(s[0] == 'p')
		{
			if(s[1] == 'u')
			{
				scanf("%d",&x);
				stack[f] = x;
				f++;
			}
			else
			{
				if(f - 1 < 0)
					printf("-1\n");
				else
					printf("%d\n",stack[f - 1]);
				f--;
				if(f < 0)
					f = 0;
			}
		}
		if(s[0] == 't')
		{
			if(f - 1 < 0)
				printf("-1\n");
			else
				printf("%d\n",stack[f - 1]);
		}
		if(s[0] == 's')
		{
			printf("%d\n",f);
		}
		if(s[0] == 'e')
		{
			if(f == 0)
				printf("1\n");
			else
				printf("0\n");
		}
	}
	return (0);
}
