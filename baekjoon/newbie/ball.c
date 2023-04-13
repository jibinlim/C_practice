#include <stdio.h>

int main(void)
{
	int m;
	scanf("%d",&m);
	int cup[4] = {0,};
	cup[1] = 1;

	int temp;
	int x,y;

	for(int i = 0; i < m; i++)
	{
		scanf("%d %d",&x,&y);
		temp = cup[x];
		cup[x] = cup[y];
		cup[y] = temp;
	}
	for(int i = 1; i <= 3; i++)
		if(cup[i] == 1)
			printf("%d\n",i);
	return (0);
}
