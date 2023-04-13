#include <stdio.h>
#include <stdlib.h>

int c[3] = {0,0,0};

void paper(int **p, int x, int y, int n)
{
	int f = p[x][y];
	int flag = 0;

	for(int i = x; i < x + n; i++)
		for(int j = y; j < y + n; j++)
			if(f != p[i][j])
			{
				flag = 1;
				break;
			}

	if(flag == 0)
	{
		if(f == 0)
			c[1]++;
		else if(f == -1)
			c[0]++;
		else
			c[2]++;
	}
	else
	{
		paper(p, x, y, n / 3);
		paper(p, x + n / 3, y, n / 3);
		paper(p, x + 2 * n / 3, y, n / 3);
		paper(p, x, y + n / 3, n / 3);
		paper(p, x, y + 2 * n / 3, n / 3);
		paper(p, x + n / 3, y + 2 * n / 3, n / 3);
		paper(p, x + n / 3, y + n / 3, n / 3);
		paper(p, x + 2 * n / 3, y + n / 3, n / 3);
		paper(p, x + 2 * n / 3, y + 2 * n / 3, n / 3);
	}
}


int main(void)
{
	int n;
	scanf("%d",&n);


	int **p;
	p = (int **) malloc (sizeof(int *) * n);

	for(int i = 0; i < n; i++)
	{
		p[i] = (int *) malloc (sizeof(int) * n);
		for(int j = 0; j < n; j++)
			scanf("%d",&p[i][j]);
	}

	paper(p,0,0,n);

	for(int i = 0; i < 3; i++)
		printf("%d\n",c[i]);
	for(int i = 0; i < n; i++)
		free(p[i]);
	free(p);
	return (0);
}
