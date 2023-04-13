#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n,m;
	scanf("%d %d",&n,&m);
	int r,c,d;
	scanf("%d %d %d",&r,&c,&d);
	int **room;
	int count = 0;
	int x = 0;
	int mo[4] = {-1,0,1,0};
	int ve[4] = {0,1,0,-1};

	room = (int **) malloc(sizeof(int *) * n);
	for(int i = 0; i < n; i++)
	{
		room[i] = (int *) malloc (sizeof(int) * m);
		for(int j = 0; j < m; j++)
			scanf("%d",&room[i][j]);
	}

	while(1)
	{
		if(room[r][c] == 0)
			count++;
		room[r][c] = 2;
		x = 0;
		d--;
		if(d < 0)
			d = 3;
		while(room[r + mo[d]][c + ve[d]] != 0)
		{
			d--;
			if(d < 0)
				d = 3;
			x++;
			if(x >= 4)
			{
				d++;
				if(d >= 4)
					d = 0;
				break;
			}
		}
		if(room[r + mo[d]][c + ve[d]] == 0)
		{
			r += mo[d];
			c += ve[d];
			continue;
		}
		if(x >= 4)
		{
			if(room[r - mo[d]][c - ve[d]] == 1)
				break;
			else
			{
				r -= mo[d];
				c -= ve[d];
			}
		}
	}
	for(int i = 0; i < n; i++)
		free(room[i]);
	free(room);
	printf("%d\n",count);
	return (0);
}
