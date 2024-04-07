#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXOP    100 
#define NUMBER   '0'
#define MAXVAL   100
#define BUFSIZE  100

char buf[BUFSIZE];
int bufp = 0;
int sp = 0;
double val[MAXVAL];

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)
{
    if(bufp >= BUFSIZE)
    {
        printf("ungetch: too many characters\n");
    }
    else
    {
        buf[bufp++] = c;
    }
}
void push(double f)
{
    if(sp < MAXVAL)
    {
        val[sp++] = f;
        printf("pushed %lf\n", f);
    }
    else
       printf("error: stack full, can't push");
}

double pop(void)
{
    if(sp > 0)
    {
        return val[--sp];
    }
    else{
        printf("error: stack empty\n");
        return 0.0;
    }
}

int getop(char s[])
{
    int i, c;

    while((s[0] = c = getch()) == ' ' || c== '\t');

    s[1] = '\0';

    if(!isdigit(c) && c!= '.' && c!='-')
    {
        return c;
    }

    i=0;
    if(c == '-' || isdigit(c))
    {
        while(isdigit(s[++i] = c = getch()));
    }

    if(c == '.')
    {
        while(isdigit(s[++i] = c= getch()));
    }

    s[i] = '\0';
    if(c!=EOF)
       ungetch(c);

    if(strcmp(s, "-") == 0)
    {
        return '-';
    }
    return NUMBER;
}

int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while((type = getop(s))!=EOF)
    {
        switch(type)
        {
            case NUMBER:
               push(atof(s));
               break;

            case '+':
               push(pop() + pop());
               break;

            case '*':
               push(pop()*pop());
               break;

            case '-':
               op2 = pop();
               push(pop() - op2);
               break;

            case '/':
               op2 = pop();
               if(op2 != 0.0)
               {
                push(pop()/op2);
               }
               else
               {
                 printf("divide by zero\n");
               }
               break;

            case '%':
               op2 = pop();
               if(op2 != 0.0)
               {
                   push(fmod(pop(), op2));
               }
               else
               {
                 printf("divide by zero\n");
               }
               break;
            case '\n':
               printf("\t%.8g\n", pop());
               break;

            default:
               printf("error: unknown commands");
               break;
        }
    }
}