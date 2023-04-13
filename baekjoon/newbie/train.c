#include <stdio.h>

int main(void)
{
	int in,out;
	int max = 0;
	int cun = 0;

	for(int i = 0; i < 4; i++)
	{
		scanf("%d %d",&out,&in);
		cun += in;
		cun -= out;
		if(max < cun)
			max = cun;
	}

	printf("%d\n",max);
	return (0);
}
