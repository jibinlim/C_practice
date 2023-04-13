#include <stdio.h>

int main()
{
	int t;
	scanf("%d",&t);
	int k;
	int n;
	int s[15][14];
	int a[t];
	for(int i = 0; i < 15 ; i++)
	{
		s[i][0] = 1;
		for(int j = 0; j < 14; j++)
		{
			s[0][j] = j + 1;
			if(i == 0)
				continue;
			if(j == 0)
				continue;
			s[i][j] = s[i-1][j] + s[i][j-1];
		}
	}
	for(int i = 0; i < t; i++)
	{
		scanf("%d",&k);
		scanf("%d",&n);
		a[i] = s[k][n - 1];
	}
	for(int i = 0 ; i < t; i++)
	{
		printf("%d\n",a[i]);
	}
	return (0);
}
