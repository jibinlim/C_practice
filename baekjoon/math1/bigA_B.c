#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char *a;
	char *b;
	char *c;
	int d;
	int a_len;
	int b_len;

	a = (char *) malloc (sizeof(char) * 10001);
	b = (char *) malloc (sizeof(char) * 10001);
	c = (char *) malloc (sizeof(char) * 10002);

	scanf("%s %s",a,b);
	a_len = strlen(a);
	b_len = strlen(b);
	if(a_len > b_len)
	{
		for(int i = a_len - 1; i >= a_len - b_len ; i--)
			b[i] = b[i - a_len + b_len];
		for(int i = 0; i < a_len - b_len ; i++)
			b[i] = '0';
	}
	else if(a_len < b_len)
	{
		for(int i = b_len - 1; i >= b_len - a_len ; i--)
			a[i] = a[i - b_len + a_len];
		for(int i = 0; i < b_len - a_len ; i++)
			a[i] = '0';
	}
	d = 0;
	if(a[0] - '0' + b[0] > '9')
	{
		for(int i = strlen(a) - 1 ; i >= 0; i--)
		{
			if(a[i] -'0' + b[i] + d > '9')
			{
				c[i + 1] = a[i] + b[i] + d - '9' - 1;
				d = 1;
			}
			else
			{
				c[i+1] = a[i] - '0'  + b[i] + d;
				d = 0;
			}
		}
		c[0] = '1';
	}
	else if(a[0] - '0' + b[0] < '9')
	{
		for(int i = strlen(a) - 1 ; i >= 0; i--)
		{
			if(a[i] - '0'+ b[i] + d > '9')
			{
				c[i] = a[i] + b[i] - '9' -1 + d;
				d = 1;
			}
			else
			{
				c[i] = a[i] - '0' + b[i] + d;
				d = 0;
			}
		}
	}
	else if(a[0] - '0' + b[0] == '9')
	{
		for(int i = strlen(a) - 1 ; i >= 0 ; i--)
		{
			if(a[i] + b[i] - '0' + d > '9')
				d = 1;
			else
				d = 0;
		}
		if(d == 1)
		{
			d = 0;
			for(int i = strlen(a) - 1; i >= 0; i--)
			{
				if(a[i] - '0' + b[i] + d > '9')
				{
					c[i + 1] = a[i] + b[i] - '9' - 1 + d;
					d = 1;
				}
				else
				{
					c[i+1] = a[i] - '0' + b[i] + d ;
					d = 0;
				}
			}
			c[0] = '1';
		}
		else
		{
			for(int i = strlen(a) - 1; i >= 0; i--)
			{
				if(a[i] - '0'+ b[i] + d > '9')
				{
					c[i] = a[i] + b[i] + d - '9' - 1;
					d = 1;
				}
				else
				{
					c[i] = a[i] - '0' + b[i] + d;
					d = 0;
				}
			}
		}
	}
	printf("%s",c);
	free(a);
	free(b);
	free(c);
	return (0);
}
