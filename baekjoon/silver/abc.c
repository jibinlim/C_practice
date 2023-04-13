#include <stdio.h>

int main(void)
{
	int a[3];
	int max = -1;
	int min = 101;
	int mid;
	for(int i = 0; i < 3; i++)
	{
		scanf("%d",a + i);
		if(max < a[i])
			max = a[i];
		if(min > a[i])
			min = a[i];
	}
	for(int i = 0; i < 3; i++)
		if(max != a[i] && min != a[i])
			mid = a[i];
	char x[4];
	scanf("%s",x);

	for(int i = 0; i < 3; i++)
	{
		if(x[i] == 'A')
			printf("%d ",min);
		else if(x[i] == 'B')
			printf("%d ",mid);
		else if(x[i] == 'C')
			printf("%d ",max);
	}
	return (0);
}
