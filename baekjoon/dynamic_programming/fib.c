#include <stdio.h>
int count_1 = 1;
int count_2 = 1;
int f[100];

int fib(int n) {
    if (n == 1 || n == 2)
		return 1;
    else 
	{
		count_1++;
		return (fib(n - 1) + fib(n - 2));
	}
}

int fibonacci(int n) 
{
    f[1] = 1;
	f[2] = 1;
    for(int i = 3; i < n; i++)
	{
		f[i] = f[i - 1] + f[i - 2];
		count_2++;
	}
    return f[n];
}

int main(void)
{
	int n;
	scanf("%d",&n);
	int a = fib(n);
	int b = fibonacci(n);

	printf("%d %d",count_1,count_2);
	return (0);
}
