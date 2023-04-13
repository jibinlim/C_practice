#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int arr[28];
	int man[30];

	int j = 0;
	int x[2];
	for(int i = 0; i < 30; i++)
		man[i] = 0;
	for(int i = 0; i < 28; i++)
	{
		scanf("%d",&arr[i]);
		man[arr[i] - 1]++;
	}
	for(int i = 0; i < 30; i++)
		if(man[i] == 0)
		{
			x[j] = i+1;
			j++;
		}
	for(int i = 0; i < 2; i++)
		printf("%d\n",x[i]);
	return (0);
}
