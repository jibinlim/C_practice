#include <stdio.h>
#include <stdlib.h>

struct p {
	int x;
	int y;
};

int main(void)
{
	int n,m;
	scanf("%d %d",&m,&n);
	int **map;
	struct p queue[1000001];
	int front = 0, rear = 0;
	int x,y;
	int count = 0;
	int now;

	map = (int **) malloc (sizeof(int *) * m);
	for(int i = 0; i < m; i++)
	{
		map[i] = (int *) malloc (sizeof(int) * n);
		for(int j = 0; j < n; j++)
			scanf("%d",&map[i][j]);
	}
	x = 0;
	y = 0;
	queue[rear].x = x;
	queue[rear].y = y;
	rear++;
	while(front < rear)
	{
		x = queue[front].x;
		y = queue[front].y;
		front++;
		now = map[x][y];
		if(x > 0 && map[x - 1][y] < now)
		{
			queue[rear].x = x - 1;
			queue[rear].y = y;
			rear++;
		}
		if(x < m - 1 && map[x + 1][y] < now)
		{
			queue[rear].x = x + 1;
			queue[rear].y = y;
			rear++;
		}
		if(y > 0 && map[x][y - 1] < now)
		{
			queue[rear].x = x;
			queue[rear].y = y - 1;
			rear++;
		}
		if(y < n - 1 && map[x][y + 1] < now)
		{
			queue[rear].x = x;
			queue[rear].y = y + 1;
			rear++;
		}
		if(x == m - 1 && y == n - 1)
			count++;
	}
	printf("%d",count);
	for(int i = 0; i < m; i++)
		free(map[i]);
	free(map);
	return (0);
}

