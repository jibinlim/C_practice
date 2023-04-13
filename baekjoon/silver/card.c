#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	scanf("%d",&n);

	int *c;
	c = (int *) malloc (sizeof(int) * 1000001);
	int front = 0;
	int rear = 0;

	for(int i = 0; i < n; i++)
	{
		c[i] = i + 1;
		rear++;
	}
	while(n > 1)
	{
		front++;
		c[rear] = c[front];
		rear++;
		front++;
		n--;
	}

	printf("%d",c[front]);
	free(c);
	return (0);
}
