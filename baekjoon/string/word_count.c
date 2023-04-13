#include <stdio.h>
#include <stdlib.h>

int is_blank(char c)
{
	if (c == 32)
		return (1);
	return (0);
}

int main()
{
	char	*sen;
	sen = malloc (sizeof(char) * 1000001);
	scanf("%[^\n]", sen);
	int		word;
	int		i;

	word = 0;
	i = 0;
	while (sen[i])
	{
		while (is_blank(sen[i]) && sen[i])
			i++;
		if (!is_blank(sen[i]) && sen[i] != 0)
			word++;
		while (!is_blank(sen[i]) && sen[i])
			i++;
	}
	printf("%d", word);
	return(0);
}
