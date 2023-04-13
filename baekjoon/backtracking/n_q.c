#include <stdio.h>
#include <stdlib.h>

void set(int i,int *count,int *pos,int *flag_a,int *flag_b, int *flag_c,int n)
{
	for(int j = 0; j < n; j++)
	{
		if(!flag_a[j] && !flag_b[i + j] && !flag_c[i - j + n - 1])
		{
			pos[i] = j;
			if(i == n - 1)
				(*count)++;
			else
			{
				flag_a[j] = flag_b[i + j] = flag_c[i - j + n - 1] = 1;
				set(i + 1,count,pos,flag_a,flag_b,flag_c,n);
				flag_a[j] = flag_b[i + j] = flag_c[i - j + n - 1] = 0;
			}
		}
	}
}

int main(void)
{
	int count;
	count = 0;
	int n;
	scanf("%d",&n);
	int *pos;
	int *flag_a;
	int *flag_b;
	int *flag_c;
	pos = (int *) malloc (sizeof(int) * n);
	flag_a = (int *) malloc (sizeof(int) * n);
	flag_b = (int *) malloc (sizeof(int) * 2 * n - 1);
	flag_c = (int *) malloc (sizeof(int) * 2 * n - 1);
	for(int i = 0; i < n; i++)
		flag_a[i] = 0;
	for(int i = 0; i < 2 * n - 1; i++)
		flag_b[i] = flag_c[i] = 0;
	set(0,&count,pos,flag_a,flag_b,flag_c,n);
	printf("%d\n",count);

	return (0);
}
