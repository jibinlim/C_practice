#include <stdio.h>
#include <string.h>

int main(void)
{
	char x[6][16];
	int m_len = 0;
	int len;
	for(int i = 0; i < 5; i++)
	{
		scanf("%s",x[i]);
		len = strlen(x[i]);
		if(m_len < len)
			m_len = len;
	}

	for(int i = 0; i < m_len; i++)
		for(int j = 0; j < 5; j++)
		{
			if(x[j][i] == 0)
				continue;
			printf("%c",x[j][i]);
		}
	return (0);
}
