#include <stdio.h>

int main(void)
{
	int k;
	scanf("%d",&k);

	int dir[6];
	int len[6];
	int size[7];
	int farm = 0;
	int wmax = 0;
	int hmax = 0;
	int i;

	for(i = 0; i < 6; i++)
	{
		scanf("%d %d",&dir[i],&len[i]);

		if(dir[i] == 1 || dir[i] == 2)
		{
			if(len[i] > wmax)
				wmax = len[i];
		}
		else
		{
			if(len[i] > hmax)
				hmax = len[i];
		}
	}

	for(int i = 0; i < 5; i++)
	{
		size[i] = len[i] * len[i + 1];
		farm += size[i];
	}
	size[6] = len[0] * len[5];
	farm += size[6];
	farm -= wmax * hmax * 2;
	printf("%d\n",farm * k);
	return (0);

}
