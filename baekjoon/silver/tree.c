#include <stdio.h>

int x[26][2];

void pre(int i)
{
	if(i < 0) return;

	printf("%c", i + 'A');
	pre(x[i][0]);
	pre(x[i][1]);

	return ;
}

void in(int i)
{
	if(i < 0) return;

	in(x[i][0]);
	printf("%c", i + 'A');
	in(x[i][1]);

	return ;
}

void post(int i)
{
	if(i < 0) return;

	post(x[i][0]);
	post(x[i][1]);
	printf("%c", i + 'A');

	return ;
}

int main(void)
{
	int n;
	scanf("%d", &n);
	char a,b,c;


	for(int i = 0; i < n; i++)
	{
		scanf("\n%c \n%c \n%c",&a,&b,&c);

		x[a - 'A'][0] = b - 'A';
		x[a - 'A'][1] = c - 'A';
	}

	pre(0);
	printf("\n");
	in(0);
	printf("\n");
	post(0);
	printf("\n");
	return (0);
}
