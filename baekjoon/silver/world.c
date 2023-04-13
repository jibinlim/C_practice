#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *s;
	int *x;

	s = (char *) malloc (sizeof(char ) * 101);
	x = (int *) malloc (sizeof(int) * 100);
	int i = 0;
	int count = 0;
	int t = 0;

	while(1)
	{
		gets(s);
		if(s[0] == '.')
			break;
		while(s[i] != '.')
		{
			if(s[i] == '(')
			{
				x[count] = 0;
				count ++;
			}
			if(s[i] == '[')
			{
				x[count] = 1;
				count++;
			}
			if(s[i] == ')')
			{
				if(count == 0)
				{
					count = -1;
					break;
				}
				if(x[count - 1] == 1)
					break;
				else
					count --;
			}
			if(s[i] == ']')
			{
				if(count == 0)
				{
					count = -1;
					break;
				}
				if(x[count - 1] == 0)
					break;
				else
					count --;
			}
			i++;
			if(count < 0)
				break;
		}
		if(count == 0)
			printf("yes\n");
		else
			printf("no\n");
		count = 0;
		i = 0;
	}
	free(s);
	free(x);
	return (0);
}
