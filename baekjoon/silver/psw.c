#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int l,c;
int al[27] = {0,};
char *x;

void dfs(int count,char *x)
{
	if(count < l)
	{
		for(int i = 0; i < 27; i++)
			if(al[i] == 1)
			{
				x[count] = i + 'a';
				al[i] = 2;
				dfs(count + 1, x);
				al[i] = 1;
			}
	}
	else
		printf("%s\n",x);
}

int main(void)
{
	scanf("%d %d",&l,&c);
	char *a;
	a = (char *) malloc (sizeof(char) * (c + 1));
	for(int i = 0; i < c; i++)
	{
		scanf(" %c",a + i);
		al[a[i] - 'a'] = 1;
	}
	x = (char *) malloc (sizeof(char) * (l + 1));
	dfs(0,x);
	
	
	free(a);
	return (0);
}
