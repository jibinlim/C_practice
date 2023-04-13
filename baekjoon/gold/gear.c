#include <stdio.h>

void right(int gear[8])
{
	int temp;
	temp = gear[7];
	for(int i = 6; i >= 0; i--)
		gear[i + 1] = gear[i];
	gear[0] = temp;
}

void left(int gear[8])
{
	int temp;
	temp = gear[0];
	for(int i = 0; i < 7; i++)
		gear[i] = gear[i + 1];
	gear[7] = temp;
}


int main(void)
{
	int gear[4][8];
	int k;
	int g,d;
	int check[4] = {0,};

	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 8; j++)
			scanf("%1d",&gear[i][j]);

	scanf("%d",&k);

	for(int i = 0; i < k;i++)
	{
		scanf("%d %d",&g,&d);
		g--;
		check[g] = d;
			for(int i = g; i < 3; i++)
			{
				if(gear[i][2] == gear[i + 1][6])
					check[i + 1] = 0;
				else
				{
					if(check[i] == 1)
						check[i + 1] = -1;
					else if(check[i] == -1)
						check[i + 1] = 1;
				}
			}
			for(int i = g; i > 0; i--)
			{
				if(gear[i][6] == gear[i - 1][2])
					check[i - 1] = 0;
				else
				{
					if(check[i] == 1)
						check[i - 1] = -1;
					else if(check[i] == -1)
						check[i - 1] = 1;
				}
			}
		for(int i = 0; i < 4; i++)
		{
			if(check[i] == 1)
				right(gear[i]);
			else if(check[i] == -1)
				left(gear[i]);
			check[i] = 0;
		}
	}
	int b = 1;
	int score = 0;
	for(int i = 0; i < 4; i++)
	{
		if(gear[i][0] == 1)
			score += b;
		b *= 2;
	}
	printf("%d\n",score);
	return (0);
}
