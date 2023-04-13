#include <stdio.h>
#include <stdlib.h>

struct p{
	int x;
	int y;
	int t;
	int c;
};

int main(void)
{
	int n,m;
	scanf("%d %d",&n,&m);
	int **map = (int **) malloc (sizeof(int *) * n);
	int ***visit = (int ***) malloc (sizeof(int **) * n);
	for(int i = 0; i < n; i++)
	{
		visit[i] = (int **) malloc (sizeof(int *) * m);
		map[i] = (int *) malloc (sizeof(int) * m);
		for(int j = 0; j < m; j++)
		{
			scanf("%1d",&map[i][j]);
			visit[i][j] = (int *) malloc (sizeof(int) * 2);
			for(int k = 0; k < 2; k++)
				visit[i][j][k] = 0;
		}
	}
	struct p *queue = (struct p*) malloc (sizeof(struct p) * (n * m));
	int x,y,t,c;
	int front = 0,rear = 1;
	queue[0].x = 0;
	queue[0].y = 0;
	queue[0].t = 1;
	queue[0].c = 0;
	visit[0][0][0] = 1;
	int ans = 0;
	int mo[4] = {0,0,-1,1};
	int ve[4] = {-1,1,0,0};
	while(front < rear)
	{
		x = queue[front].x;
		y = queue[front].y;
		c = queue[front].c;
		t = queue[front].t;
		front++;
		if(x == n - 1 && y == m - 1)
		{
			ans = 1;
			break;
		}
		for(int i = 0; i < 4; i++)
		{
			int dx = x + mo[i];
			int dy = y + ve[i];

			if(dx < 0 || dy < 0 || dx > n - 1 || dy > m - 1)
				continue;
			if(c == 0)
			{
				if(visit[dx][dy][0] == 0 && map[dx][dy] == 0)
				{
					visit[dx][dy][0] = 1;
					queue[rear].x = dx;
					queue[rear].y = dy;
					queue[rear].c = 0;
					queue[rear].t = t + 1;
					rear++;
				}
				if(visit[dx][dy][1] == 0 && map[dx][dy] == 1)
				{
					visit[dx][dy][1] = 1;
					queue[rear].x = dx;
					queue[rear].y = dy;
					queue[rear].c = 1;
					queue[rear].t = t + 1;
					rear++;
				}
			}
			else
			{
				if(visit[dx][dy][1] == 0 && map[dx][dy] == 0)
				{
					visit[dx][dy][1] = 1;
					queue[rear].x = dx;
					queue[rear].y = dy;
					queue[rear].c = 1;
					queue[rear].t = t + 1;
					rear++;
				}
			}
		}
	}
	if(ans == 1)
		printf("%d\n",t);
	else
		printf("-1\n");
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
			free(visit[i][j]);
		free(visit[i]);
		free(map[i]);
	}
	free(map);
	free(visit);
	free(queue);
	return (0);
}
