#include <stdio.h>

int min(int a,int b)
{
	if(a > b)
		return b;
	else
		return a;
}

int check(int button[10],int goal)
{
	int x = 0;
	if(goal == 0)
	{
		if(button[0] == 0)
			return 0;
		else
			return 1;
	}
	while(goal > 0)
	{
		if(button[goal % 10] == 0)
			return 0;
		goal /= 10;
		x++;
	}
	return (x);
}

int main(void)
{
	int goal;
	scanf("%d",&goal);
	int m;
	scanf("%d",&m);
	int x;
	int button[10] = {1,1,1,1,1,1,1,1,1,1};
	for(int i = 0; i < m; i++)
	{
		scanf("%d",&x);
		button[x] = 0;
	}
	int now = 100;
	int count = 0;
	int c;
	int l;
	c = check(button,goal);
	if(check(button,goal) != 0)
	{
		if(now > goal)
			c = min(c, now - goal);
		else
			c = min(c, goal - now);
	}
	else
	{
		if(now > goal)
			c = now - goal;
		else
			c = goal - now;
		for(int i = 0; i < 1000001; i++)
		{
			l = check(button,i);
			if(l != 0)
			{
				if(i > goal)
					l += i - goal;
				else
					l += goal - i;
				c = min(l,c);
			}
		}
	}
	printf("%d\n",c);
	return (0);
}
