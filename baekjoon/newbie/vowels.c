#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vowel(char *s,int len)
{
	int i = 0;
	int count = 0;
	char x[11] = "aeiouAEIOU";

	while(i < len)
	{
		for(int j = 0; j < 10; j++)
			if(x[j] == s[i])
			{
				count++;
				break;
			}
		i++;
	}
	return (count);
}

int main(void)
{
	int *ans;
	char **s;
	int j = 0;

	s = (char **) malloc (sizeof(char *) * 501);
	ans = (int *) malloc(sizeof(int) * 500);
	while(1)
	{
		s[j] = (char *) malloc(sizeof(char) * 256);
		gets(s[j]);
		if(s[j][0] == '#')
			break;
		ans[j] = vowel(s[j],strlen(s[j]));
		free(s[j]);
		j++;
	}
	for(int i = 0; i < j; i++)
		printf("%d\n",ans[i]);
	free(ans);
	free(s);
	return (0);
}
