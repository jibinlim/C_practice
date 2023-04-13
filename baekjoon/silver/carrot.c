#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	int r;
	int c;
	int **b;

	scanf("%d %d %d",&n,&r,&c);

	b = (int **) malloc (sizeof(int *) * n);

	for(int i = 0; i < n; i++)
	{
		b[i] = (int *) malloc (sizeof(int) * n);
		for(int j = 0; j < n; j++)
			b[i][j] = 0;
	}
	b[r - 1][c - 1] = 1;

	if((r - 1) % 2 == 0)
	{
		if((c - 1) % 2 == 0)
		{
			for(int i = 0; i < n; i++)
				for(int j = 0; j < n; j++)
				{
					if(i % 2 == 0)
					{
						if(j % 2 == 0)
							b[i][j] = 1;
					}
					else
					{
						if(j % 2 == 1)
							b[i][j] = 1;
					}
				}
		}
		else
			for(int i = 0; i < n; i++)
				for(int j = 0; j < n; j++)
				{
					if(i % 2 == 0)
					{
						if(j % 2 == 1)
							b[i][j] = 1;
					}
					else
					{
						if(j % 2 == 0)
							b[i][j] = 1;
					}
				}
	}
	else
	{
		if((c - 1) % 2 == 0)
		{
			for(int i = 0; i < n; i++)
				for(int j = 0; j < n; j++)
				{
					if(i % 2 == 1)
					{
						if(j % 2 == 0)
							b[i][j] = 1;
					}
					else
						if(j % 2 == 1)
							b[i][j] = 1;
				}
		}
		else
			for(int i = 0; i < n; i++)
				for(int j = 0; j < n; j++)
				{
					if(i % 2 == 1)
					{
						if(j % 2 == 1)
							b[i][j] = 1;
					}
					else
						if(j % 2 == 0)
							b[i][j] = 1;
				}
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(b[i][j] == 0)
				printf(".");
			else
				printf("v");
		}
		printf("\n");
		free(b[i]);
	}
	free(b);
	return (0);
}

