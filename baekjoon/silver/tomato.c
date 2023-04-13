#include <stdio.h>
#include <stdlib.h>

struct po{
	int x;
	int y;
};

int main(void)
{
	int n,m;
	scanf("%d %d",&n, &m);
	struct po q[1000001] = {0,};
	struct po n_q[1000001] = {0,};
	int **box;
	int front = 0;
	int rear = 0;
	int day = 0;
	int n_f = 0, n_r = 0;
	int flag = 0;
	int x,y;

	box = (int **) malloc(sizeof(int *) * m);

	for(int i = 0; i < m; i++)
	{
		box[i] = (int *) malloc (sizeof(int) * n);
		for(int j = 0; j < n; j++)
		{
			scanf("%d",&box[i][j]);
			if(box[i][j] == 1)
			{
				q[rear].x = i;
				q[rear].y = j;
				rear++;
			}
		}
	}
	while(1)
	{
		if(flag == 0)
		{
			n_f = 0;
			n_r = 0;
			while(front < rear)
			{
				x = q[front].x;
				y = q[front].y;
				front++;
				if(x < m - 1 && box[x + 1][y] == 0)
				{
					box[x + 1][y] = 1;
					n_q[n_r].x = x + 1;
					n_q[n_r].y = y;
					n_r++;
				}
				if(x > 0 && box[x - 1][y] == 0)
				{
					box[x - 1][y] = 1;
					n_q[n_r].x = x - 1;
					n_q[n_r].y = y;
					n_r++;
				}
				if(y < n - 1 && box[x][y + 1] == 0)
				{
					box[x][y + 1] = 1;
					n_q[n_r].x = x;
					n_q[n_r].y = y + 1;
					n_r++;
				}
				if(y > 0 && box[x][y - 1] == 0)
				{
					box[x][y - 1] = 1;
					n_q[n_r].x = x;
					n_q[n_r].y = y - 1;
					n_r++;
				}
			}
			flag = 1;
			if(n_f == n_r)
				break;
			day++;
		}
		else
		{
			front = 0;
			rear = 0;
			while(n_f < n_r)
			{
				x = n_q[n_f].x;
				y = n_q[n_f].y;
				n_f++;
				if(x < m - 1 && box[x + 1][y] == 0)
				{
					box[x + 1][y] = 1;
					q[rear].x = x + 1;
					q[rear].y = y;
					rear++;
				}
				if(x > 0 && box[x - 1][y] == 0)
				{
					box[x - 1][y] = 1;
					q[rear].x = x - 1;
					q[rear].y = y;
					rear++;
				}
				if(y < n - 1 && box[x][y + 1] == 0)
				{
					box[x][y + 1] = 1;
					q[rear].x = x;
					q[rear].y = y + 1;
					rear++;
				}
				if(y > 0 && box[x][y - 1] == 0)
				{
					box[x][y - 1] = 1;
					q[rear].x = x;
					q[rear].y = y - 1;
					rear++;
				}
			}
			if(front == rear)
				break;
			day++;
			flag = 0;
		}
	}
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			if(box[i][j] == 0)
				day = -1;
	printf("%d",day);
	for(int i = 0; i < m; i++)
		free(box[i]);
	free(box);
	return (0);
}
