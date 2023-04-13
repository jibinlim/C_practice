#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int l,c;
int a_c = 0;
int j_c = 0;

int cmp(const void *a, const void *b)
{
	char* x = (char *)a;
	char* y = (char *)b;

	return(strcmp(x,y));
}

void dfs(char *s, int visit[15],int a,int n, char *stack)
{
	visit[a] = 1;
	stack[n] = s[a];
	if(n == l - 1)
	{
		for(int i = 0; i <= n; i++)
		{
			if(stack[i] == 'a'|| stack[i] == 'e' || stack[i] == 'o' || stack[i] == 'i' || stack[i] == 'u')
				a_c++;
			else
				j_c++;
		}
		if(a_c >= 1 && j_c >= 2)
		{
			printf("%s\n",stack);
			a_c = 0;
			j_c = 0;
		}
		else
		{
			a_c = 0;
			j_c = 0;
		}
	}
	else
		for(int i = a + 1; i < c; i++)
			if(visit[i] == 0)
				dfs(s,visit,i,n+1,stack);
	visit[a] = 0;
}


int main(void)
{
	scanf("%d %d",&l,&c);
	char *s;
	char *stack;
	int visit[15] = {0,};


	s = (char *) malloc (sizeof(char) * (c + 1));
	stack = (char *) malloc (sizeof(char) * (l + 1));

	for(int i = 0; i < c; i++)
	{
		scanf("%*c%c",s + i);
	}

	qsort(s,c,sizeof(char),cmp);

	for(int i = 0; i <= c - l; i++)
		dfs(s,visit,i,0,stack);

	free(s);
	free(stack);
	return (0);
}
