#include <stdio.h>

int main(void)
{
	int in,out;

	int cun = 0;
	int max = 0;

	for(int i = 0; i < 10; i++)
	{
		scanf("%d %d",&out,&in);
		cun -= out;
		cun += in;
		if(cun > max)
			max = cun;
	}
	printf("%d\n",max);
	return (0);
}
