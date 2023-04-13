#include <stdio.h>

int h,w;

void dfs(int map[50][50],int i, int j)
{
	map[i][j] = 0;
	int mo[8] = {1, 1, 0, -1, -1, -1, 0, 1};
	int ve[8] = {0, 1, 1, 1, 0, -1, -1, -1};

	for(int a = 0; a < 8; a++)
	{
		int dx = i + mo[a];
		int dy = j + ve[a];

		if(dx < 0 || dy < 0 || dx >= h || dy >= w)
			continue;
		if(map[dx][dy] == 1)
			dfs(map,dx,dy);
	}
}


int main(void)
{
	while(1)
	{
		scanf("%d %d",&w,&h);
		if(w == 0 && h == 0)
			break;
		int map[50][50];

		for(int i = 0; i < h; i++)
			for(int j = 0; j < w; j++)
				scanf("%d",&map[i][j]);

		int count = 0;

		for(int i = 0; i < h; i++)
			for(int j = 0; j < w; j++)
			{
				if(map[i][j] == 1)
				{
					dfs(map,i,j);
					count++;
				}
			}
		printf("%d\n",count);
	}
	return (0);
}

