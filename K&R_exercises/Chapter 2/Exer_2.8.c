#include<stdio.h>

#include BYTELEN   8
 int rightrot(int x, int n)
 {
 	int rightmask;
	rightmask  = (x << (BYTELEN-n));
	
	x = (x >> n);
	x = (x | rightmask);
 	return x;
 }
 
 int main(void)
 {
 	int x, n;
 	x = 0xAF;
 	printf("%d\n", rightrot(x,n));
 	
 }
