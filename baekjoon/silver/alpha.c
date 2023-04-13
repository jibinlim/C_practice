#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a[26] = {0,};
	char alpha[27] = "abcdefghijklmnopqrstuvwxyz";
	char x;
	int max = 0;

	while((x = getchar()) != EOF)
	{
		if(x >= 'a' && x <= 'z')
			a[x - 'a']++;
		if(max < a[x - 'a'])
			max = a[x - 'a'];
	}
	for(int i = 0; i < 26; i++)
	{
		if(max == a[i])
			printf("%c",alpha[i]);
	}
	return (0);
}
