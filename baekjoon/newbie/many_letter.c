#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char *s;
	char a[27] = "abcdefghijklmnopqrstuvwxyz";
	int x[26];
	int max = 0;

	s = (char *) malloc (sizeof(char) * 2501);

	scanf("%[^\n]s",s);

	for(int i = 0; i < 26; i++)
		x[i] = 0;
	int len = strlen(s);
	for(int i = 0; i < len ; i++)
	{
		for(int j = 0; j < 26; j++)
			if(a[j] == s[i])
			{
				x[j]++;
				break;
			}
	}
	for(int i = 0 ; i < 26; i++)
	{
		if(max < x[i])
			max = x[i];
	}
	for(int i = 0; i < 26; i++)
		if(max != 0 &&max == x[i])
			printf("%c",a[i]);
	free(s);
	return (0);
}
