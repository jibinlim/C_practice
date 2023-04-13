#include <stdio.h>
#include <stdlib.h>

struct po{
	int x;
	int y;
};

int main(void)
{
	int n;
	int m;
	scanf("%d %d",&n,&m);
	struct po queue[10001] = {0,};
	int front = 0, rear = 0;
	int x = 0, y = 0;

	int **ma;

	ma = (int **) malloc (sizeof(int *) * n);

	for(int i = 0; i < n; i++)
	{
		ma[i] = (int *) malloc (sizeof(int) * m);
		for(int j = 0; j < m; j++)
			scanf("%1d",&ma[i][j]);
	}
	ma[0][0] = 2;
	queue[front].x = x;
	queue[front].y = y;
	rear++;
	while(front < rear)
	{
		x = queue[front].x;
		y = queue[front].y;
		front++;
		if(x < n - 1 && ma[x + 1][y] == 1)
		{
			ma[x + 1][y] = ma[x][y] + 1;
			queue[rear].x = x + 1;
			queue[rear].y = y;
			rear++;
		}
		if(y < m - 1 && ma[x][y + 1] == 1)
		{
			ma[x][y + 1] = ma[x][y] + 1;
			queue[rear].x = x;
			queue[rear].y = y + 1;
			rear++;
		}
		if(x > 0 && ma[x - 1][y] == 1)
		{
			ma[x - 1][y] = ma[x][y] + 1;
			queue[rear].x = x - 1;
			queue[rear].y = y;
			rear++;
		}
		if(y > 0 && ma[x][y - 1] == 1)
		{
			ma[x][y - 1] = ma[x][y] + 1;
			queue[rear].x = x;
			queue[rear].y = y - 1;
			rear++;
		}
	}
	printf("%d\n",ma[n - 1][m - 1] - 1);
	for(int i = 0; i < n; i++)
		free(ma[i]);
	free(ma);
	return (0);
}
