#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char *s;
	int n;
	char c;
	int p,q;
	int *ans;

	s = (char *) malloc (sizeof(char) * 2001);

	scnaf("%s %d",s,&n);

	ans = (int *) malloc (sizeof(int) * n);

