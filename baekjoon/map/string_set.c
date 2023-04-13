#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b)
{
	char **x = (char **) a;
	char **y = (char **) b;
	if(strcmp(*x,*y) > 0)
		return (1);
	else if (strcmp(*x,*y) < 0)
		return (-1);
	else
		return (0);
}

int binary(char **ns, char *ms,int left, int right)
{
	int c = (left + right) / 2;
	char *a;
	a = (char *) malloc (sizeof(char) * 501);
	a = ns[c];
	if (left <= right)
	{
		if(strcmp(ms,a) < 0)
			return binary(ns,ms,left,c-1);
		else if(strcmp(ms,a) > 0)
			return binary(ns,ms,c + 1,right);
		else
			return (1);
	}
	return (0);
}

int main(void)
{
	int n,m;
	scanf("%d %d",&n, &m);
	char **ns;
	char **ms;
	int count = 0;

	ns = (char **) malloc (sizeof(char *) * (n + 1));
	ms = (char **) malloc (sizeof(char *) * (m + 1));

	for(int i = 0; i < n; i++)
	{
		ns[i] = (char *) malloc (sizeof(char) * 501);
		scanf("%s",ns[i]);
	}
	for(int i = 0; i < m; i++)
	{
		ms[i] = (char *) malloc (sizeof(char) * 501);
		scanf("%s",ms[i]);
	}
	qsort(ns, n, sizeof(char *),cmp);
	for(int i = 0; i < m; i++)
		if(binary(ns, ms[i], 0 , n - 1) == 1)
			count ++;
	for(int i = 0; i < m; i++)
		free(ms[i]);
	for(int i = 0; i < n; i++)
		free(ns[i]);
	free(ms);
	free(ns);
	printf("%d",count);
	return (0);
}
