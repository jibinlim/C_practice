#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n,k;
	scanf("%d %d",&n,&k);

	int *man;
	int index = -1;
	int count = 0;
	int j = 0;
	int *ans;

	man = (int *) malloc (sizeof(int) * n);
	ans = (int *) malloc (sizeof(int) * n);
	for(int i = 0; i < n; i++)
		man[i] = i + 1;

	while(j < n)
	{
		index++;
		if(index >= n)
			index = 0;
		count ++;
		while(man[index] == 0)
		{
			index++;
			if(index >= n)
				index = 0;
		}
		if(count == k)
		{
			ans[j] = man[index];
			man[index] = 0;
			count = 0;
			j++;
		}
	}
	printf("<");
	for(int i = 0; i < n; i++)
	{
		if(i != n - 1)
			printf("%d, ",ans[i]);
		else
			printf("%d>",ans[i]);
	}
	free(ans);
	free(man);
	return (0);
}
