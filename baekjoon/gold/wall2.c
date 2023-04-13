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
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	int **map = (int **) malloc (sizeof(int *) * n);
	int ***visit = (int ***) malloc (sizeof(int **) * n);
	for(int i = 0; i < n; i++)
	{
		map[i] = (int *) malloc (sizeof(int) * m);
		visit[i] = (int **) malloc (sizeof(int *) * m);
		for(int j = 0; j < m; j++)
		{
			scanf("%1d",&map[i][j]);
			visit[i][j] = (int *) malloc (sizeof(int) * (k + 1));
			for(int a = 0; a < k; a++)
				visit[i][j][k] = 0;
		}
	}
	struct p *queue = (struct p*) malloc (sizeof(struct p) * (n * m * (k + 1)));
	int x,y,t,c;
	int mo[4] = {0,0,-1,1};
	int ve[4] = {-1,1,0,0};
	int front = 0,rear = 1;
	queue[0].x = 0;
	queue[0].y = 0;
	queue[0].t = 1;
	queue[0].c = 0;
	visit[0][0][0] = 1;
	int ans = 0;
	while(front < rear)
	{
		x = queue[front].x;
		y = queue[front].y;
		t = queue[front].t;
		c = queue[front].c;
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

			if(c == k)
			{
				if(visit[dx][dy][c] == 0 && map[dx][dy] == 0)
				{
					visit[dx][dy][c] = 1;
					queue[rear].x = dx;
					queue[rear].y = dy;
					queue[rear].t = t + 1;
					queue[rear].c = c;
					rear++;
				}
			}
			else
			{
				if(visit[dx][dy][c] == 0 && map[dx][dy] == 0)
				{
					visit[dx][dy][c] = 1;
					queue[rear].x = dx;
					queue[rear].y = dy;
					queue[rear].t = t + 1;
					queue[rear].c = c;
					rear++;
				}
				if(visit[dx][dy][c + 1] == 0 && map[dx][dy] == 1)
				{
					visit[dx][dy][c + 1] = 1;
					queue[rear].x = dx;
					queue[rear].y = dy;
					queue[rear].t = t + 1;
					queue[rear].c = c + 1;
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
		free(map[i]);
		free(visit[i]);
	}
	free(queue);
	free(map);
	free(visit);
	return (0);
}

