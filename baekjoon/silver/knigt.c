#include <stdio.h>
#include <stdlib.h>

struct po{
	int x;
	int y;
	int z;
};

int main(void)
{
	int t;
	scanf("%d",&t);
	int k;
	int x,y,z;
	int des_x,des_y;
	int front,rear;

	for(int i = 0; i < t; i++)
	{
		scanf("%d",&k);
		scanf("%d %d",&x,&y);
		scanf("%d %d",&des_x,&des_y);
		struct po queue[100001] = {0,};
		int b[300][300] = {0,};
		front = 0;
		rear = 0;
		z = 0;
		queue[rear].x = x;
		queue[rear].y = y;
		queue[rear].z = z;
		b[x][y] = 1;
		rear++;
		while(front < rear)
		{
			x = queue[front].x;
			y = queue[front].y;
			z = queue[front].z;
			front++;
			if(x == des_x && y == des_y)
				break;
			if(x > 0 && y < k - 2 && b[x - 1][y + 2] == 0)
			{
				queue[rear].x = x - 1;
				queue[rear].y = y + 2;
				queue[rear].z = z + 1;
				b[x - 1][y + 2] = 1;
				rear++;
			}
			if(x > 0 && y > 1 && b[x - 1][y - 2] == 0)
			{
				queue[rear].x = x - 1;
				queue[rear].y = y - 2;
				queue[rear].z = z + 1;
				b[x - 1][y - 2] = 1;
				rear++;
			}
			if(x > 1 && y < k - 1 && b[x - 2][y + 1] == 0)
			{
				queue[rear].x = x - 2;
				queue[rear].y = y + 1;
				queue[rear].z = z + 1;
				b[x - 2][y + 1] = 1;
				rear++;
			}
			if(x > 1 && y > 0 && b[x - 2][y - 1] == 0) 
			{
				queue[rear].x = x - 2;
				queue[rear].y = y - 1;
				queue[rear].z = z + 1;
				b[x - 2][y - 1] = 1;
				rear++;
			}
			if(x < k - 1 && y < k - 2 && b[x + 1][y + 2] == 0)
			{
				queue[rear].x = x + 1;
				queue[rear].y = y + 2;
				queue[rear].z = z + 1;
				b[x + 1][y + 2] = 1;
				rear++;
			}
			if(x < k - 1 && y > 1 && b[x + 1][y - 2] == 0)
			{
				queue[rear].x = x + 1;
				queue[rear].y = y - 2;
				queue[rear].z = z + 1;
				b[x + 1][y - 2] = 1;
				rear++;
			}
			if(x < k - 2 && y > 0 && b[x + 2][y + 1] == 0)
			{
				queue[rear].x = x + 2;
				queue[rear].y = y + 1;
				queue[rear].z = z + 1;
				b[x + 2][y + 1] = 1;
				rear++;
			}
			if(x < k - 2 && y > 1 && b[x + 2][y - 1] == 0)
			{
				queue[rear].x = x + 2;
				queue[rear].y = y - 1;
				queue[rear].z = z + 1;
				b[x + 2][y - 1] = 1;
				rear++;
			}
		}
		printf("%d\n", z);
	}
	return (0);
}
