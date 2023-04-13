#include <stdio.h>

struct p{
	int x;
	int b;
};

int main(void)
{
	int f,s,g,u,d;
	scanf("%d %d %d %d %d",&f,&s,&g,&u,&d);

	struct p queue[1000001];
	int visit[1000001];
	int x,b;
	int front = 0,rear = 0;
	int c = 1;
	queue[rear].x = s;
	queue[rear].b = 0;
	visit[s] = 1;
	rear++;
	while(front < rear)
	{
		x = queue[front].x;
		b = queue[front].b;
		front++;
		if(x == g)
		{
			c = 0;
			break;
		}
		if(x + u <= f && visit[x + u] == 0)
		{
			queue[rear].x = x + u;
			queue[rear].b = b + 1;
			rear++;
			visit[x + u] = 1;
		}
		if(x - d >= 1 && visit[x - d] == 0)
		{
			queue[rear].x = x - d;
			queue[rear].b = b + 1;
			rear++;
			visit[x - d] = 1;
		}
	}
	if(c == 0)
		printf("%d\n",b);
	else
		printf("use the stairs\n");
	return (0);
}
