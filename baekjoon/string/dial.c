#include <stdio.h>
#include <stdlib.h>

int main()
{
	char* word;
	word = malloc (sizeof(char) * 16);
	scanf("%s",word);
	int sum = 0;
	while(*word)
	{
		if(*word >= 'A' && *word <= 'C')
			sum += 3;
		else if (*word >= 'D' && *word <= 'F')
			sum += 4;
		else if (*word >= 'G' && *word <= 'I')
			sum += 5;
		else if (*word >= 'J' && *word <= 'L')
			sum += 6;
		else if (*word >= 'M' && *word <= 'O')
			sum += 7;
		else if (*word >= 'P' && *word <= 'S')
			sum += 8;
		else if (*word >= 'T' && *word <= 'V')
			sum += 9;
		else if (*word >= 'W' && *word <= 'Z')
			sum += 10;
		word++;
	}
	printf("%d",sum);
	return (0);
}
