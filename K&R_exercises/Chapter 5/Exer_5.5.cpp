#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>


#define MAXINPUT     1000
#define BUFSIZE       100
#define MAXOP         100
#define NUMBER        '0'

char buf[BUFSIZE];
int bufp = 0;
int sp = 0;
double val[BUFSIZE];

void push(double f)
{
	if(sp < BUFSIZE)
	{
		val[sp++] = f;
	}
	else
	{
		printf("error: stack is full");
	}
}

double pop(void)
{
	if (sp > 0)
	{
		return val[--sp];
	}
	else
	{
		printf("stack is empty\n");
		return 0;
	}
}

int getch(void)
{
	return (bufp>0)? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if(bufp >= BUFSIZE)
	    printf("Ungetch: Too many charcaters\n");
	else
	    buf[bufp++] = c;
}

int my_getline(char * input, int lim)
{
	int c;
	char *temp = input;
	while(--lim >=0 && (c = getchar()) != EOF && c != '\n')
	{
		*input++ = c;
	}
	
	if(c == '\n')
	{
		*input++ = c;
	}
	
	*input = '\0';
	
	return input-temp;
}

int atoi(char *s)
{
	static int n;
	int sign;
	
	for(; isspace(*s); s++)
	;
	
	sign = (*s == '-') ? -1 : 1;
	if(*s == '+' || *s == '-')
	{
		s++;
	}
	for(n = 0; isdigit(*s);s++)
	{
		n = 10*n + (*s - '0');
	}
	return sign*n;
}



void reverse(char *s)
{
	int c;
	char *temp ;
	for(temp = s+ (strlen(s) - 1); s < temp ; s++ , temp--)
	{
		c = *s;
		*s = *temp;
		*temp = c;
	}		
}

void itoa(int n, char *s) {
    int sign;
    char *t = s;

    if ((sign = n) < 0)
        n = -n;

    do {
        *s++ = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0)
        *s++ = '-';
    *s = '\0';
    reverse(t);
}

int getop(char *s)
{
	int c;
	while((*s = c= getch()) == ' ' || c == '\t')
	;
	*(s+1) = '\0';
	
	if(!isdigit(c) && c != '.')
	   return c;
	   
	if(isdigit(c))
	   while(isdigit((*++s) = c = getch()))
	   ;
	   
	if(c == '.')
	   while(isdigit((*++s) = c = getch()))
	   ;
	   
	*s = '\0';
	
	if(c!= EOF)
	  ungetch(c);
	
	return NUMBER;
}

int strindex(char *s, char *t)
{
	char *tempA = s;
	char *tempB, *tempC;
	for(; *s!=0; s++)
	{
		for(tempB = s, tempC= t;*tempC!= '\0' && *tempB == *tempC; tempB++, tempC++)
		{
			;
		}
		if( tempC > t && tempC !='\0')
		{
			return (s - tempA);
		}
	}
	return -1;
}

int main()
{
	char sinput[MAXINPUT], str[MAXINPUT], substr[MAXINPUT];
	int i, type, index=0;
	char s1[100];
	double op2;
	char s[MAXOP];
	
	putchar('s');
	putchar(':');
	
	my_getline(str, MAXINPUT);
	
	putchar('d');
	putchar(':');
	
	my_getline(substr, MAXINPUT);
	
	index = strindex(str, substr);
    printf("the substring is found at index %d\t", index);
    
    printf("enter the character to convert to integer\n: ");
	my_getline(sinput, MAXINPUT);	
	printf("The converted integer is as : %d\n", atoi(sinput));
	

	printf("enter the interger to convert to character\n:");
	scanf("%d", &i);

	itoa(i, s1);
	printf("The converted integer is as : %s\n", s1);
	
	reverse(s1);	
	printf("The reversed string is as : %s\n", s1);
	
	while((type = getop(s)) != EOF)
	{
		switch (type)
		{
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if(op2 != 0.0)
				{
					push(pop() / op2);
				}
				else
				{
					printf("error: zero division");
				}
				break;
			case '\n':
                printf("Result : %.8g\n", pop());
                break;
			default:
				printf("error: unknown command");
				break;						
		}
	}
	
}
