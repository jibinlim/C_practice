#include <stdio.h>
#include <stdlib.h>
struct p{
	int x;
	int y;
};

int cmp(const void *a,const void *b)
{
	struct p *v = (struct p*) a;
	struct p *w = (struct p*) b;
	if(v -> y > w -> y)
		return 1;
	else if(v -> y < w -> y)
		return -1;
	else
		return (v -> x - w -> x);
}

int main(void)
{
	int n;
	scanf("%d",&n);
	struct p *a;

	a = (struct p *) malloc (sizeof(struct p) * n);

	int i;
	for(i = 0; i < n; i++)
		scanf("%d %d",&a[i].x, &a[i].y);
	int j = 0;
	int count = 1;
	i = 1;

	qsort(a,n,sizeof(struct p),cmp);

	while(i < n)
	{
		if(a[j].y <= a[i].x)
		{
			j = i;
			count++;
		}
		i++;
	}
	printf("%d",count);
	free(a);
	return (0);
}
