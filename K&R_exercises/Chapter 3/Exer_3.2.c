#include<stdio.h>
#include<string.h>

#define MAXLINE    100

void rev_escape(char s[], char t[])
{
	int i,j;
	i=j=0;
	while(t[i]!='\0')
	{
		switch(t[i])
		{
			case '\\':
				++i;
                if(t[i] == 't')
                {
                	s[j] = '\t';
				}
				else if(t[i] == 'n')
				{
					s[j] = '\n';
				}
				break;
			default:
				s[j] = t[i];
				break;
		}
		++i;
		++j;
	}
	
	s[j] = '\0';
	
}

void escape(char s[], char t[])
{
	int i,j;
	i=j=0;
	while(s[i]!='\0')
	{
		switch(s[i])
		{
			case '\t':
				t[j] = '\\';
				++j;
				t[j] = 't';
				break;
			case '\n':
				t[j] = '\\';
				++j;
				t[j] = 'n';
				break;
			default:
				t[j] = s[i];
				break;
		}
		++i;
		++j;
	}
	
	t[j] = '\0';
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
	escape(sinput, dinput);
	printf("the new string is %s\n", dinput);
	rev_escape(sinput, dinput);
	printf("the new string is %s\n", sinput);
}
