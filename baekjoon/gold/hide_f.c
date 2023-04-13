#include <stdio.h>

struct p{
	int x;
	int t;
};

int main(void)
{
	int n,k;
	scanf("%d %d",&n,&k);

	struct p queue[100001] = {0,};
	int visit[100001] = {0,};
	int front = 0,rear = 0;
	int x,t;
	x = n;
	t = 0;
	queue[rear].x = x;
	queue[rear].t = t;
	visit[x] = 1;
	rear++;
	while(rear > front)
	{
		x = queue[front].x;
		t = queue[front].t;
		front++;
		if(x == k)
			break;
		if(2 * x <= 100000 && visit[2 * x] == 0)
		{
			queue[rear].x = 2 * x;
			queue[rear].t = t;
			rear++;
			visit[2 * x] = 1;
		}
		if(x > 0 && visit[x - 1] == 0)
		{
			queue[rear].x = x - 1;
			queue[rear].t = t + 1;
			rear++;
			visit[x - 1] = 1;
		}
		if(x < 100000 && visit[x + 1] == 0)
		{
			queue[rear].x = x + 1;
			queue[rear].t = t + 1;
			rear++;
			visit[x + 1] = 1;
		}
	}
	printf("%d\n",t);
	return (0);
}
