#include <stdio.h>
#include <stdlib.h>

int chess(char **c, int a, int b)
{
	char cas_1[9][9] = {"WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW"};
	char cas_2[9][9] = {"BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB"};
	int x = 0;
	int y = 0;
	int count_1 = 0;
	int count_2 = 0;
	for(int i = a; i < a + 8; i++)
	{
		y = 0;
		for(int j = b; j < b + 8; j++)
		{
			if(cas_1[x][y] != c[i][j])
				count_1++;
			y++;
		}
		x++;
	}
	x = 0;
	y = 0;
	for(int i = a; i < a + 8; i++)
	{
		y = 0;
		for(int j = b; j < b + 8; j++)
		{
			if(cas_2[x][y] != c[i][j])
				count_2++;
			y++;
		}
		x++;
	}
	if(count_1 > count_2)
		return (count_2);
	return (count_1);
}

int main(void)
{
	int n;
	int m;
	char **c;
	scanf("%d %d",&n,&m);
	c = (char **) malloc (sizeof(char *) * (n + 1));
	for(int i = 0; i < n; i++)
	{
		c[i] = (char *) malloc (sizeof(char) * (m + 1));
		scanf("%s",c[i]);
	}
	int min = 64;
	for(int i = 0; i <= n - 8; i++)
		for(int j = 0; j <= m - 8; j++)
			if(chess(c,i,j) < min)
				min = chess(c,i,j);
	printf("%d",min);
	for(int i =0; i < n; i++)
		free(c[i]);
	free(c);
	return (0);
}
