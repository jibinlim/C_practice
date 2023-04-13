#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	scanf("%d",&n);
	int *bln;
	bln = (int *) malloc (sizeof(int) * n);
	int i = 0;
	int j = 0;
	int index = 0;

	for(i = 0 ; i < n; i++)
		scanf("%d",&bln[i]);

	i = 0;

	while(j < n - 1)
	{
		printf("%d ",i + 1);
		while(bln[i] > 0)
		{
			index++;
			if(index == n)
				index = 0;
			while(bln[index] == 0 || i == index)
			{
				index++;
				if(index == n)
					index = 0;
			}
			bln[i]--;
		}
		while(bln[i] < 0)
		{
			index--;
			if(index <= 0)
				index = n - 1;
			while(bln[index] == 0 || i == index)
			{
				index--;
				if(index == 0)
					index = n - 1;
			}
			bln[i]++;
		}
		i = index;
		j++;
	}
	printf("%d",i + 1);
	free(bln);
	return (0);
}

