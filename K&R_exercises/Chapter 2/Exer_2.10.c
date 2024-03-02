#include<stdio.h>

int my_lower(int c)
{
	return (c>='A' && c<='Z') ? c +'a' -'A' :c;
}

int main(void)
{
	int c = 'E';
	printf("%c\n", my_lower(c));
}
