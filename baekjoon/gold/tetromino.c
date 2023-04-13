#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n,m;
	scanf("%d %d",&n,&m);
	int **map;
	map = (int **) malloc (sizeof(int *) * n);
	int te[19][4] = {{0,0,0,0},{0,1,2,3},{0,1,0,1},{0,0,1,2},{0,1,1,1},{0,1,1,1},{0,0,0,1},{0,0,0,1},{0,1,2,2},{0,1,2,2},{0,0,1,0},{0,1,1,2},{0,0,1,2},{0,1,1,1},{0,1,1,2},{0,0,1,1},{0,0,1,1},{0,1,1,2},{0,1,1,2}};
	int ro[19][4] = {{0,1,2,3},{0,0,0,0},{0,0,1,1},{0,1,0,0},{0,0,-1,-2},{0,0,1,2},{0,1,2,0},{0,-1,-2,0},{0,0,0,1},{0,0,0,-1},{0,1,1,2},{0,0,1,0},{0,-1,0,0},{1,0,1,2},{0,0,-1,0},{0,1,1,2},{1,2,0,1},{1,1,0,0},{0,0,1,1}};

	for(int i = 0 ; i < n; i++)
	{
		map[i] = (int *) malloc (sizeof(int) * m);
		for(int j = 0; j < m; j++)
			scanf("%d",&map[i][j]);
	}
	int max = 0;
	int sum = 0;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			for(int k = 0; k < 19; k++)
			{
				sum = 0;
				for(int t = 0; t < 4; t++)
				{
					int dx = i + ro[k][t];
					int dy = j + te[k][t];

					if(dx < 0 || dy < 0 || dx > n - 1|| dy > m - 1)
						break;
					sum += map[dx][dy];
				}
				if(sum > max)
					max = sum;
			}
		}
	}
	for(int i = 0; i < n; i++)
		free(map[i]);
	free(map);

	printf("%d\n",max);
	return (0);
}


