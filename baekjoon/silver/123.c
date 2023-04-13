#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int t,n;
	int b[11];
	b[0] = 1;
	b[1] = 2;
	b[2] = 4;
	int *ans;

	ans = (int *) malloc (sizeof(int) * t);
	scanf("%d",&t);
	for(int i = 0; i < t; i++)
	{
		scanf("%d",&n);
		for(int j = 3 ; j < n; j++)
			b[j] = b[j - 3] + b[j - 2] + b[j - 1];
		ans[i] = b[n - 1];
	}
	for(int i = 0; i < t; i++)
		printf("%d\n",ans[i]);
	free(ans);
	return (0);
}
