#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b)
{
	if(*(int *)a < *(int *)b)
		return (1);
	else if (*(int *)a > *(int *)b)
		return (-1);
	else
		return (0);
}

int det(char s[])
{
	int i = 0;
	while(s[i])
	{
		if(s[i] == '0')
			return(1);
		i++;
	}
	return (0);
}

int main(void)
{
	char s[500001];
	scanf("%s",s);
	int *a;
	int sum = 0;

	int max = -1;
	int len = strlen(s);
	a = (int *) malloc (sizeof(int) * (len));
	for(int i = 0; i < len; i++)
		sum += s[i] - '0';
	if(det(s) && sum % 3 == 0)
	{
		max = 0;
		for(int i = 0; i < len; i++)
			a[i] = s[i] - '0';
		qsort(a,len,sizeof(int),cmp);
		for(int i = 0; i < len; i++)
			s[i] = a[i] + '0';
		printf("%s",s);
	}
	else
		printf("%d",max);

	free(a);
	return (0);
}
