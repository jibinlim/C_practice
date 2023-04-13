#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d",&n);
	int card[100001] = {0,};
	int f = 0, r = 0;

	for(int i = 0; i < n; i++)
	{
		card[i] = i + 1;
		r++;
	}
	while(n > 0)
	{
		printf("%d ",card[f]);
		f++;
		card[r] = card[f];
		r++;
		f++;
		n--;
	}
	return (0);
}
