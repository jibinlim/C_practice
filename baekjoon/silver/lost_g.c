#include<stdio.h>
#include <string.h>

int main(void)
{
	char x[51];
	scanf("%s",x);

	int len = strlen(x);
	int i = 0;
	int f = 0;
	int sum = 0;
	int result = 0;
	while(i <= len)
	{
		if(x[i] == '+' || x[i] == '-'|| x[i] == '\0')
		{
			if(f == 0)
			{
				sum += result;
				result = 0;
			}
			else
			{
				sum -= result;
				result = 0;
			}
			if(x[i] == '-')
				f = 1;
		}
		else
		{
			result *= 10;
			result += x[i] - '0';
		}
		i++;
	}
	printf("%d",sum);
	return (0);
}
			
