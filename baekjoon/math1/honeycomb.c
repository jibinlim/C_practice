#include <stdio.h>

int main()
{
	unsigned int n;
	scanf("%u",&n);
	if(n <= 0 || n > 1000000000)
		return (0);
	unsigned int r;
	unsigned int i;
	i = 1;
	r = 1;

	while (r < n)
	{
		r += i * 6;
		i++;
	}
	printf("%u",i);
	return (0);
}
