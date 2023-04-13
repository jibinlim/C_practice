#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d",&n);

	int a;
	int b[100000];
	for(int i = 0; i < 10000; i++)
		b[i] = 0;
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&a);
		b[a - 1]++;
	}
	for(int i = 0; i < 10000; i++)
		if(b[i] >= 1)
		{
			for(int j = 0; j < b[i] ; j++)
				printf("%d\n",i + 1);
		}
	return (0);
}
