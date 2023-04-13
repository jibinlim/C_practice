#include <stdio.h>
#include <stdlib.h>

struct po {
	int x;
	int y;
};

int cmp(const void *a, const void *b)
{
	if(*(int *) a > *(int *)b)
		return (1);
	else if (*(int *)a < *(int *)b)
		return (-1);
	else
		return (0);
}

int main(void)
{
	int n;
	scanf("%d", &n);

	int **ap;

	int c[1000] = {0, };
	int s[1000] = {0, };
	int k[1000] = {0, };
	int front = 0, rear = 0;
	int x = 0, y = 0;
	int t = 0, a = 0;
	int max = 0;
	int count = 1;
	int b = 0;
	struct po queue[10001] = {0,};

	ap = (int **) malloc (sizeof(int *) * n);
	for(int i = 0; i < n; i++)
	{
		ap[i] = (int *) malloc (sizeof(int) * n);
		for(int j = 0; j < n; j++)
		{
			scanf("%1d",&ap[i][j]);
			if(ap[i][j] == 1)
			{
				s[t] = i;
				k[t] = j;
				t++;
			}
		}
	}
	ap[s[0]][k[0]] = 2;
	x = s[0];
	y = k[0];
	rear++;
	while(a < t)
	{
		front = 0;
		rear = 1;
		queue[front].x = x;
		queue[front].y = y;
		while(front < rear)
		{
			x = queue[front].x;
			y = queue[front].y;
			front++;
			if(x < n - 1 && ap[x + 1][y] == 1)
			{
				queue[rear].x = x + 1;
				queue[rear].y = y;
				ap[x + 1][y] = ap[x][y] + 1;
				count ++;
				rear++;
			}
			if(x > 0 && ap[x - 1][y] == 1)
			{
				queue[rear].x = x - 1;
				queue[rear].y = y;
				ap[x - 1][y] = ap[x][y] + 1;
				rear++;
				count ++;
			}
			if(y < n - 1 && ap[x][y + 1] == 1)
			{
				queue[rear].x = x;
				queue[rear].y = y + 1;
				ap[x][y + 1] = ap[x][y] + 1;
				rear++;
				count ++;
			}
			if(y > 0 && ap[x][y - 1] == 1)
			{
				queue[rear].x = x;
				queue[rear].y = y - 1;
				ap[x][y - 1] = ap[x][y] + 1;
				rear++;
				count++;
			}
			if(max < count)
				max = count;
		}
		if(max != 0)
		{
			c[b] = max;
			b++;
		}
		count = 0;
		max = 0;
		a++;
		x = s[a];
		y = k[a];
		if(ap[x][y] == 1)
		{
			ap[x][y] = 2;
			count++;
		}
	}
	qsort(c,b,sizeof(int),cmp);
	printf("%d\n",b);
	for(int i = 0; i < b; i++)
		printf("%d\n",c[i]);
	for(int i = 0; i < n; i++)
		free(ap[i]);
	free(ap);
	return (0);
}
