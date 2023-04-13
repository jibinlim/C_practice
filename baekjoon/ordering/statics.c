#include <stdio.h>
#include <stdlib.h>

int cmp(const int *a,const int *b)
{
	if(*a < *b)
		return (-1);
	else if(*a > *b)
		return (1);
	else
		return (0);
}

int main(void)
{
	int n;
	scanf("%d",&n);

	int *a;
	a = (int *) malloc (sizeof(int) * n);

	double avg;
	int med;
	int mode;
	int range;
	int sum = 0;
	int x;
	int max = 0;
	int j = 0;
	int *y;
	int count = 0;
	int z = 0;
	int c;

	y = (int *) malloc (sizeof(int) * 8000);


	for(int i = 0; i < n; i++)
		scanf("%d",&a[i]);
	for(int i = 0; i < 8001; i++)
		y[i] = 0;
	qsort(a,n,sizeof(int),(int(*)(const void *, const void *))cmp);
	med = a[(n-1)/2];
	range = a[n-1] - a[0];
	x = a[0];
	for(int i = 0; i < n; i++)
	{
		y[a[i]+4000]++;
		sum += a[i];
	}
	for(int i = 8000; i >= 0; i--)
	{
		if(z < y[i])
		{
			count = 0;
			z = y[i];
			c = i;
			count++;
		}
		else if (z == y[i])
		{
			count++;
			c = i;
		}
	}
	if	(count >= 2)
	{
		for(int j = c + 1; j < 8001; j++)
			if(y[j] == z)
			{
				mode = j - 4000;
				break;
			}
	}
	else
		mode = c - 4000;
	avg =(double) sum / n;
	if (avg < 0 && avg > -1)
		avg = 0;
	printf("%.0lf\n%d\n%d\n%d\n",avg,med,mode,range);
	free(a);
	free(y);
	return (0);
}
