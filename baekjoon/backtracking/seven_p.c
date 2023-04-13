#include <stdio.h>

char stu[6][6];
int ct = 0;
char s[6];
int visit[5][5] = {0,};
int a[6];
int b[6];
void dfs(int x, int y,int c)
{
	s[c] = stu[x][y];
	if(c == 6)
	{
		int count = 0;
		for(int i = 0; i <= 6; i++)
			if(s[i] == 'S')
				count++;
		if(count >= 4)
		{
			ct++;
		}
		return ;
	}
	int mo[4] = {0,0,-1,1};
	int ve[4] = {-1,1,0,0};
	for(int i = 0; i < 4; i++)
	{
		int dx = x + mo[i];
		int dy = y + ve[i];
		if(dx < 0 || dx > 4 || dy < 0 || dy > 4)
			continue;
		if(visit[dx][dy] == 0)
		{
			visit[dx][dy] = 1;
			dfs(dx,dy,c + 1);
			visit[dx][dy] = 0;
		}
	}
}


int main(void)
{
	for(int i = 0; i < 5; i++)
		scanf("%s",stu[i]);
	for(int i = 0; i < 5; i++)
		for(int j = 0; j < 5; j++)
		{
			if(visit[i][j] == 0)
			{
				visit[i][j] = 1;
				dfs(i,j,0);
				visit[i][j] = 0;
			}
		}
	printf("%d\n",ct);
	return (0);
}
