#include <stdio.h>
#include <stdlib.h>

void merge(int tmp[],int a[], int l, int c,int r,int *x)
{
	int i = l;
	int j = c + 1;
	int t = 0;
	while(i <= c && j <= r)
	{
		if(a[i] <= a[j])
			tmp[t++] = a[i++];
		else
			tmp[t++] = a[j++];
	}
	while(i <= c)
		tmp[t++] = a[i++];
	while(j <= r)
		tmp[t++] = a[j++];
	i = l;
	t = 0;
	while(i <= r)
	{
		a[i++] = tmp[t++];
		(*x)--;
		if(*x == 0)
		{
			printf("%d\n",a[i-1]);
			return ;
		}
	}
}

void merge_sort(int tmp[], int a[],int l, int r, int *x)
{
	if(l < r)
	{
		int c = (l + r) / 2;
		merge_sort(tmp, a, l, c, x);
		merge_sort(tmp, a, c + 1, r, x);
		merge(tmp, a, l, c, r, x);
	}
}

int main(void)
{
	int n;
	int x;
	scanf("%d %d",&n,&x);
	int *tmp;
	int *a;
	tmp = (int *) malloc (sizeof(int)  * n);
	a = (int *) malloc (sizeof(int) * n);
	for(int i = 0; i < n; i++)
		scanf("%d",a + i);
	merge_sort(tmp, a, 0, n - 1, &x);
	if(x > 0)
		printf("-1");
	free(a);
	free(tmp);
	return (0);
}
