#include <stdio.h>

int main(void)
{
	int a,b;
	scanf("%d %d",&a,&b);
	int sum = 0;

	int count = 0;
	int num = 1;
	for(int i = 1; i <= b; i++)
	{
		if(i >= a)
			sum += num;
		count++;
		if(count == num)
		{
			count = 0;
			num++;
		}
	}
	printf("%d\n",sum);
	return (0);
}
