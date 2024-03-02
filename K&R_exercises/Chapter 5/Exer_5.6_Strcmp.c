#include<stdio.h>

#define MAXINPUT     100

int my_strcmp(char *s , char *t)
{
	for(; *s == *t; s++, t++)
	{
		if(*s == '\0')
		   return 0;
	}
	return *s - *t;	
}

int my_strncmp(char *s , char *t, int n)
{	
	for(; *s == *t; s++, t++)
	{
		if((*s == '\0') || --n <= 0)
		   return 0;
	}
	return *s - *t;	
}

int main()
{
	char cinput[MAXINPUT], dinput[MAXINPUT];
	putchar('s');
	putchar(':');
	
	my_getline(cinput, MAXINPUT);
	
	putchar('d');
	putchar(':');
	
	my_getline(dinput, MAXINPUT);
	printf("%d\n", my_strcmp(cinput, dinput));
	
	printf("%d\n", my_strncmp(cinput, dinput, 3));
	
}
