#include<stdio.h>
#include<string.h>

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

void itoa(int n, char s[], int width)
{
	int i, sign;
	
	if((sign = n) < 0)
	{
		n = -n;
	}
	
	i=0;
	
	do{
		s[i++] = n%10 + '0';
	}while((n/=10)>0);
	
	if(sign < 0)
	{
		s[i++]= '-';
	}
	
	printf("%d\n", i);
	
	while(i<width)
	{
		s[i++] = ' ';
	}
	
	s[i] = '\0';
	
	reverse(s);
}

int main(void)
{
	char sinput[100];
	int n, width;
	
	n = 42425;
	width = 10;
	
	itoa(n, sinput, width);
	
	printf("%s\n", sinput);
}


