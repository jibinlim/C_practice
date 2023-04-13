#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int t;
	scanf("%d",&t);
	int *ans;
	char v[51];
	int count;
	int j;

	ans = (int *) malloc (sizeof(int) * t);

	for(int i = 0; i < t; i++)
	{
		scanf("%s",v);
		count = 0;
		j = 0;
		while(v[j])
		{
			if(v[j] == ')')
				count += -1;
			else if(v[j] == '(')
				count += 1;
			j++;
			if(count < 0)
				break;
		}
		if(count == 0)
			ans[i] = 1;
		else
			ans[i] = -1;
	}

	for(int i = 0; i < t; i++)
	{
		if(ans[i] == 1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	free(ans);
	return (0);
}
