#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n,m;
	scanf("%d %d",&n,&m);
	int **city;
	int rm = 0;

	city = (int **) malloc (sizeof(int *) * n);
	for(int i = 0; i < n; i++)
	{
		city[i] = (int *) malloc (sizeof(int) * n);
		for(int j = 0; j < n; j++)
		{
			scanf("%d",&city[i][j]);
			if(city[i][j] == 2)
				rm++;
		}
	}
