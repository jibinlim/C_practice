#include <stdio.h>

struct p{
	int x;
	int y;
};

int main(void)
{
	char map[11][21];
	struct p me;
	struct p fin;
	int count = 0;
	me.x = 9;
	me.y = 2;
	fin.x = 0;
	fin.y = 16;
	for(int i = 0; i < 10; i++)
		for(int j = 0; j < 20; j++)
		{
			if(i == 0)
				map[i][j] = '_';
			else if(i == 9)
				map[i][j] = '-';
			else if(j == 0 || j == 19)
				map[i][j] = '|';
			else
				map[i][j] = ' ';
		}
	
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 20; j++)
		{
			if(me.x == i && me.y == j)
				printf("o");
			else if(fin.x == i && fin.y == j)
				printf("F");
			else
				printf("%c",map[i][j]);
		}
		printf("\n");
	}

	char key;
	while(1)
	{
		printf("앞으로(w) 뒤로(s) 오른쪽(d) 왼쪽(a):");
		scanf("%c%*c",&key);
		if(key == 'w')
		{
			me.x--;
			if(!(me.x == fin.x && me.y == fin.y))
				if(me.x <= 0)
					me.x++;
		}
		if(key == 's')
		{
			me.x++;
			if(me.x >= 9)
				me.x--;
		}
		if(key == 'd')
		{
			me.y++;
			if(me.y >= 19)
				me.y--;
		}
		if(key == 'a')
		{
			me.y--;
			if(me.y <= 0)
				me.y++;
		}
		for(int i = 0; i < 10; i++)
		{
			for(int j = 0; j < 20; j++)
			{
				if(me.x == i && me.y == j)
					printf("o");
				else if(fin.x == i && fin.y == j)
					printf("F");
				else
					printf("%c",map[i][j]);
			}
			printf("\n");
		}
		count++;
		printf("현재 좌표:(%d,%d)",me.x,me.y);
		if(me.x == fin.x && me.y == fin.y)
			break;
	}
	printf("\n%d번 이동했습니다!",count);
	return (0);
}
