#include <stdio.h>
#include <stdlib.h>

struct p{
	int x;
	int y;
	int z;
	int t;
};

int main(void)
{
	while(1)
	{
		int l,r,c;
		scanf("%d %d %d",&l,&r,&c);
		if(l == 0 && r == 0 && c == 0)
			break;

		int front = 0,rear = 1;
		int x,y,z,t;
		struct p *queue = (struct p*) malloc (sizeof(struct p) * (l * r * c));
		int ***visit = (int ***) malloc (sizeof(int **) * l);
		char ***b = (char ***) malloc (sizeof(char **) * (l + 1));
		for(int i = 0; i < l; i++)
		{
			visit[i] = (int **) malloc (sizeof(int *) * r);
			b[i] = (char **) malloc (sizeof(char *) * (r + 1));
			for(int j = 0; j < r; j++)
			{
				visit[i][j] = (int *) malloc (sizeof(int) * c);
				b[i][j] = (char *) malloc (sizeof(char) * (c + 1));
				scanf("%s",b[i][j]);
			}
			for(int j = 0; j < r; j++)
			{
				for(int k = 0; k < c; k++)
				{
					visit[i][j][k] = 0;
					if(b[i][j][k] == 'S')
					{
						queue[0].x = i;
						queue[0].y = j;
						queue[0].z = k;
						queue[0].t = 0;
					}
				}
			}
		}
		int m[6] = {1,-1,0,0,0,0};
		int v[6] = {0,0,-1,1,0,0};
		int e[6] = {0,0,0,0,-1,1};
		int ans = 0;
		while(front < rear)
		{
			x = queue[front].x;
			y = queue[front].y;
			z = queue[front].z;
			t = queue[front].t;
			front++;
			if(b[x][y][z] == 'E')
			{
				ans = 1;
				break;
			}
			for(int i = 0; i < 6; i++)
			{
				int dx = x + m[i];
				int dy = y + v[i];
				int dz = z + e[i];

				if(dx < 0 || dy < 0 || dz < 0 || dx > l - 1 || dy > r - 1 || dz > c - 1)
					continue;
				if(visit[dx][dy][dz] == 0 && b[dx][dy][dz] != '#')
				{
					visit[dx][dy][dz] = 1;
					queue[rear].x = dx;
					queue[rear].y = dy;
					queue[rear].z = dz;
					queue[rear].t = t + 1;
					rear++;
				}
			}
		}
		if(ans == 0)
			printf("Trapped!\n");
		else
			printf("Escaped in %d minute(s).\n",t);
		for(int i = 0; i < l; i++)
		{
			for(int j = 0; j < r; j++)
			{
				free(visit[i][j]);
				free(b[i][j]);
			}
			free(visit[i]);
			free(b[i]);
		}
		free(b);
		free(visit);
		free(queue);
	}
	return (0);
}
