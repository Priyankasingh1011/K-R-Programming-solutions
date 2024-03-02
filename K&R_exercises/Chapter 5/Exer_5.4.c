#include <stdio.h>
#include <string.h>

#define MAXINPUT     100

int my_strend(char *s, char *t)
{
	int len = strlen(t);
	while(*s != '\0')
	{
		s++;
	}	
	s--;
	
	while(*t != '\0')
	{
		t++;
	}
	
	t--;
	
	while(len>0)
	{
		if(*t == *s)
		{
			--t;
			--s;
			--len;
		}
		else
		{
			return 0;
		}
	}
	if(len == 0)
	{
		return 1;
	}
		
}

int my_getline(char input[], int lim)
{
	int c, i;
	for(i = 0; i<lim-1 && (c = getchar()) != EOF && c != '\n'; i++)
	{
		input[i] = c;
	}
	
	if(c == '\n')
	{
		input[i] = c;
		++i;
	}
	
	input[i] = '\0';
	
	return i;
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
	printf("%d\n", my_strend(cinput, dinput));
	
	
}
