#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n,k;
	scanf("%d %d",&n,&k);

	int *ans;
	ans = (int *) malloc (sizeof(int) * n); //출력용 ans
	int count = 0;  //k를 세기 위한 count
	int *x;
	int j = 0;
	int i = 0;
	if(n <= 0 || k <= 0)  //둘중 하나라도 0이면 프로그램을 끝내도록 했습니다.
		return(0);
	x = (int *) malloc (sizeof(int) * (n + 1)); //번호 넣는 x입니다
	for(i = 0; i <= n ; i++)
		x[i] = i;
	i = 0;
	while(j < n)
	{
		count++;
		i++;
		if(i > n)
			i = 0;
		while(x[i] == 0) //x[i] 가 빠지면 0으로 만들어서 0이면 넘어가도록 했습니다.
		{
			i++;
			if(i > n)  //n보다 커지면 다시 0부터 초기화 됩니다.
				i = 0;
		}
		if(count == k)
		{
			while(x[i] == 0)
			{
				i++;
				if(i > n)
					i = 0;
			}
			ans[j] = x[i];  //해당값 삽입
			count = 0;
			x[i] = 0;
			j++;
		}
	}
	printf("<");
	for(i = 0; i < n; i++)
	{
		if(i < n - 1)
		{
			printf("%d",ans[i]);
			printf(", ");
		}
		else
			printf("%d>",ans[i]);
	}
	free(ans);
	return (0);
}
