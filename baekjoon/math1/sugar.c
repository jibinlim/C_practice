#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	int cnt = 5000;
	int f[1000];
	int t[3000];
	int x = 0;
	int y = 0;
	for(int i = 0; 5 * i <= n; i++)
	{
		for(int j = 0; 3 * j <= n; j++)
		{
			if(5 * i + 3 * j == n)
			{
				f[x] = i;
				t[x] = j;
				x++;
				y++;
			}
		}
	}
	x = 0;
	while(y > 0)
	{
		if(cnt > f[x] + t[x])
		{
			cnt = f[x] + t[x];
		}
		x++;
		y--;
	}
	if (cnt == 5000)
		cnt = -1;
	printf("%d",cnt);
	return(0);
}
