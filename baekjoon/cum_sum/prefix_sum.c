#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	int m;

	scanf("%d %d",&n,&m);
	int *a;
	int b;
	int c;
	int *ans;
	int *sum;

	a = (int *) malloc (sizeof(int) * n);
	ans = (int *) malloc (sizeof(int) * m);
	sum = (int *) malloc (sizeof(int) * n + 1);

	sum[0] = 0;
	for(int i = 0; i < n; i++)
	{
		scanf("%d",a+i);
		sum[i+1] = sum[i] + a[i];
	}
	for(int i = 0; i < m; i++)
	{
		scanf("%d %d",&b,&c);
		if(b == c)
			ans[i] = a[b - 1];
		else
			ans[i] = sum[c] - sum[b - 1];
	}

	for(int i = 0; i < m; i++)
		printf("%d\n",ans[i]);
	free(a);
	free(ans);
	free(sum);
	return (0);
}
