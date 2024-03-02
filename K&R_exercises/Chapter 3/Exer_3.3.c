#include<stdio.h>
#define MAXLINE   1000

void expand(char s1[], char s2[])
{
	int i, j, c;
	i=j=0;
	while((c= s1[i++])!='\0')
	{
		if(s1[i]== '-' && s1[i+1]>=c)
		{
			i++;
			while(c<s1[i])
			{
				s2[j++]=c++;
			}
		}
		else
		{
			s2[j++]=c;
		}
		
	}
	s2[j]='\0';
}

int my_getline(char s[], int limit)
{
	int i, c;
	for(i=0;i<limit-1 && (c=getchar()) != EOF && c !='\n'; i++)
	{
		s[i] = c;
	}
	
	if(c == '\n')
	{
		s[i++] = c;
	}
	
	s[i] = '\0';
	return i;
}
int main()
{
	char sinput[MAXLINE];
	char dinput[MAXLINE];
	
	my_getline(sinput, MAXLINE);
	expand(sinput,dinput);
	
	printf("the expanded string is %s", dinput);
}
