#include <stdio.h>

int main()
{
	int k;
	int q;
	int	r;
	int b;
	int kn;
	int p;

	scanf ("%d %d %d %d %d %d", &k, &q, &r, &b, &kn, &p);
	k = 1 - k;
	q = 1 - q;
	r = 2 - r;
	b = 2 - b;
	kn = 2 - kn;
	p = 8 - p;

	printf ("%d %d %d %d %d %d", k, q, r, b, kn, p);
	return (0);
}
