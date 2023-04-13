#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
	if(*(int *)a > *(int *)b)
		return (1);
	else if (*(int *)a < *(int *)b)
		return (-1);
	else
		return (0);
}

int main(void)
{
	int n;
	int *a;
	int x;
	int ans = 0;
	int t;
	int j = -1;

	scanf("%d", &n);
	a = (int *) malloc (sizeof(int) * n);

	for(int i = 0; i < n; i++)
		scanf("%d",a+i);
	scanf("%d",&x);

	qsort(a,n,sizeof(int),cmp);

	for(int i = 0; i < n; i++)
	{
		if(a[i] == x)
		{
			ans = 0;
			t = x + 1;
			break;
		}
		if(a[i] > x)
		{
			j = i;
			t = a[i - 1] + 1;
			break;
		}
	}
	if(j == 0)
		t = 1;
	while(t <= x)
	{
		if(t != x)
			ans += (a[j] - 1) - x + 1;
		else
			ans += (a[j] - 1) - x;
		t++;
	}
	printf("%d",ans);
	free(a);
	return (0);
}
