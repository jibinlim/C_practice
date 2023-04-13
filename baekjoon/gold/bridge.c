#include <stdio.h>
#include <stdlib.h>

int n;
int **island;
int min = 2147483647;

struct p{
	int x;
	int y;
	int h;
};

int j_rear = 0;
struct p* j_queue = (struct p*) malloc (sizeof(struct p) * (n * n));
void bfs(int a,int b, int c)
{
	struct p* queue = (struct p*) malloc (sizeof(struct p) * (n * n));
	int x,y;
	int front = 0,rear = 1;
	int mo[4] = {0,0,-1,1};
	int ve[4] = {-1,1,0,0};
	int dx,dy;
	island[a][b] = c;
	queue[0].x = a;
	queue[0].y = b;
	int t = 0;
	while(front < rear)
	{
		x = queue[front].x;
		y = queue[front].y;
		front++;

		t = 0;
		for(int i = 0; i < 4; i++)
		{
			dx = x + mo[i];
			dy = y + ve[i];

			if(dx < 0 || dy < 0 || dx > n - 1 || dy > n - 1)
				continue;
			if(island[dx][dy] == 1)
			{
				island[dx][dy] = c;
				queue[rear].x = dx;
				queue[rear].y = dy;
				rear++;
			}
			if(island[dx][dy] == 0 && t = 0)
			{
				j_queue[j_rear].x = dx;
				j_queue[j_rear].y = dy;
				j_queue[j_rear].h = c;
				j_rear++;
				t++;
			}
		}
	}
	free(queue);
}

int main(void)
{
	scanf("%d",&n);
	
	island = (int **) malloc (sizeof(int *) * n);
	for(int i = 0; i < n; i++)
	{
		island[i] = (int *) malloc (sizeof(int) * n);
		for(int j = 0; j < n; j++)
			scanf("%d",&island[i][j]);
	}

	int a = 2;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			if(island[i][j] == 1)
			{
				bfs(i,j,a);
				a++;
			}
		}
	int t = 2;
	int j_front = 0;
	int x,y,t;
	while(t < a)
	{
		while(j_
		x = j_queue[front].x;
		y = j_queue[front].y;
		t = j_queue[front].h;
		front++;
		if(island[x][y] != t
	printf("%d\n",min);
	for(int i = 0; i < n; i++)
	{
		free(island[i]);
	}
	free(island);
	return (0);
}
