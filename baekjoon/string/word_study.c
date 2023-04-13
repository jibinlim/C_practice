#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char *word;
	word = malloc (sizeof(char) * 1000001);
	scanf("%s",word);
	int *count;
	int i;
	int j;
	int max;
	int len;

	len = strlen(word);
	count = malloc (sizeof(int) * len);
	for(i = 0; i < len ; i++)
	{
		if(word [i] >= 97 && word[i] <= 122)
		{
			word[i] -= 32;
		}
		count[i] = 0;
		for(j = i + 1; j < len ; j++)
		{
			if(word[i] == word[j] || word[i] == (word[j] - 32))
				count[i]++;
		}
	}
	max = -1;
	for (i = 0; i < len ; i++)
	{
		if(max < count[i])
		{
			max = count[i];
			j = i;
		}
		else if( max == count[i])
		{
			printf("?");
			return (0);
		}
	}
	printf("%c",word[j]);
	return (0);
}
