#include <stdio.h>

struct p{
	int x;
	int y;
	int z;
	int d;
};


int main(void)
{
	int m,n,h;
	int box[101][101][101] = {0,};
	scanf("%d %d %d",&m,&n,&h);

	struct p queue[1000001] = {0,};
	int front = 0, rear = 0;
	int c = 0;

	for(int i = 0; i < h; i++)
		for(int j = 0; j < n; j++)
			for(int k = 0; k < m; k++)
			{
				scanf("%d",&box[i][j][k]);
				if(box[i][j][k] == 1)
				{
					queue[rear].z = i;
					queue[rear].y = j;
					queue[rear].x = k;
					queue[rear].d = 0;
					rear++;
				}
			}

	int x,y,z,d;
	while(front < rear)
	{
		x = queue[front].x;
		y = queue[front].y;
		z = queue[front].z;
		d = queue[front].d;
		front++;
		if(z < h - 1 && box[z + 1][y][x] == 0)
		{
			queue[rear].x = x;
			queue[rear].y = y;
			queue[rear].z = z + 1;
			queue[rear].d = d + 1;
			box[z + 1][y][x] = 1;
			rear++;
		}
		if(z > 0 && box[z - 1][y][x] == 0)
		{
			queue[rear].x = x;
			queue[rear].y = y;
			queue[rear].z = z - 1;
			queue[rear].d = d + 1;
			box[z - 1][y][x] = 1;
			rear++;
		}
		if(x > 0 && box[z][y][x - 1] == 0)
		{
			queue[rear].x = x - 1;
			queue[rear].y = y;
			queue[rear].z = z;
			queue[rear].d = d + 1;
			box[z][y][x - 1] = 1;
			rear++;
		}
		if(x < m - 1 && box[z][y][x + 1] == 0)
		{
			queue[rear].x = x + 1;
			queue[rear].y = y;
			queue[rear].z = z;
			queue[rear].d = d + 1;
			box[z][y][x + 1] = 1;
			rear++;
		}
		if(y > 0 && box[z][y - 1][x] == 0)
		{
			queue[rear].x = x;
			queue[rear].y = y - 1;
			queue[rear].z = z;
			queue[rear].d = d + 1;
			box[z][y - 1][x] = 1;
			rear++;
		}
		if(y < n - 1 && box[z][y + 1][x] == 0)
		{
			queue[rear].x = x;
			queue[rear].y = y + 1;
			queue[rear].z = z;
			queue[rear].d = d + 1;
			box[z][y + 1][x] = 1;
			rear++;
		}
	}
	for(int i = 0; i < h; i++)
		for(int j = 0; j < n; j++)
			for(int k = 0; k < m; k++)
			{
				if(box[i][j][k] == -1)
					c++;
				if(box[i][j][k] == 0)
					d = -1;
			}
	printf("%d\n",d);
	return (0);
}
