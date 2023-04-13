#include <stdio.h>

void ft_print_combn(int n,int i)
{
	if(n == 1)
		for(int j = 1; j <= 9; j++)
		{
			printf("%d",i);
			printf("%d, ",j);
		}
	else
	{
		for(int j = 0; j <= 9; j++)
			ft_print_combn(n-1,j);
	}
}

int main(void)
{
	for(int i = 0; i <= 4; i++)
		ft_print_combn(4,i);
	return (0);
}
