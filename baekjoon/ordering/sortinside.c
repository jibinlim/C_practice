#include <stdio.h>
#include <stdlib.h>
int cmp(const int *a, const int *b)
{
	if(*a < *b)
		return 1;
	else if (*a > *b)
		return (-1);
	else
		return (0);
}

int ja(int x)
{
	int count = 0;
	while(x > 0)
	{
		x /= 10;
		count++;
	}
	return (count);
}

int main(void)
{
	int x;
	scanf("%d",&x);

	int j;
	int j_temp;
	int temp;
	int *a;

	j = ja(x);
	j_temp = j;
	a = (int *) malloc (sizeof(int) * j);

	while(j > 0)
	{
		a[j - 1] = x % 10;
		x /= 10;
		j--;
	}
	qsort(a,j_temp,sizeof(int),(int(*)(const void *,const void *))cmp);
	for(int i = 0; i < j_temp; i++)
		printf("%d",a[i]);
	free(a);
	return (0);
}
