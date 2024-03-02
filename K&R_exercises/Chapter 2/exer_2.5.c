#include<stdio.h>

#define MAXVALUE    100

int any(char s1[], char s2[])
{
	int i, j;
	
	for(i=0; s1[i] != '\0';++i)
	{
		for (j=0;(s1[i] != s2[j]) && s2[j]!='\0'; ++j);		
		
		if(s2[j]!='\0' && s2[j]!='\n')
		   return i;
	}
		
	return -1;
}

int my_getline(char s[], int limit)
{
	int i, c;
	for(i = 0; i< limit-1 && (c = getchar()) != EOF && c != '\n';i++)
	{
		s[i] = c;
	}
	
	if(c == '\n')
	{
		s[i++] = c;
	}
	
	s[i]= '\0';
	return i;
}

int main(void)
{
	char sinput[MAXVALUE];
	char dinput[MAXVALUE];
	
	putchar('s');
	putchar(':');
	
	my_getline(sinput, MAXVALUE);
	
	putchar('d');
	putchar(':');
	
	my_getline(dinput, MAXVALUE);
	
	printf("String2 is found at index %d of String1\n", any(sinput, dinput));
	
}
