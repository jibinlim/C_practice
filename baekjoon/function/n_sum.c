long long sum(int *a, int n)
{
	int	i;
	long long	sum;

	i = 0;
	sum = 0;
	while(i < n)
	{
		sum += *a;
		a++;
		i++;
	}
	return (sum);
}
