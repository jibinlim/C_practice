#include <stdio.h>

int main()
{
	char	a[100];
	scanf("%s" ,a);
	int		i;
	char	c;

	c = 'a';
	while (c <= 'z')
	{
		i = 0;
		while (c != a[i] && a[i])
		{
			i++;
			if (a[i] == 0)
			{
				if (c == 'z')
				{
					printf("-1");
					c++;
					break;
				}
				printf("-1 ");
				c++;
			}
		}
		if (c == a[i])
		{
			if (c == 'z')
			{
				printf("%d", i);
				c++;
				break;
			}
			printf("%d ", i);
			c++;
		}
	}
	return (0);
}
