#include <stdio.h>

int main(void)
{
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	int t = 0;
	int count = 0;

	if(n + m <= k)
		t = 0;
	else
	{
		if(n % 2 == 1)
		{
			n--;
			k--;
		}

	if(n >= m * 2)
	{
		while(n > m * 2)
		{
			n--;
			k--;
		}
		while(k > 0)
		{
			n--;
			k--;
			count++;
			if(count == 2 && k > 0)
			{
				count = 0;
				m--;
				k--;
			}
		}
	}
	else
	{
		while(n < m * 2)
		{
			m--;
			k--;
		}
		while(k > 0)
		{
			n--;
			k--;
			count++;
			if(count == 2 && k > 0)
			{
				count = 0;
				m--;
				k--;
			}
		}
	}
	while(m >= 1 && n >= 2)
	{
		m--;
		n -= 2;
		t++;
	}
	}
	printf("%d",t);
	return (0);
}
