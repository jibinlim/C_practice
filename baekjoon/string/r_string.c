#include <stdio.h>

int main()
{
	int		t;
	scanf("%d", &t);
	int		r[t];
	char	s[t][21];
	int		x;
	int		j;
	for (int i = 0; i < t; i++)
	{
		scanf("%d", &r[i]);
		scanf("%s", s[i]);
	}
	for (int i = 0; i < t; i++)
	{
		j = 0;
		while (s[i][j])
		{
			x = r[i];
			if (x >= 9)
				x = 8;
			while (x != 0)
			{
				printf("%c", s[i][j]);
				x--;
			}
			j++;
		}
		printf("\n");
	}
	return (0);
}
