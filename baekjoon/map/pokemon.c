#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct po
{
	int in;
	char name[21];
} po;

int cmp(const void *a, const void *b)
{
	po *x = (po *) a;
	po *y = (po *) b;
	if(strcmp(x -> name, y -> name) < 0)
		return (1);
	else if(strcmp(x -> name, y -> name) > 0)
		return (-1);
	else
		return (0);
}

int com(const void *a, const void *b)
{
	po *x = (po *) a;
	po *y = (po *) b;
	if(x -> in > y -> in)
		return (1);
	else if(x -> in < y-> in)
		return (-1);
	else
		return (0);
}

int binary(po *p, char* qu, int left, int right)
{
	int c = (left + right) / 2;
	char a[21];
	if(left <= right)
	{
		strcpy(a, p[c].name);
		if(strcmp(a,qu) > 0)
			return binary(p, qu, c + 1, right);
		else if(strcmp(a,qu) < 0)
			return binary(p, qu, left, c - 1);
		else
			return (c);
	}
	return (0);
}

int main(void)
{
	int n, m;
	scanf("%d %d",&n,&m);
	po *p;
	char **qu;
	p = (po *) malloc (sizeof(po) * (n));
	for(int i = 0; i < n; i++)
	{
		scanf("%s",p[i].name);
		p[i].in = i + 1;
	}
	qu = (char **) malloc (sizeof(char *) * (m + 1));
	for(int i = 0; i < m; i++)
	{
		qu[i] = (char *) malloc (sizeof(char) * 21);
		scanf("%s",qu[i]);
	}
	for(int i = 0; i < m; i++)
	{
		if(atoi(qu[i]) > 0 && atoi(qu[i]) < n + 1)
		{
			qsort(p,n,sizeof(po),com);
			printf("%s\n",p[atoi(qu[i]) - 1].name);
		}
		else
		{
			qsort(p,n,sizeof(po),cmp);
			printf("%d\n",p[binary(p,qu[i],0,n-1)].in);
		}
		free(qu[i]);
	}
	free(qu);
	free(p);
	return (0);
}
