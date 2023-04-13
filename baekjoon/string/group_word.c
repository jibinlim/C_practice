#include <stdio.h>
#include <string.h>

int ch_num(char *temp)
{
	int len;
	len = strlen(temp);
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (temp[i] == temp[j])
				return (0);
		}
	}
	return (1);
}


int main()
{
	int	n;
	scanf("%d", &n);
	char	word[n][101];
	char	temp[26];
	int	len;
	int	k;
	int	j;
	int	count;

	count = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%s", word[i]);
		len = strlen(word[i]);
		temp[0] = word[i][0];
		k = 1;
		j = 0;
		while (word[i][j])
		{
			while (temp[k - 1] == word[i][j])
				j++;
			if (temp[k - 1] != word[i][j])
			{
				temp[k] = word[i][j];
				k++;
				j++;
			}
		}
		temp[k] = 0;
		if (ch_num(temp))
			count++;
	}
	printf("%d", count);
	return (0);
}
