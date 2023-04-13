#include <stdio.h>
#include <math.h>

int func(int n, int r, int c)
{
	if(n < 1)
		return (0);

	int mid = (int)pow(2, n - 1);

	if(r < mid && c < mid)
		return func(n - 1, r ,c);
	else if(r < mid && c >= mid)
		return mid * mid + func(n - 1, r , c - mid);
	else if(r >= mid && c < mid)
		return mid * mid * 2 + func(n - 1, r - mid, c);
	else
		return mid * mid * 3 + func(n - 1, r - mid, c - mid);
}

int main(void)
{
	int n,r,c;
	scanf("%d %d %d",&n,&r,&c);

	int result = func(n,r,c);
	printf("%d\n",result);
	return (0);
}
