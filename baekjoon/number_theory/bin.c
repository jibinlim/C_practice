#include <stdio.h>

int bon(int n,int k)
{
	if(k == 0 || k == n)
		return (1);
	else
		return (bon(n - 1, k - 1) + bon(n - 1, k));
}

int main(void)
{
	int n;
	int k;
	scanf("%d %d",&n,&k);

	if(k < 0 || k > n)
		printf("0");
	else
		printf("%d",bon(n, k) % 10007);

	return (0);
}
