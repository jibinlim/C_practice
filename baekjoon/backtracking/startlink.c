#include <stdio.h>

int team[20][20] = {0,};
int visit[21] = {0,};
int n;
int s[20];
int min = 2147483647;

void dfs(int x, int c)
{
	s[c] = x + 1;
	visit[x + 1] = 1;
	if(c == (n / 2) - 1)
	{
		int s_sum = 0;
		int l_sum = 0;
		int t = 0;
		int a = 0;
		int not[20];
		for(int i = 0; i < n; i++)
		{
			if(s[t] != i + 1)
			{
				not[a] = i + 1;
				a++;
			}
			else
				t++;
		}
		for(int i = 0; i <= c; i++)
			for(int j = i + 1; j <= c; j++)
			{
				s_sum += team[s[i] - 1][s[j] - 1];
				s_sum += team[s[j] - 1][s[i] - 1];
				l_sum += team[not[i] - 1][not[j] - 1];
				l_sum += team[not[j] - 1][not[i] - 1];
			}
		if(s_sum > l_sum)
		{
			if(s_sum - l_sum < min)
				min = s_sum - l_sum;
		}
		else
		{
			if(l_sum - s_sum < min)
				min = l_sum - s_sum;
		}
	}
	else
	{
		for(int i = x; i < n; i++)
			if(visit[i + 1] == 0)
				dfs(i, c + 1);
	}
	visit[x + 1] = 0;
}

int main(void)
{
	scanf("%d",&n);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d",&team[i][j]);

	for(int i = 0; i < n; i++)
		dfs(i,0);
	printf("%d\n",min);
	return (0);
}
