#include <stdio.h>

int main()
{
	char a[2][3];
	int A;
	int B;

	for (int i = 0; i < 2; i++)
		scanf("%s",a[i]);

	A = (a[0][2] - '0') * 100 + (a[0][1] - '0') * 10 + (a[0][0] - '0');
	B = (a[1][2] - '0') * 100 + (a[1][1] - '0') * 10 + (a[1][0] - '0');

	if(A > B)
	{
		printf("%d",A);
	}
	else
		printf("%d",B);

	return (0);
}
