#include <stdio.h>
#include <string.h>


int main(void)
{
	char bi[1000001];
	scanf("%s",bi);
	char oc[1000001];

	int len = strlen(bi);
	int i = 0;
	int j = 0;
	int x = 0;

	if(len % 3 == 1)
	{
		if(bi[j] == '1')
		{
			oc[i] = '1';
			i++;
			j++;
			x = 1;
		}
		if(len == 1 && bi[j] == '0')
			oc[i] = '0';
	}
	else if(len % 3 == 2)
	{
		oc[i] = (bi[j] - '0') * 2 + (bi[j + 1] - '0') + '0';
		i++;
		j+=2;
		x = 1;
	}
	while((len / 3) + x > i)
	{
		oc[i] = (bi[j] - '0') * 4 + (bi[j + 1] - '0') * 2 + (bi[j + 2] -'0' ) + '0';
		i++;
		j+=3;
	}
	len = strlen(oc);
	i = 0;
	if(len != 1 && oc[0] == '0')
		i++;
	for(; i < len; i++)
		printf("%c",oc[i]);

	return (0);
}
