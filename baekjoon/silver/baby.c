#include <stdio.h>

int main(void)
{
	char baby[15][8] = {"baby","sukhwan","tururu","turu","very","cute","tururu","turu","in","bed","tururu","turu","baby","sukhwan"};

	int n;
	scanf("%d",&n);

	if(n <= 14)
		printf("%s",baby[n - 1]);
	else
	{

		if(n % 14 == 3 || n % 14 == 7|| n % 14 == 11)
		{
			if((n / 14) + 2 < 5)
			{
				printf("tu");
				for(int i = 0; i < (n / 14) + 2 ; i++)
					printf("ru");
			}
			else
				printf("tu+ru*%d",(n / 14) + 2);
		}
		else if (n % 14 == 4 || n % 14 == 8 || n % 14 == 12)
		{
			if((n / 14) + 1 < 5)
			{
				printf("tu");
				for(int i = 0; i < (n / 14) + 1; i++)
					printf("ru");
			
			}
			else
				printf("tu+ru*%d",(n / 14) + 1);
		}
		else if(n % 14 == 0)
			printf("%s",baby[13]);
		else
			printf("%s",baby[(n % 14)- 1]);
	}
	return (0);
}
