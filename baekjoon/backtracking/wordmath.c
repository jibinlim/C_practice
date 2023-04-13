#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
char **word;
int max = 0;
int a;
char l[11];
int x = 0;
int num[11];


void dfs(int c, int count)
{
	num[count] = c;
	int f = 0;
	if(count == x - 1)
	{
		int i = 0;
		int sum = 0;
		while(i < n)
		{
			int result = 0;
			int j = 0;
			int len = strlen(word[i]);
			for(int j = 0; j < len; j++)
			{
				for(int a = 0; a < x; a++)
				{
					if(word[i][j] == l[a])
					{
						result = (result * 10) + num[a];
						break;
					}
				}
			}
			sum += result;
			i++;
		}
		if(sum > max)
			max = sum;
		return;
	}
	for(int i = 0; i <= 9; i++)
	{
		f = 0;
		for(int j = 0; j <= count; j++)
			if(num[j] == i)
			{
				f = 1;
				break;
			}
		if(f == 0)
			dfs(i,count + 1);
	}
}



int main(void)
{
	scanf("%d",&n);
	int j = 0;
	int f = 0;
	word = (char **) malloc (sizeof(char *) * (n + 1));
	for(int i = 0; i < n; i++)
	{
		j = 0;
		word[i] = (char *) malloc (sizeof(char) * 9);
		scanf("%s",word[i]);
		while(word[i][j])
		{
			f = 0;
			for(int a = 0; a < x; a++)
			{
				if(l[a] == word[i][j]) 
				{
					f = 1;
					break;
				}
			}
			if(f == 0)
			{
				l[x] = word[i][j];
				x++;
			}
			j++;
		}
	}
	for(int i = 0; i <= 9; i++)
		dfs(i,0);
	printf("%d",max);
	for(int i = 0; i < n; i++)
		free(word[i]);
	free(word);
	return (0);
}
