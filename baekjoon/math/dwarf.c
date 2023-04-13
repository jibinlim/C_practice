#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	if(*(int *)a > *(int *)b)
		return 1;
	else if(*(int *)a < *(int *)b)
		return -1;
	else
		return 0;
}

int main(void)
{
	int dwarf[9];
	int sum = 0;
	int count = 0;
	int x,y;

	for(int i = 0; i < 9; i++)
	{
		scanf("%d",&dwarf[i]);
		sum += dwarf[i];
	}

	qsort(dwarf,9,sizeof(int),cmp);

	count = sum - 100;
	for(int i = 0; i < 9; i++)
		for(int j = i + 1; j < 9; j++)
		{
			if(dwarf[i] + dwarf[j] == count)
			{
				x = i;
				y = j;
				break;
			}
		}
	for(int i = 0; i < 9; i++)
		if(!(i == x || i == y))
			printf("%d\n",dwarf[i]);
	return (0);
}
