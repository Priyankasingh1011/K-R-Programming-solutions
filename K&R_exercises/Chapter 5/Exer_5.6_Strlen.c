#include<stdio.h>
#define MAXINPUT       100

int my_strlen(char *c)
{
	char *p = c;
	while(*p != '\0')
	{
		p++;
	}
	
	return p - c;	
}

int my_getline(char input[], int lim)
{
	int c, i;
	for(i=0; i<lim-1 && (c=getchar()) != EOF && c != '\n'; i++)
	{
		input[i] = c;
	}
	
	if(c== '\n')
	{
		input[i] = c;
		++i;
	}
	
	input[i] = '\0';
	
	return i;
	
}

int main()
{
	char cinput[MAXINPUT];
	putchar('s');
	putchar(':');
	
	my_getline(cinput, MAXINPUT);
	
	printf("%d\n", my_strlen(cinput));
	
}
