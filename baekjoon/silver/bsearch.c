#include <stdio.h>
#include <stdlib.h>

struct z{
	int q;
	int index;
};

int binary(struct z *x, int start, int end, int ky)
{
	int middle = (start + end) / 2;
	if(start <= end)
	{
		if(ky < x[middle].q)
			return binary(x,start,middle - 1,ky);
		else if (ky > x[middle].q)
			return binary(x,middle + 1, end, ky);
		else
			return x[middle].index;
	}
	else
		return -1;
}

int cmp(const void *a, const void *b)
{
	struct z *x = (struct z *)a;
	struct z *y = (struct z *)b;
	return (x -> q - y -> q);
}


int main(void)
{
	int i,nx,ky;
	struct z *x;
	int p;
	printf("요소 개수 :");
	scanf("%d",&nx);
	x = (struct z *) malloc (sizeof(struct z) * nx);

	for(int i = 0; i < nx; i++)
	{
		scanf("%d",&x[i].q);
		x[i].index = i + 1;
	}
	qsort(x,nx,sizeof(struct z),cmp);
	printf("검색 값:");
	scanf("%d",&ky);
	p = binary(x, 0, nx - 1, ky);
	if(p == -1)
		printf("없음");
	else
		printf("%d에 있던거임!", p);
	free(x);
	return (0);
}
