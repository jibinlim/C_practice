#include <stdio.h>

struct p{
	int x;
	int t;
};

int main(void)
{
	int n;
	scanf("%d",&n);

	struct p queue[100001];
	int visit[10001] = {0,};

	visit[n] = 1;
	int front = 0, rear = 1;
	int x,t;
	queue[0].x = n;
	queue[0].t = 0;
	while(front < rear)
	{
		x = queue[front].x;
		t = queue[front].t;
		printf("%d ",x);
		front++;
		if(x == 1)
			break;
		if(x % 3 == 0 && visit[x / 3] == 0)
		{
			queue[rear].x = x / 3;
			queue[rear].t = t + 1;
			visit[x / 3] = 1;
			rear++;
		}
		if(x % 2 == 0 && visit[x / 2] == 0)
		{
			queue[rear].x = x / 2;
			queue[rear].t = t + 1;
			visit[x / 2] = 1;
			rear++;
		}
		if(x - 1 >= 1 && visit[x - 1] == 0)
		{
			queue[rear].x = x - 1;
			queue[rear].t = t + 1;
			visit[x - 1] = 1;
			rear++;
		}
	}
	printf("%d",t);
	return (0);
}
