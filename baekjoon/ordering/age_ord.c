#include <stdio.h>
#include <stdlib.h>

typedef struct online
{
	char name[101];
	int age;
} online;

int compare(const void *a, const void *b)
{
	online *x = (online *) a;
	online *y = (online *) b;
	if(x -> age > y -> age)
		return (1);
	else if (x -> age < y -> age)
		return (-1);
	else
		return (0);
}

int main(void)
{
	int n;
	scanf("%d",&n);
	online *on;
	on = (online *) malloc (sizeof(online) * n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d %s",&on[i].age,on[i].name);
	}
	qsort(on,n,sizeof(online),compare);
	for(int i = 0; i < n ; i++)
	{
		printf("%d %s\n",on[i].age,on[i].name);
	}
	free(on);
	return (0);
}
