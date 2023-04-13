#include <stdio.h>
#include <stdlib.h>

void quick_1(int *a,int *b, int left, int right)
{
	int pr = right;
	int pl = left;
	int x = a[(pr + pl) / 2];
	int temp;
	while(pr >= pl)
	{
		while(a[pr] > x) pr--;
		while(a[pl] < x) pl++;
		if(pr >= pl)
		{
			temp = a[pr];
			a[pr] = a[pl];
			a[pl] = temp;
			temp = b[pr];
			b[pr] = b[pl];
			b[pl] = temp;
			pl++;
			pr--;
		}
	}
	if(left < pr) quick_1(a, b, left, pr);
	if(right > pl) quick_1(a, b, pl, right);
}

int main(void)
{
	int n;
	scanf("%d",&n);
	if(n < 0)
		return (0);
	int temp;

	int a = 0;
	int b = a + 1;

	int *x;
	int *y;

	x = (int *) malloc (sizeof(int) * n);
	y = (int *) malloc (sizeof(int) * n);

	for(int i = 0; i < n; i++)
		scanf("%d %d",&x[i],&y[i]);
	quick_1(x, y, 0, n-1);
	while(a < n)
	{
		while(x[a] == x[b] && b < n)
			b++;
		if(b - a > 1)
		{
			quick_1(y,x,a,b-1);
			a = b;
			b = a + 1;
		}
		else
		{
			a++;
			b = a + 1;
		}
	}
	for(int i = 0; i < n; i++)
		printf("%d %d\n",x[i],y[i]);
	free(x);
	free(y);
	return (0);
}
