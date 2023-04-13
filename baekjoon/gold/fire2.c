#include <stdio.h>
#include <stdlib.h>

struct p{
	int x;
	int y;
	int t;
};


int main(void)
{
	int time;
	scanf("%d",&time);

	for(int aa = 0; aa < time; aa++)
	{
		int w,h;
		scanf("%d %d",&w,&h);

		int sf = 0,sr = 0,ff = 0,fr = 0;
		int x,y,t;
		struct p *s_queue = (struct p*) malloc (sizeof(struct p) * (w * h));
		struct p *f_queue = (struct p*) malloc (sizeof(struct p) * (w * h));
		char** buil = (char **) malloc (sizeof(char *) * (h + 1));

		for(int i = 0; i < h; i++)
		{
			buil[i] = (char *) malloc (sizeof(char) * (w + 1));
			scanf("%s",buil[i]);

			for(int j = 0; j < w; j++)
			{
				if(buil[i][j] == '*')
				{
					f_queue[fr].x = i;
					f_queue[fr].y = j;
					f_queue[fr].t = 0;
					fr++;
				}
				if(buil[i][j] == '@')
				{
					s_queue[sr].x = i;
					s_queue[sr].y = j;
					s_queue[sr].t = 0;
					sr++;
				}
			}
		}
		int count = 1;
		int mo[4] = {0,0,-1,1};
		int ve[4] = {-1,1,0,0};
		int k = 0;
		while(1)
		{
			while(sf < sr)
			{
				if(s_queue[sf].t == count)
					break;
				x = s_queue[sf].x;
				y = s_queue[sf].y;
				t = s_queue[sf].t;
				sf++;
				if(buil[x][y] == '*')
					continue;

				for(int i = 0; i < 4; i++)
				{
					int dx = x + mo[i];
					int dy = y + ve[i];

					if(dx < 0 || dy < 0 || dx > h - 1 || dy > w - 1)
					{
						k = 1;
						break;
					}
					if(buil[dx][dy] == '.')
					{
						buil[x][y] = 'x';
						s_queue[sr].x = dx;
						s_queue[sr].y = dy;
						s_queue[sr].t = t + 1;
						sr++;
						buil[dx][dy] = '@';
					}
				}
			}
			if(k == 1)
				break;
			while(ff < fr)
			{
				if(f_queue[ff].t == count)
					break;
				x = f_queue[ff].x;
				y = f_queue[ff].y;
				t = f_queue[ff].t;
				ff++;

				for(int i = 0 ; i < 4; i++)
				{
					int dx = x + mo[i];
					int dy = y + ve[i];

					if(dx < 0 || dy < 0 || dx > h - 1 || dy > w - 1)
						continue;
					if(buil[dx][dy] != '#' && buil[dx][dy] != '*')
					{
						buil[dx][dy] = '*';
						f_queue[fr].x = dx;
						f_queue[fr].y = dy;
						f_queue[fr].t = t + 1;
						fr++;
					}
				}
			}
			if(sf >= sr)
			{
				printf("IMPOSSIBLE\n");
				break;
			}
			printf("\n");
			for(int i = 0; i < h; i++)
			{
				for(int j = 0; j < w; j++)
					printf("%c",buil[i][j]);
				printf("\n");
			}
			count++;
		}
		if(k == 1)
			printf("%d\n",count);
		free(s_queue);
		free(f_queue);
		for(int i = 0; i < h; i ++)
			free(buil[i]);
		free(buil);
	}
	return (0);
}
