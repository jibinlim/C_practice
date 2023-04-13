#include <stdio.h>

int sum(int x,int y)
{
	return (x + y);
}

int mul(int x,int y)
{
	return (x * y);
}

void kuku(int(*calc)(int,int))
{
	int i,j;
	for(i = 1; i <= 9; i++)
	{
		for(j = 1; j <= 9; j++)
			printf("%3d",(*calc)(i,j));
		printf("\n");
	}
}

int main(void)
{
	printf("덧셈표\n");
	kuku(sum);
	printf("곱셈표\n");
	kuku(mul);
	return (0);
}
