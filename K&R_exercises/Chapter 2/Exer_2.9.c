#include<stdio.h>

int bitcount(int x)
{
	int count = 0;
	while(x)
	{
		x = x&(x-1);
		count++;
	}
	return count;
}

int main(void)
{
	int x = 4;
	printf("%d\n", bitcount(x));
}
