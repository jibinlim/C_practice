#include <stdio.h>

int self_number(int nb)
{
	int result;
	int x;
	int y;
	
	result = 0;
	while(result <= 10000)
	{
		if (nb < 10)
		{
			result = nb + (nb % 10);
			nb++;
		}
		else if (nb < 100)
		{
			result = nb + (nb / 10) + (nb % 10);
			nb++;
		}
		else if (nb < 1000)
		{
			y = nb % 100;
			result = nb + (nb / 100) + (y / 10) + (y % 10);
			nb++;
		}
		else if(nb < 10000)
		{
			x = nb % 1000;
			y = x % 100;
			result= nb + (nb / 1000) + (x / 100) + (y / 10) + (y % 10);
			nb++;
		}
		return(result);
	}
	return (0);
}

int in_result(int result)
{
	int nb;

	nb = 0;
	while (self_number(nb) <= 9993)
	{
		if (result == self_number(nb))
				return (1);
		nb++;
	}
	return (0);
}

int main()
{
	int result;
	result = 0;
	while (result <= 9993)
	{
		if (!in_result(result))
		{
			printf("%d\n", result);
		}
		result++;
	}
	return (0);
}
