#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d",&n);
	int six = 0;

	int x[10] = {0, };

	while(n > 0)
	{
		x[n % 10]++;
		n /= 10;
	}
	if((x[6] + x[9]) % 2 == 1)
		six = 1;
	x[6] = (x[9] + x[6]) / 2 + six;
	x[9] = 0;
	int max = 0;
	for(int i = 0; i < 9; i++)
		if(x[i] > max)
			max = x[i];
	printf("%d\n",max);
	return (0);
}
