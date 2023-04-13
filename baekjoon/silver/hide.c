#include <stdio.h>

struct p{
	int x;
	int y;
};

int visit[100001] = {0,};

int main(void)
{
	int n,k;
	scanf("%d %d",&n,&k);
	int front = 0,rear = 0;
	int x, y;
	struct p queue[1000001] = {0,};
	queue[rear].x = n;
	queue[rear].y = 0;
	rear++;
	visit[n] = 1;
	while(front < rear)
	{
		x = queue[front].x;
		y = queue[front].y;
		front++;
		if(x == k)
			break;
		if(x > 0 && visit[x - 1] == 0)
		{
			queue[rear].x = x - 1;
			queue[rear].y = y + 1;
			visit[x - 1] = 1;
			rear++;
		}
		if(x < 100000 && visit[x + 1] == 0)
		{
			queue[rear].x = x + 1;
			queue[rear].y = y + 1;
			visit[x + 1] = 1;
			rear++;
		}
		if(x <= 50000 && visit[2 * x] == 0)
		{
			queue[rear].x = 2 * x;
			queue[rear].y = y + 1;
			visit[2 * x] = 1;
			rear++;
		}
	}
	printf("%d",y);
	return (0);
}
