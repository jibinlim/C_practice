#include <stdio.h>

int no_number(int *t, int num)
{
	while(*t != 43)
	{
		if(*t == num)
			return (0);
		t++;
	}
	return (1);
}

int main()
{
	int	arr[10];
	int	x[10];
	int	t[10];
	int	i;
	int	j;
	int count;

	j = 1;
	count = 1;
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
		x[i] = arr[i] % 42;
		t[i] = 43;
	}
	t[0] = x[0];
	for ( i = 0; i < 10; i++)
	{
		if(no_number(t, x[i]))
		{
			t[j] = x[i];
			j++;
			count++;
		}
	}
	printf("%d", count);
	return (0);
}
