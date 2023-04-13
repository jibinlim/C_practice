#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a,b,c;
	int max;
	int t;
	int count = 0;
	int *ans;

	ans = (int *) malloc (sizeof(int) * 500);
	while(1)
	{
		scanf("%d %d %d",&a,&b,&c);
		if(a == 0 && b == 0 && c == 0)
			break;
		if(a > b)
		{
			if (a > c)
			{
				if(a * a == b * b + c * c)
				{
					ans[count] = 1;
					count++;
				}
				else
				{
					ans[count] = 0;
					count++;
				}
			}
		}
		if(b > a)
		{
			if(b > c)
			{
				if(b * b == a * a + c * c)
				{
					ans[count] = 1;
					count++;
				}
				else
				{
					ans[count] = 0;
					count++;
				}
			}
		}
		if(c > a)
		{
			if(c > b)
			{
				if(c * c == a * a + b * b)
				{
					ans[count] = 1;
					count++;
				}
				else
				{
					ans[count] = 0;
					count++;
				}
			}
		}
	}
	for(int i = 0 ; i < count ; i++)
	{
		if(ans[i] == 0)
			printf("wrong\n");
		else
			printf("right\n");
	}
	free(ans);
	return (0);
}
