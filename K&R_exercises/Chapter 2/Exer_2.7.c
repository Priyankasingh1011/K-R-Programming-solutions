#include<stdio.h>

int invert(int x, int p, int n)
{
	return x ^ (~(1<<n) << (p+1-n));
}

int main()
{
	int x, p, n;
	p=4, n=3;
    x = 6;
	printf("%d\n", getbits(x,p,n));
}
