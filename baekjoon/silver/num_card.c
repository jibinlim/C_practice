#include <stdio.h>
#include <stdlib.h>


int cmp(const void *a, const void *b)
{
	if(*(int *)a > *(int *)b)
		return 1;
	else if(*(int *)a < *(int *)b)
		return -1;
	else
		return 0;
}

int lower_bound(int *card, int key, int size)
{
	int start = 0;
	int end = size - 1;

	while(start < end)
	{
		int mid = (start + end) / 2;
		if(key <= card[mid])
			end = mid;
		else
			start = mid + 1;
	}
	return end;
}

int upper_bound(int *card, int key, int size)
{
	int start = 0;
	int end = size - 1;
	int mid;
	while(start < end)
	{
		mid = (start + end) / 2;
		if(key < card[mid])
			end = mid;
		else
			start = mid + 1;
	}
	if(card[end] == key)
		return end + 1;
	else
		return end;
}

int main(void)
{
	int n;
	scanf("%d",&n);
	int *card;
	card = (int *) malloc (sizeof(int) * n);
	for(int i = 0; i < n; i++)
		scanf("%d",&card[i]);
	int m;
	scanf("%d",&m);
	int *deck;
	deck = (int *) malloc (sizeof(int) * m);
	for(int i = 0; i < m; i++)
		scanf("%d",&deck[i]);
	qsort(card,n,sizeof(int),cmp);
	int x = 0;
	for(int i = 0; i < m; i++)
	{
		int lower = lower_bound(card,deck[i],n);
		int upper = upper_bound(card,deck[i],n);
		printf("%d ",upper - lower);
	}
	free(deck);
	free(card);
	return (0);
}
