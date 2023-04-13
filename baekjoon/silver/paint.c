#include <stdio.h>

struct p{
	int x;
	int y;
};

int n;
int m;
int paint[501][501];
int max = 0;
int z = 0;
struct p queue[250000] = {0,};

void bfs(int xx, int yy)
{
	int x ,y;
	int front = 0,rear = 0;
	queue[rear].x = xx;
	queue[rear].y = yy;
	paint[xx][yy] = 0;
	rear++;
	int mo[4] = {0,0,-1,1};
	int ve[4] = {-1,1,0,0};
	while(rear > front)
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
			if(paint[dx][dy] == 1)
			{
				queue[rear].x = dx;
				queue[rear].y = dy;
				paint[dx][dy] = 0;
				rear++;
			}
		}
	}
	if(front > max)
		max = front;
}

int main(void)
{
	scanf("%d %d",&n,&m);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			scanf("%d",&paint[i][j]);
	int count = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(paint[i][j] == 1)
			{
				bfs(i,j);
				count++;
			}
	printf("%d\n%d\n",count,max);
	return (0);
}
