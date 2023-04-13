#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	scanf("%d",&n);
	int *s;
	int count = 1;
	int max;
	s = (int *) malloc (sizeof(int) * n);

	for(int i = 0; i < n; i++)
		scanf("%d",s+i);
	max = s[n - 1];
	for(int i = n - 2; i >= 0; i--)
		if(s[i] > max)
		{
			count++;
			max = s[i];
		}
	printf("%d",count);
	free(s);
	return (0);
}
