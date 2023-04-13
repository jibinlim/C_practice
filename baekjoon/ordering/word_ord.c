#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b)
{
	char *x = *(char **) a;
	char *y = *(char **) b;
	int w1 = strlen(x);
	int w2 = strlen(y);
	if(w1 > w2)
		return 1;
	else if (w1 < w2)
		return -1;
	else
		return strcmp(x,y);
}

int main(void)
{
	int n;
	scanf("%d",&n);
	int a;

	char **str;
	str = (char **) malloc(sizeof(char *) * (n + 1));

	for(int i = 0; i < n; i++)
	{
		str[i] = (char *) malloc(sizeof(char) * 51);
		scanf("%s",str[i]);
	}
	qsort(str , n, sizeof(str[0]), compare);
	printf("%s\n",str[0]);
	for(int i = 1; i < n; i++)
	{
		a = strcmp(str[i-1], str[i]);
		if(a != 0)
			printf("%s\n",str[i]);
	}
	for(int i = 0 ; i < n; i++)
		free(str[i]);
	free(str);
	return (0);
}
