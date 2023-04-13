#include <stdio.h>

int main(void)
{
	int paper[100][100];
	int t;
	int n;
	int m;
	int count;

	scanf("%d",&t);

	for(int i = 0; i < 100; i++)
		for(int j = 0; j < 100; j++)
			paper[i][j] = 0;
	for(int i = 0; i < t; i++)
	{
		scanf("%d %d",&n,&m);
		for(int j = m - 1; j - m + 1< 10; j++)
			for(int k = n - 1; k - n + 1 < 10; k++)
				paper[j][k] = 1;
	}
	count = 0;
	for(int i = 0 ; i < 100; i++)
		for(int j = 0; j < 100; j++)
			if(paper[i][j] == 1)
				count++;
	printf("%d",count);

	return (0);
}
