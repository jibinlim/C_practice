#include <stdio.h>
#include <stdlib.h>

int arr[9];
int n,m;
int s[9];
int check[1000] = {0 ,};

int cmp(const void *a, const void *b)
{
	if(*(int *)a > *(int *)b)
		return (1);
	else if(*(int *)a < *(int *)b)
		return (-1);
	else
		return (0);
}

void dfs(int x, int cnt)
{
	s[cnt - 1] = arr[x];
	int v = -1;
	if(cnt == m)
	{
		for(int i = 0; i < m; i++)
			printf("%d ",s[i]);
		printf("\n");
	}
	else
		for(int i = 0; i < n; i++)
		{
			if(v != arr[i])
			{
				v = arr[i];
				dfs(i,cnt + 1);
			}
		}
}

int main(void)
{
	scanf("%d %d",&n,&m);

	for(int i = 0; i < n; i++)
	{
		scanf("%d",&arr[i]);
		check[arr[i]]++;
	}
	qsort(arr,n,sizeof(int),cmp);
	for(int i = 0 ; i < n; i += check[arr[i]])
		dfs(i,1);
	return (0);
}
