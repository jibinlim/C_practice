#include <stdio.h>
#include <stdlib.h>

int w(int a, int b ,int c)
{
	if(a <= 0 || b <= 0 || c <= 0)
		return (1);
	if(a > 20 || b > 20 || c > 20)
		return (w(20,20,20));
	if(a < b || b < c)
		return (w(a,b,c-1) + w(a,b-1,c-1) - w(a, b-1,c));
	return (w(a-1,b,c)+w(a-1,b-1,c)+w(a-1, b, c-1)-w(a-1,b-1,c-1));
}

int main(void)
{
	int *a,*b,*c;
	int count = 0;
	int *ans;
	a = (int *) malloc (sizeof(int) * 500);
	b = (int *) malloc (sizeof(int) * 500);
	c = (int *) malloc (sizeof(int) * 500);
	ans = (int *) malloc (sizeof(int) * 500);
	while(1)
	{
		scanf("%d %d %d",&a[count],&b[count],&c[count]);
		if(a[count] == -1 && b[count] == -1 && c[count] == -1)
			break;
		ans[count] = w(a[count],b[count],c[count]);
		count++;
	}
	for(int i = 0; i < count ; i++)
		printf("w(%d, %d, %d) = %d\n",a[i],b[i],c[i],ans[i]);
	free(a);
	free(b);
	free(c);
	free(ans);
	return (0);
}
