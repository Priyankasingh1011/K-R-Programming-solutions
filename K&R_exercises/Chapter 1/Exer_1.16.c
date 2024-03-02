#include<stdio.h>
#define MAXLEN   1000

int my_getline(char line[], int limit)
{
	int i, j, c;
	for(i=0; i< limit-1 && (c=getchar())!=EOF && c!= '\n' ; i++)
	{
		line[i] = c;
	}
	
	if(c == '\n')
	{
		line[i++] = c;
	}
	
	line[i] = '\0';
	return i;
}

void copy(char src[], char dest[])
{
	int i;
	i=0;
	while((src[i]=dest[i])!='\0')
	    i++;
}

int main(void)
{
	int len, max;
	char line[MAXLEN];
	char longest[MAXLEN];
	
	max=0;
	while((len = my_getline(line, MAXLEN))>0)
	{
		if(len > max)
		{
			max = len;
			copy(longest, line);
		}
	}
	
	if(max > 0)
	{
		printf("The length of the longest line %d\n", max);
		printf("The longest string is: %s", longest);
	}
}
