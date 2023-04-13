#include <stdio.h>
#include <stdlib.h>

struct p{
	int x;
	int y;
	int t;
};

int main(void)
{
	int r,c;
	scanf("%d %d",&r,&c);

	struct p j_queue[1001];
	struct p f_queue[1001];
	int jf,jr;
	int ff,fr = 0;
	int jx,jy;
	int fx,fy;
	char **maze = (char **) malloc (sizeof(char *) * (r + 1));
	for(int i = 0; i < r; i++)
	{
		maze[i] = (char *) malloc (sizeof(char) * (c + 1));
		scanf("%s",maze[i]);
		for(int j = 0; j < c; j++)
		{
			if(maze[i][j] == 'J')
			{
				jx = i;
				jy = j;
			}
			if(maze[i][j] == 'F')
			{
				f_queue[fr].x = i;
				f_queue[fr].y = j;
				f_queue[fr].t = 0;
				fr++;
			}
		}
	}
	jf = 0;
	jr = 1;
	ff = 0;
	int jt,ft;
	int mo[4] = {0,0,-1,1};
	int ve[4] = {-1,1,0,0};
	j_queue[0].x = jx;
	j_queue[0].y = jy;
	j_queue[0].t = 0;
	int k = 0;
	int count = 1;
	while(1)
	{
		while(jf < jr)
		{
			if(j_queue[jf].t == count)
				break;
			jx = j_queue[jf].x;
			jy = j_queue[jf].y;
			jt = j_queue[jf].t;
			jf++;
			if(maze[jx][jy] == 'F')
				continue;
			for(int i = 0; i < 4; i++)
			{
				int dx = jx + mo[i];
				int dy = jy + ve[i];
				if(dx < 0 || dy < 0 || dx > r - 1 || dy > c - 1)
				{
					k = 1;
					break;
				}
				if(maze[dx][dy] == '.')
				{
					maze[jx][jy] = 'x';
					j_queue[jr].x = dx;
					j_queue[jr].y = dy;
					j_queue[jr].t = jt + 1;
					maze[dx][dy] = 'J';
					jr++;
				}
			}
		}
		if(k == 1)
			break;
		while(ff < fr)
		{
			if(f_queue[ff].t == count)
				break;
			fx = f_queue[ff].x;
			fy = f_queue[ff].y;
			ft = f_queue[ff].t;
			ff++;
			for(int i = 0; i < 4; i++)
			{
				int dx = fx + mo[i];
				int dy = fy + ve[i];

				if(dx < 0 || dy < 0 || dx > r - 1 || dy > c - 1)
					continue;
				if(maze[dx][dy] != 'F' && maze[dx][dy] != '#')
				{
					f_queue[fr].x = dx;
					f_queue[fr].y = dy;
					f_queue[fr].t = ft + 1;
					maze[dx][dy] = 'F';
					fr++;
				}
			}
		}
		for(int i = 0; i < r; i++)
		{
			k = 2;
			for(int j = 0; j < c; j++)
			{
				if(maze[i][j] == 'J')
				{
					k = 0;
					break;
				}
			}
			if(k == 0)
				break;
		}
		count++;
		if(k == 2 || jf >= jr && ff >= fr)
		{
			printf("IMPOSSIBLE\n");
			break;
		}
		printf("\n");
		for(int i = 0; i < r; i++)
		{
			for(int j = 0; j < c; j++)
			{
				printf("%c",maze[i][j]);
			}
			printf("\n");
		}
	}
	if(k == 1)
		printf("%d\n",count);
	for(int i = 0; i < r; i++)
		free(maze[i]);
	free(maze);
	return (0);
}
