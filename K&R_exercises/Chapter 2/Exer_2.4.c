#include<string.h>
#include<stdio.h>

#define MAXLINE     100

void squeeze(char s1[], char s2[])
{
    int i, j, k;
    k=0;
    for(i=0; s1[i]!='\0';++i)
    {
        for(j=0;(s2[j]!='\0' && s1[i]!=s2[j]);++j);    
		if(s2[j] == '\0')
            s1[k++] = s1[i];
        
    }  
    s1[k] = '\0';   
}


int my_getline(char s[], int limit)
{
	int i, c;
	for(i=0; i < limit-1 && (c=getchar()) != EOF && c!= '\n'; i++)
	{
		s[i] = c;
	}
	
	if(c== '\n')
	{
		s[i++] = c;
	}
	
	s[i] = '\0';
	
	return i;
}

int main(void)
{
	char sinput[MAXLINE];
	char dinput[MAXLINE];
	
    putchar('s');
    putchar(':');
	
	my_getline(sinput, MAXLINE);
	
	putchar('d');
    putchar(':');
	
	my_getline(dinput, MAXLINE);

	
	//scanf("%d\n", &c);
	squeeze(sinput, dinput);
	
	printf("%s\n", sinput);
}
