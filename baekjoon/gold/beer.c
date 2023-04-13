#include <stdio.h>
#include <stdlib.h>

struct p{
	int x;
	int y;
};

int dis(int a, int b)
{
	if(a > b)
		return a - b;
	else
		return b - a;
}

int main(void)
{
	int tc;
	scanf("%d",&tc);

	for(int aa = 0; aa < tc; aa++)
	{
		int n;
		scanf("%d",&n);

		int hx,hy;
		int *cx,*cy;
		int rx,ry;
		cx = (int *) malloc (sizeof(int) * n);
		cy = (int *) malloc (sizeof(int) * n);

		int f = 0, r = 0;
		struct p* queue = (struct p*) malloc (sizeof(struct p) * n);
		int *visit = (int *) malloc (sizeof(int) * n);
		scanf("%d %d",&hx,&hy);
		int z = 0;
		for(int i = 0; i < n; i++)
		{
			scanf("%d %d",&cx[i],&cy[i]);
			visit[i] = 0;
			if(dis(cx[i],hx) + dis(cy[i],hy) <= 1000)
			{
				queue[r].x = cx[i];
				queue[r].y = cy[i];
				visit[i] = 1;
				r++;
			}
		}
		scanf("%d %d",&rx,&ry);
		if(dis(hx,rx) + dis(hy,ry) <= 1000)
			z = 1;
		int x,y,beer;
		while(f < r && z == 0)
		{
			x = queue[f].x;
			y = queue[f].y;
			f++;
			if(dis(rx,x) + dis(ry,y) <= 1000)
			{
				z = 1;
				break;
			}
			for(int i = 0; i < n; i++)
			{
				if(visit[i] == 0 && dis(x,cx[i]) + dis(y,cy[i]) <= 1000)
				{
					queue[r].x = cx[i];
					queue[r].y = cy[i];
					r++;
					visit[i] = 1;
				}
			}
		}
		if(z == 1)
			printf("happy\n");
		else
			printf("sad\n");
		free(cx);
		free(cy);
		free(queue);
		free(visit);
	}
	return (0);
}
