#include <stdio.h>
#include <stdlib.h>

int gcd(int a,int b)
{
	if(b == 0)
		return (a);
	else
		return gcd(b,a%b);
}

int main(void)
{
	int t;
	scanf("%d",&t);

	int *a;
	int *b;
	a = (int *) malloc (sizeof(int) * t);
	b = (int *) malloc (sizeof(int) * t);

	for(int i = 0 ; i < t; i++)
		scanf("%d %d",&a[i], &b[i]);
	for(int i = 0; i < t; i++)
		printf("%d\n",(a[i] * b[i]) / gcd(a[i],b[i]));
	free(a);
	free(b);
	return (0);
}
