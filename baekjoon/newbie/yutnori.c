#include <stdio.h>

int main(void)
{
	int y1,y2,y3,y4;
	int z[2] = {0,};

	for(int i = 0; i < 3; i++)
	{
		scanf("%d %d %d %d",&y1,&y2,&y3,&y4);
		z[y1]++;
		z[y2]++;
		z[y3]++;
		z[y4]++;
		if(z[0] == 1)
			printf("A\n");
		else if(z[0] == 2)
			printf("B\n");
		else if(z[0] == 3)
			printf("C\n");
		else if(z[0] == 4)
			printf("D\n");
		else if(z[0] == 0)
			printf("E\n");
		z[0] = 0;
		z[1] = 0;
	}
	return (0);
}
