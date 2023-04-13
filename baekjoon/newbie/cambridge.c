#include <stdio.h>

int main(void)
{
	char cam[10] = "CAMBRIDGE";
	int i = 0;
	char x[101];

	scanf("%s",x);

	int f = 0;
	while(x[i])
	{
		f = 0;
		for(int j = 0; j < 9; j++)
			if(x[i] == cam[j])
			{
				f = 1;
				break;
			}
		if(f == 0)
			printf("%c",x[i]);
		i++;
	}
	printf("\n");
	return (0);
}
