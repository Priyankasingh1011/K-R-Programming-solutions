#include<stdio.h>

#define MAXLEN   1000
#define TOTAL_CHAR  80

int my_getline(char line[], int n)
{
	int i, c;
	for(i=0;i<n-1 && (c=getchar())!= EOF && c !='\n' ;i++)
	{
		line[i] = c;
	}
	
	if(c == '\0')
	{
		line[i++] = c;
	}
	
	line[i] = '\0';
	return i;
}

int main(void)
{
	char line[MAXLEN] ;
	int len;
	if((len = my_getline(line, MAXLEN)) > TOTAL_CHAR)
	{
		printf("%s\n", line);
	}
	else
	{
		printf("the sentence has lower character than 80\n");
	}
}
