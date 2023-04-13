#include <stdio.h>
#include <string.h>

int main()
{
	char	word[150];
	scanf("%s", word);
	int	i;
	int	count;

	i = 0;
	count = strlen(word);
	while (word[i])
	{
		if (word[i] == 'c')
		{
			i++;
			if (word[i] == '=' || word[i] == '-')
				count--;
		}
		else if (word[i] == 'd')
		{
			i++;
			if (word[i] == '-')
				count--;
			else if (word[i] == 'z')
			{
				i++;
				if (word[i] == '=')
					count -= 2;
			}
		}
		else if (word[i] == 'l' || word[i] == 'n')
		{
			i++;
			if (word[i] == 'j')
				count--;
		}
		else if (word[i] == 's' || word[i] == 'z')
		{
			i++;
			if (word[i] == '=')
				count--;
		}
		else
			i++;
	}
	printf("%d", count);
	return (0);
}
