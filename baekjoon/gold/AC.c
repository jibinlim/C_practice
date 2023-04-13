#include <stdio.h>

int main(void)
{
	int t;
	scanf("%d",&t);

	for(int i = 0; i < t; i++)
	{
		char p[100001];
		scanf("%s",p);

		int n;
		scanf("%d",&n);
		
		char x[400001];
		scanf("%s",x);

		int a[100001];
		int j = 0;
		int k = 0;
		while(x[j])
		{
			if(x[j] >= '0' && x[j] <= '9')
			{
				if(x[j + 1] >= '0' && x[j + 1] <= '9')
				{
					if(x[j + 2] >= '0' && x[j + 2] <= '9')
					{
						a[k] = 100;
						k++;
						j+=2;
					}
					else
					{
						a[k] = (x[j] - '0') * 10 + x[j + 1] - '0';
						k++;
						j++;
					}
				}
				else
				{
					a[k] = x[j] - '0';
					k++;
				}
			}
			j++;
		}
		int front = 0, rear = k - 1;
		int f = 0;
		j = 0;
		while(p[j])
		{
			if(p[j] == 'R')
			{
				if(f == 0)
					f = 1;
				else
					f = 0;
			}
			if(p[j] == 'D')
			{
				if(f == 0)
					front++;
				else
					rear--;
			}
			j++;
		}
		if(front > rear)
		{
			if(front - rear >= 2)
				printf("error\n");
			else if(front - rear == 1)
				printf("[]\n");
		}
		else
		{
			printf("[");
			if(f == 1)
			{
				for(int z = rear ; z >= front; z--)
				{
					if(z != front)
						printf("%d,",a[z]);
					else
						printf("%d",a[z]);
				}
			}
			else
			{
				for(int z = front; z <= rear; z++)
				{
					if(z != rear)
						printf("%d,",a[z]);
					else
						printf("%d",a[z]);
				}
			}
			printf("]\n");
		}
	}
	return (0);
}
