#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n,k;
	scanf("%d %d", &n, &k);


	int x,y;
	int dx,dy;
	int h_x,h_y;
	int t_x,t_y;
	int l;
	int second = 0;
	int lon = 1;
	int **board;

	board = (int **) malloc (sizeof(int *) * n);
	for(int i = 0; i < n; i++)
	{
		board[i] = (int *) malloc (sizeof(int) * n);
		for(int j = 0; j < n; j++)
			board[i][j] = 0;
	}

	for(int i = 0; i < k; i++)
	{
		scanf("%d %d",&x, &y);
		board[x - 1][y - 1] = 2;
	}
	board[0][0] = 1;
	scanf("%d", &l);
	int *a;
	char *str;
	a = (int *) malloc (sizeof(int) * l);
	str = (char *) malloc (sizeof(char) * (l + 1));
	for(int i = 0; i < l; i++)
		scanf("%d %c%*c",&a[i],&str[i]);
	int f = 0;
	int t = 0;
	int pyo = -1;
	int mo[4] = {0,0,-1,1};
	int ve[4] = {-1,1,0,0};
	t_x = 0;
	t_y = 0;
	h_x = 0;
	h_y = 0;
	board[h_x][h_y] = pyo;
	pyo--;
	while(1)
	{
		if(f == 0)
			h_y++;
		else if(f == 1)
			h_x++;
		else if(f == 2)
			h_y--;
		else if(f == 3)
			h_x--;
		second++;
		if(h_x < 0 || h_y < 0 || h_x >= n || h_y == n)
			break;
		if(board[h_x][h_y] < 0)
			break;
		else if(board[h_x][h_y] == 0)
		{
			board[h_x][h_y] = pyo;
			pyo--;
			for(int i = 0; i < 4; i++)
			{
				dx = t_x + mo[i];
				dy = t_y + ve[i];
				if(dx < 0 || dy < 0 || dx >= n || dy >= n)
					continue;
				if(board[dx][dy] == board[t_x][t_y] - 1)
				{
					board[t_x][t_y] = 0;
					t_x = dx;
					t_y = dy;
					break;
				}
			}
		}
		else
		{
			board[h_x][h_y] = pyo;
			pyo--;
		}
		if(second == a[t])
		{
			if(str[t] == 'D')
				f++;
			else if(str[t] == 'L')
				f--;
			if(f > 3)
				f = 0;
			if(f < 0)
				f = 3;
			t++;
		}
	}

	printf("%d\n",second);
	free(a);
	free(str);
	for(int i = 0; i < n; i++)
		free(board[i]);
	free(board);
	return (0);
}
