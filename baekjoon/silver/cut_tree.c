#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n,m;
	scanf("%d %d",&n,&m);

	long long end = 0;
	long long start = 0;
	int  *tree;
	tree = (int *) malloc (sizeof(int) * n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&tree[i]);
		if(end < tree[i])
			end = tree[i];
	}
	long long mid;
	long long x;
	long long mx;
	long long min = 2147483647;
	while(start <= end)
	{
		mid = (start + end) / 2;
		x = 0;
		for(int i = 0; i < n; i++)
		{
			if(mid < tree[i])
				x += tree[i] - mid;
		}
		if(x - m >= 0 && x - m < min)
		{
			min = x - m;
			mx = mid;
		}
		if(x > m)
			start = mid + 1;
		else
			end = mid - 1;
	}

	printf("%lld\n",mx);
	free(tree);
	return (0);
}

