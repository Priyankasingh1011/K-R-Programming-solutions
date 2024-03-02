#include<stdio.h>
#include<string.h> 
#define MAXLEN   1000

void reverse(char s[])
{
	int i, j, c;
	for(i=0, j = strlen(s)-1; i<j ;i++, j--)
	{
		c = s[i];
	    s[i] = s[j];
	    s[j] = c;
	}
}


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

int main(void)
{
	char sinput[MAXLEN];
	int len;
	while(len = my_getline(sinput, MAXLEN)> 0)
	{
		printf("The input is %s: ", sinput);
		
		reverse(sinput);
		
		printf("The output is %s: ", sinput);
	}
}
