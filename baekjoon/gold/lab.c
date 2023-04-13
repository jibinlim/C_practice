#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int c_visit[8][8] = {0,};
int n,m;
int **lab;
int **t_lab;
int max;
int visit[8][8] = {0,};

struct p{
	int x;
	int y;
};

int front = 0;
int rear = 0;
struct p queue[65];

int check(void)
{
	int x,y;
	int mo[4] = {0,0,-1,1};
	int ve[4] = {-1,1,0,0};
	front = 0;
	int a_rear = rear;
	while(front < a_rear)
	{
		x = queue[front].x;
		y = queue[front].y;
		front++;
		for(int i = 0; i < 4; i++)
		{
			int dx = x + mo[i];
			int dy = y + ve[i];

			if(dx < 0 || dy < 0 || dx > n - 1 || dy > m - 1)
				continue;
			if(t_lab[dx][dy] == 0 && c_visit[dx][dy] == 0)
			{
				queue[a_rear].x = dx;
				queue[a_rear].y = dy;
				t_lab[dx][dy] = 2;
				c_visit[dx][dy] = 1;
				a_rear++;
			}
		}
	}
	int count = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			if(t_lab[i][j] == 0)
				count++;
			c_visit[i][j] = 0;
		}
	return (count);
}


void dfs(int x, int y, int c)
{
	visit[x][y] = 1;
	if(c == 3)
	{
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				t_lab[i][j] = lab[i][j];
		int count = check();
		if(count > max)
			max = count;
	}
	else
	{
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				if(lab[i][j] == 0 && visit[i][j] == 0)
				{
					lab[i][j] = 1;
					dfs(i,j,c+1);
					lab[i][j] = 0;
				}
	}
	visit[x][y] = 0;
}

int main(void)
{
	scanf("%d %d",&n,&m);

	lab = (int **) malloc (sizeof(int *) * n);
	t_lab = (int **) malloc (sizeof(int *) * n);
	for(int i = 0; i < n; i++)
	{
		lab[i] = (int *) malloc (sizeof(int) * m);
		t_lab[i] = (int *) malloc (sizeof(int) * m);
		for(int j = 0; j < m; j++)
		{
			scanf("%d",&lab[i][j]);
			if(lab[i][j] == 2)
			{
				queue[rear].x = i;
				queue[rear].y = j;
				rear++;
			}
		}
	}
	int count = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(lab[i][j] == 0)
			{
				lab[i][j] = 1;
				dfs(i,j,1);
				lab[i][j] = 0;
			}
	printf("%d\n",max);
	for(int i = 0; i < n; i++)
	{
		free(lab[i]);
		free(t_lab[i]);
	}
	free(lab);
	free(t_lab);
	return (0);
}
