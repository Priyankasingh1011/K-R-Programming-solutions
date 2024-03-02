#include<stdio.h>
#include<string.h>

#define abs(x) ((x) > 0 ? (x) : -(x))
void reverse(char s[])
{
	int i, j, c;
	for(i = 0,j = strlen(s)-1; i<j; i++,j--)
	{
		c= s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
void itoa(int n, char s[])
{
	int i, sign;
	
	sign = n;
	
	i=0;
	do{
		s[i++] = abs(n%10) + '0';
	} while((n/=10)!=0);
	
	if(sign<0)
	{
		s[i++] = '-';
	}
	
	s[i] = '\0';
	
	reverse(s);
}

int main(void)
{
	int number;
	char sinput[100];
	
	number = -2147483648;
	
	itoa(number, sinput);
	printf("%s", sinput);
}
