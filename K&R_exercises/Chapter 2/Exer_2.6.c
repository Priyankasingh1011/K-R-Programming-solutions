#include<stdio.h>

int setbits(int x, int p, int n, int y)
{
	return (x >> (p+1-n)) & ~(1 << n) | (y >> (p+1-n)) & ~(1 << n);
}


int main(void)
{
	int x, p, n;
	p=4, n=3;
    x = 6, y=8;
	printf("%d\n", getbits(x,p,n,y));
}
