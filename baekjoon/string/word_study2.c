#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char *word;
	word = malloc (sizeof(char) * 1000001);
	scanf("%s",word);
	int len;
	len = strlen(word);
	int count[26];
	int x;
	int max = -1;
	for (int i = 0; i < len ; i++)
	{
		if(word[i] >= 'a' && word[i] <= 'z')
			word[i] -= 'a' - 'A';
	}
	for (int i = 0; i < 26; i++)
	{
		count[i] = 0;
	}
	for(int i = 0 ; i < len ; i++)
	{
		if(word[i] >= 'A' && word[i] <= 'Z')
		{
			x = (int) word[i] - 65;
			 count[x]++;
		}
	}
	for(int i= 0; i < 26 ; i++)
	{
		if(count[i] > max)
		{
			max = count[i];
			count[i] = -1;
			x = i;
		}
	}
	for(int i = 0; i < 26 ; i++)
	{
		if(max == count[i])
		{
			printf("?\n");
			return (0);
		}
	}
	printf("%c\n",x + 65);
	return 0;
}
