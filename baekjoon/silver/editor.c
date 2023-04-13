#include <stdio.h>
#include <string.h>

int main(void)
{
	char l_s[1000001];
	char r_s[1000001];
	int l_t = 0,r_t = 0;
	char op;
	char c;
	int p;

	scanf("%s",l_s);
	l_t = strlen(l_s);
	scanf("%d", &p);
	while(p > 0)
	{
		scanf(" %c",&op);
		if(op == 'P')
		{
			scanf(" %c", &c);
			l_s[l_t] = c;
			l_t++;
		}
		else if(op == 'L')
		{
			if(l_t > 0)
			{
				r_s[r_t] = l_s[l_t - 1];
				r_t++;
				l_s[l_t - 1] = 0;
				l_t--;
			}
		}
		else if(op == 'D')
		{
			if(r_t > 0)
			{
				l_s[l_t] = r_s[r_t - 1];
				l_t++;
				r_s[r_t - 1] = 0;
				r_t--;
			}
		}
		else if(op == 'B')
		{
			if(l_t > 0)
			{
				l_s[l_t - 1] = 0;
				l_t--;
			}
		}
		p--;
	}
	for(int i = r_t - 1; i >= 0; i--)
	{
		l_s[l_t] = r_s[i];
		l_t++;
	}
	printf("%s",l_s);
	return (0);
}
