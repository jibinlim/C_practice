#include <stdio.h>
#include <math.h>


int main(void)
{
	int t;
	scanf("%d",&t);

	for(int i = 0; i < t; i++)
	{
		unsigned int now,des;
		scanf("%d %d",&now,&des);
		int dis = des - now;
		int root = (int)sqrt(dis);
		int count = 2 * root - 1;
		int square = root * root;

		if(dis - square == 0)
			count = 2 * root - 1;
		else if(dis - square <= root)
			count++;
		else
			count += 2;
		printf("%d\n",count);
	}
	return (0);
}
