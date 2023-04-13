#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n,k;
	scanf("%d %d", &n, &k);
	int k_t = k;
	char *num;
	num = (char *) malloc (sizeof(char) * (n + 1));
	int *st;
	st = (int *) malloc (sizeof(int) * n);
	int top = 0;

	scanf("%s",num);
	st[top] = num[0] - '0';
	top++;
	for(int i = 1; i < n; i++)
	{
		while(k > 0 && st[top - 1] < num[i] - '0' && top > 0)
		{
			st[top - 1] = num[i] - '0';
			top--;
			k--;
		}
		st[top] = num[i] - '0';
		top++;
	}
	for(int i = 0; i < n - k_t; i++)
		printf("%d",st[i]);

	free(st);
	free(num);
	return (0);
}
