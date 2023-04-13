#include <stdio.h>

int main(void)
{
	int n;
	int n_temp;
	int ans = 0;
	int sum = 0;
	int y;

	scanf("%d",&n);

	y = 1;
	while(y < n)
	{
		n_temp = y;
		sum += y;
		while(n_temp > 0)
		{
			sum += n_temp % 10;
			n_temp /= 10;
		}
		if(sum == n)
		{
			ans = y;
			break;
		}
		sum = 0;
		y++;
	}
	printf("%d\n",ans);
	return (0);
}
