#include <stdio.h>

int main(void)
{
	long long n,m;
	scanf("%lld %lld",&n,&m);

	unsigned long long ans;

	if(n > m)
		ans = n - m;
	else
		ans = m - n;
	printf("%lld",ans);
	return (0);
}
