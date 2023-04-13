#include <stdio.h>

int max(int a,int b)
{
	if(a > b)
		return a;
	else 
		return b;
}

int min(int a,int b)
{
	if(a < b)
		return a;
	else
		return b;
}

int main(void)
{
	int space[500];

	int h,w;
	scanf("%d %d",&h,&w);

	int answer = 0;
	for(int i = 0; i < w; i++)
		scanf("%d",&space[i]);

	for(int i = 1; i < w - 1; i++)
	{
		int left = 0, right = 0;
		for(int j = 0; j < i; j++)
			left = max(left,space[j]);
		for(int j = w - 1; j > i; j--)
			right = max(right,space[j]);
		answer += max(0,min(left,right) - space[i]);
	}
	printf("%d",answer);
	return (0);
}
