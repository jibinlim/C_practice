#include <stdio.h>

void is_prime(int m,int n)
{
	int arr[n+1];

	for(int i = 0; i < n+1; i++)
		arr[i] = 0;

	arr[0] = 1;
	arr[1] = 1;

	for(int i = 2; i <= n; i++)
	{
		if(arr[i] == 1)
			continue;
		for(int j=2*i; j<=n ; j+=i)
			arr[j] = 1;
	}
	for(int i = m; i <= n; i++)
		if(!arr[i]) printf("%d\n",i);
}

int main(void)
{
	int m;
	int n;
	scanf("%d %d",&m,&n);
	is_prime(m,n);
	return (0);
}
