#include <stdio.h>
#include <stdlib.h>

typedef struct s
{
	int v;
	int i;
	int p;
} s;

int compare_1(const void *a, const void *b)
{
	s *x = (s *)a;
	s *y = (s *)b;
	if( x -> v > y -> v)
		return (1);
	else if( x -> v < y -> v)
		return (-1);
	else
		return (0);
}
int compare_2(const void *a, const void *b)
{
	s *x = (s *)a;
	s *y = (s *)b;
	if (x -> i > y -> i)
		return (1);
	else if(x -> i < y -> i)
		return (-1);
	else
		return (0);
}

int main(void)
{
	int n;
	scanf("%d",&n);
	int t = 0;
	s *x;

	x = (s *) malloc (sizeof(s) * n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&x[i].v);
		x[i].i = i;
	}
	qsort(x,n,sizeof(s),compare_1);
	x[0].p = t;
	for(int i = 1; i < n ;i++)
	{
		if(x[i - 1].v == x[i].v)
			x[i].p = t;
		else
		{
			t++;
			x[i].p = t;
		}
	}
	qsort(x,n,sizeof(s),compare_2);
	for(int i = 0; i < n ;i++)
	{
		if(i < n - 1)
			printf("%d ",x[i].p);
		else
			printf("%d",x[i].p);
	}
	free(x);
	return 0;
}
