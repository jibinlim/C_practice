#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d",&n);
    int x = 1;
    while(n > 0)
    {
        x *= 2;
        n--;
    }
    printf("%d",x);
    return (0);
}
