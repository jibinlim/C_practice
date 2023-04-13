#include <stdio.h>

int main(void)
{
	int n,m;
	scanf("%d %d",&n,&m);
	int a[101];
	int f,t;

	for(int i = 1; i <= n; i++)
		a[i] = i;
	for(int i = 0; i < m; i++)
	{
		scanf("%d %d",&f,&t);
		while(f < t)
		{
			int temp = a[f];
			a[f] = a[t];
			a[t] = temp;
			f++;
			t--;
		}
	}
	for(int i = 1; i <= n; i++)
		printf("%d ",a[i]);
	return (0);
}

