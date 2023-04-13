#include <stdio.h>
#include <stdlib.h>
int *q;
int n;

void left(void)
{
	int temp;
	temp = q[0];
	for(int i = 1; i < n; i++)
		q[i - 1] = q[i];
	q[n - 1] = temp;
}
void right(void)
{
	int temp;
	temp = q[n - 1];
	for(int i = n - 2; i >= 0; i--)
		q[i + 1] = q[i];
	q[0] = temp;
}
void ext(void)
{
	for(int i = 1; i < n; i++)
		q[i - 1] = q[i];
	n--;
}

int main(void)
{
	int m;
	int *t;
	int count = 0;
	int j = 0;
	int i = 0;

	scanf("%d %d",&n,&m);
	q = (int *) malloc (sizeof(int) * n);
	t = (int *) malloc (sizeof(int) * m);

	for(i = 0; i < n; i++)
		q[i] = i + 1;

	for(i = 0; i < m; i++)
		scanf("%d",t+i);
	i = 0;
	while(j < m)
	{
		while(t[j] == q[0])
		{
			ext();
			j++;
			if(j == m)
				break;
		}
		if(j == m)
			break;
		i = 0;
		while(t[j] != q[i])
			i++;
		if(i - 0 <= n - i)
		{
			left();
			i--;
			count++;
		}
		else
		{
			right();
			i++;
			if(i == n)
				i = 0;
			count++;
		}
	}
	printf("%d",count);
	free(q);
	free(t);
	return (0);
}
